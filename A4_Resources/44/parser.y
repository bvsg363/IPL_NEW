%{
#include <stdio.h>
#include <list>
extern "C" void yyerror(char *s);
extern int yylex(void);
extern int yylineno;
Symbol_Table *local_symbol_table = new Symbol_Table();
Symbol_Table *global_symbol_table = new Symbol_Table();

// list<Ast*> *common_ast_list = new list<Ast*>;

int glob_scop = 1;

Data_Type sample_data_type;

%}

%union  YYSTYPE
{   int integer_value;
    double double_value;
    std::string * string_value;
    list<Ast *> * ast_list;
    Ast * ast;
    Symbol_Table * symbol_table;
    Symbol_Table_Entry * symbol_entry;
    Basic_Block * basic_block;
    Procedure * procedure;
};

%token  INTEGER_NUMBER BBNUM DOUBLE_NUMBER NAME RETURN INTEGER FLOAT ASSIGN VOID UMINUS
%token  WHILE GREATER_THAN NOT_EQUAL LESS_THAN LESS_THAN_EQUAL EQUAL GREATER_THAN_EQUAL IF ELSE DO AND OR NOT

%start  program
%left   '?' ':'
%left   OR
%left   AND
%left   EQUAL NOT_EQUAL
%left   LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL
%left   '+' '-'
%left   '*' '/'
%right  NOT


%type <integer_value>   INTEGER_NUMBER type
%type <double_value>     DOUBLE_NUMBER
%type <procedure>    procedure_definition
%type <string_value> NAME
%type <ast> assignment_statement expression variable constant conditional_expr relational_expr logical_expr if_stmt while_stmt do_while_stmt single_stmt
%type <symbol_table> variable_list variable_declaration variable_declaration_list global_variable_declaration_list
%type <ast_list> statement_list

%%
program     :   global_variable_declaration_list
                procedure_definition
                {
                    program_object.set_procedure($2, yylineno);
                    program_object.set_global_table(*global_symbol_table);
                }
            ;

procedure_definition    :   VOID NAME '(' ')'
                            '{'
                                variable_declaration_list
                                statement_list
                            '}'
                            {
                                $6->set_table_scope(local);
                                $$ = new Procedure(void_data_type, *($2), yylineno);
                                $$->set_local_list(*local_symbol_table);
                                $$->set_ast_list(*($7));
                            }
                        ;

global_variable_declaration_list :  variable_declaration_list
                                    {
                                        glob_scop = 0;
                                        $1->set_table_scope(global);
                                        $$ = $1;
                                    }

variable_declaration_list   :   variable_declaration_list
                                variable_declaration
                                {
                                    $1->append_list(*($2), yylineno);
                                    $$ = $1;
                                }

                            |   /* empty */
                                {
                                    $$ = new Symbol_Table();
                                }
                            ;

variable_declaration    :   type variable_list ';'
                            {
                                $$ = $2;
                            }
                        ;

type    :   INTEGER
            {
                sample_data_type = int_data_type;
            }

        |   FLOAT
            {
                sample_data_type = double_data_type;
            }
        ;

variable_list   :   NAME
                    {
                        $$ = new Symbol_Table();
                        Symbol_Table_Entry * sym = new Symbol_Table_Entry(*($1), sample_data_type, yylineno);
                        $$->push_symbol(sym);
                        if(glob_scop == 1){
                            global_symbol_table->push_symbol(sym);
                        }
                        else{
                            local_symbol_table->push_symbol(sym);
                        }
                    }

                |   variable_list ',' NAME
                    {
                        Symbol_Table_Entry * sym = new Symbol_Table_Entry(*($3), sample_data_type, yylineno);
                        $1->push_symbol(sym);
                        $$ = $1;
                        if(glob_scop == 1){
                            global_symbol_table->push_symbol(sym);
                        }
                        else{
                            local_symbol_table->push_symbol(sym);
                        }
                    }
                ;

statement_list  :   /* empty */
                    {
                        $$ = new list<Ast*>;
                    }

                |   statement_list single_stmt
                    {
                        $1->push_back($2);
                        $$ = $1;
                        // common_ast_list->push_back($2);
                    }
                ;

single_stmt     :   assignment_statement
                    {
                        $$ = $1;
                    }
                |   if_stmt
                    {
                        $$ = $1;
                    }
                |   while_stmt
                    {
                        $$ = $1;
                    }
                |   do_while_stmt
                    {
                        $$ = $1;
                    }
                ;

assignment_statement    :   variable ASSIGN expression ';'
                            {
                                $$ = new Assignment_Ast($1, $3, yylineno);
                                $$->check_ast();
                            }
                        ;

// expression1    :   expression
//                     {
//                         $$ = $1;
//                     }
//                 |   conditional_expr
//                     {
//                         $$ = $1;
//                     }
//                 ;

expression :   expression '*' expression
                {
                    $$ = new Mult_Ast($1, $3, yylineno);
                    $$->set_data_type($1->get_data_type());
                    $$->check_ast();
                }

            |   expression '/' expression
                {
                    $$ = new Divide_Ast($1, $3, yylineno);
                    $$->set_data_type($1->get_data_type());
                    $$->check_ast();
                }

            |   expression '+' expression
                {
                    $$ = new Plus_Ast($1, $3, yylineno);
                    $$->set_data_type($1->get_data_type());
                    $$->check_ast();
                }

            |   expression '-' expression
                {
                    $$ = new Minus_Ast($1, $3, yylineno);
                    $$->set_data_type($1->get_data_type());
                    $$->check_ast();
                }

            |   variable
                {
                    $$ = $1;
                    $$->set_data_type($1->get_data_type());
                }

            |   constant
                {
                    $$ = $1;
                    $$->set_data_type($1->get_data_type());
                }

            |   '(' expression ')'
                {
                    $$ = $2;
                    $$->set_data_type($2->get_data_type());
                }

            |   '-' variable
                {
                    $$ = new UMinus_Ast($2, NULL, yylineno);
                    $$->set_data_type($2->get_data_type());
                }

            |   '-' constant
                {
                    $$ = new UMinus_Ast($2, NULL, yylineno);
                    $$->set_data_type($2->get_data_type());
                }

            |   '-' '(' expression ')'
                {
                    $$ = new UMinus_Ast($3, NULL, yylineno);
                    $$->set_data_type($3->get_data_type());
                }

            |   logical_expr '?' expression ':' expression
                {
                    $$ = new Conditional_Expression_Ast($1, $3, $5, yylineno);
                    $$->set_data_type($3->get_data_type());
                    $$->check_ast();
                }

            ;

variable    :   NAME
                {
                    if(local_symbol_table->variable_in_symbol_list_check(*($1))){
                        $$ = new Name_Ast(*($1), local_symbol_table->get_symbol_table_entry(*($1)), yylineno);
                    }
                    else if(global_symbol_table->variable_in_symbol_list_check(*($1))){
                        $$ = new Name_Ast(*($1), global_symbol_table->get_symbol_table_entry(*($1)), yylineno);
                    }
                    else{
                        yyerror("cs316: Error : Variable has not been declared");
                        exit(0);
                    }
                }
            ;

constant    :   INTEGER_NUMBER
                {
                    $$ = new Number_Ast<int> ($1, int_data_type, yylineno);
                }

            |   DOUBLE_NUMBER
                {
                    $$ = new Number_Ast<double> ($1, double_data_type, yylineno);
                }
            ;


/* (a>b)&&(b<c) ? d : e */
// conditional_expr    :   logical_expr '?' expression ':' expression
//                         {
//                             $$ = new Conditional_Expression_Ast($1, $3, $5, yylineno);
//                             $$->set_data_type($3->get_data_type());
//                             $$->check_ast();
//                         }
//                     ;



if_stmt     :   IF '(' logical_expr ')'
                '{'
                    statement_list
                '}'
                {
                    if ($6->empty())
                    {
                        yyerror("cs316: Error : Block of statements cannot be empty (Invariant at line 404, file parser.y).");
                        exit(0);
                    }

                    Sequence_Ast * seq_ast_then = new Sequence_Ast(yylineno);
                    for (std::list<Ast*>::iterator it = $6->begin(); it != $6->end(); ++it)
                    {
                        seq_ast_then->ast_push_back(*it);
                    }
                    $$ = new Selection_Statement_Ast($3, seq_ast_then, NULL, yylineno);
                }

            |   IF '(' logical_expr ')'
                    single_stmt
                {
                    $$ = new Selection_Statement_Ast($3, $5, NULL, yylineno);
                }

            |   IF '(' logical_expr ')'
                '{'
                    statement_list
                '}'
                ELSE
                '{'
                    statement_list
                '}'
                {
                    if ($6->empty() || $10->empty())
                    {
                        yyerror("cs316: Error : Block of statements cannot be empty (Invariant at line 404, file parser.y).");
                        exit(0);
                    }

                    Sequence_Ast * seq_ast_then = new Sequence_Ast(yylineno);
                    for (std::list<Ast*>::iterator it = $6->begin(); it != $6->end(); ++it){
                        seq_ast_then->ast_push_back(*it);
                    }

                    Sequence_Ast * seq_ast_else = new Sequence_Ast(yylineno);
                    for (std::list<Ast*>::iterator it = $10->begin(); it != $10->end(); ++it){
                        seq_ast_else->ast_push_back(*it);
                    }

                    $$ = new Selection_Statement_Ast($3, seq_ast_then, seq_ast_else, yylineno);
                }

            |   IF '(' logical_expr ')'
                    single_stmt
                ELSE
                '{'
                    statement_list
                '}'
                {
                    if ($8->empty())
                    {
                        yyerror("cs316: Error : Block of statements cannot be empty (Invariant at line 404, file parser.y).");
                        exit(0);
                    }

                    Sequence_Ast * seq_ast_else = new Sequence_Ast(yylineno);
                    for (std::list<Ast*>::iterator it = $8->begin(); it != $8->end(); ++it){
                        seq_ast_else->ast_push_back(*it);
                    }

                    $$ = new Selection_Statement_Ast($3, $5, seq_ast_else, yylineno);
                }

            |   IF '(' logical_expr ')'
                '{'
                    statement_list
                '}'
                ELSE
                    single_stmt
                {
                    if ($6->empty())
                    {
                        yyerror("cs316: Error : Block of statements cannot be empty (Invariant at line 404, file parser.y).");
                        exit(0);
                    }

                    Sequence_Ast * seq_ast_then = new Sequence_Ast(yylineno);
                    for (std::list<Ast*>::iterator it = $6->begin(); it != $6->end(); ++it){
                        seq_ast_then->ast_push_back(*it);
                    }

                    $$ = new Selection_Statement_Ast($3, seq_ast_then, $9, yylineno);
                }

            |   IF '(' logical_expr ')'
                    single_stmt
                ELSE
                    single_stmt
                {
                    $$ = new Selection_Statement_Ast($3, $5, $7, yylineno);
                }
            ;

while_stmt      :   WHILE '(' logical_expr ')'
                    '{'
                        statement_list
                    '}'
                    {
                        if($6->empty())
                        {
                            yyerror("cs316: Error : Block of statements cannot be empty (Invariant at line 404, file parser.y).");
                            exit(0);
                        }
                        Sequence_Ast * seq_ast_body = new Sequence_Ast(yylineno);
                        for (std::list<Ast*>::iterator it = $6->begin(); it != $6->end(); ++it)
                        {
                            seq_ast_body->ast_push_back(*it);
                        }

                        $$ = new Iteration_Statement_Ast($3, seq_ast_body, yylineno, false);
                    }

                |   WHILE '(' logical_expr ')'
                        single_stmt
                    {
                        $$ = new Iteration_Statement_Ast($3, $5, yylineno, false);
                    }
                ;

/* do{}while(){}; */
do_while_stmt   :   DO
                    '{'
                        statement_list
                    '}'
                    WHILE '(' logical_expr ')' ';'
                    {
                        if ($3->empty())
                        {
                            yyerror("cs316: Error : Block of statements cannot be empty (Invariant at line 404, file parser.y).");
                            exit(0);
                        }
                        Sequence_Ast * seq_ast_body = new Sequence_Ast(yylineno);
                        for (std::list<Ast*>::iterator it = $3->begin(); it != $3->end(); ++it)
                        {
                            seq_ast_body->ast_push_back(*it);
                        }

                        $$ = new Iteration_Statement_Ast($7, seq_ast_body, yylineno, true);
                    }

                |   DO
                        single_stmt
                    WHILE '(' logical_expr ')' ';'
                    {
                        $$ = new Iteration_Statement_Ast($5, $2, yylineno, true);
                    }
                ;


logical_expr    :   logical_expr AND logical_expr
                    {
                        $$ = new Logical_Expr_Ast($1, _logical_and, $3, yylineno);
                    }

                |   logical_expr OR logical_expr
                    {
                        $$ = new Logical_Expr_Ast($1, _logical_or, $3, yylineno);
                    }

                |   NOT logical_expr
                    {
                        $$ = new Logical_Expr_Ast(NULL, _logical_not, $2, yylineno);
                    }

                |   '(' logical_expr ')'
                    {
                        $$ = $2;
                    }

                |   relational_expr
                    {
                        $$ = $1;
                    }
                ;

relational_expr     :   expression LESS_THAN expression
                        {
                            $$ = new Relational_Expr_Ast($1, less_than, $3, yylineno);
                            // $$->set_data_type($1->get_data_type());
                            $$->check_ast();
                        }

                    |   expression LESS_THAN_EQUAL expression
                        {
                            $$ = new Relational_Expr_Ast($1, less_equalto, $3, yylineno);
                            // $$->set_data_type($1->get_data_type());
                            $$->check_ast();
                        }

                    |   expression GREATER_THAN expression
                        {
                            $$ = new Relational_Expr_Ast($1, greater_than, $3, yylineno);
                            // $$->set_data_type($1->get_data_type());
                            $$->check_ast();                            
                        }

                    |   expression GREATER_THAN_EQUAL expression
                        {
                            $$ = new Relational_Expr_Ast($1, greater_equalto, $3, yylineno);
                            // $$->set_data_type($1->get_data_type());
                            $$->check_ast();                            
                        }

                    |   expression EQUAL expression
                        {
                            $$ = new Relational_Expr_Ast($1, equalto, $3, yylineno);
                            // $$->set_data_type($1->get_data_type());
                            $$->check_ast();                            
                        }

                    |   expression NOT_EQUAL expression
                        {
                            $$ = new Relational_Expr_Ast($1, not_equalto, $3, yylineno);
                            // $$->set_data_type($1->get_data_type());
                            $$->check_ast();                            
                        }

                    |   '(' relational_expr ')'
                        {
                            $$ = $2;
                            // $$->set_data_type($2->get_data_type());
                        }
                    ;