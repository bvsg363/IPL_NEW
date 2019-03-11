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

%start  program
%left   '+' '-' "&&" "||"
%left   '*' '/'

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


%type <integer_value>   INTEGER_NUMBER type
%type <double_value>     DOUBLE_NUMBER
%type <procedure>    procedure_definition
%type <string_value> NAME
%type <ast> assignment_statement expresssion variable constant conditional_expr relational_expr logical_expr if_stmt while_stmt do_while_stmt
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

                |   statement_list assignment_statement
                    {
                        $1->push_back($2);
                        $$ = $1;
                        // common_ast_list->push_back($2);
                    }

                |   statement_list if_stmt
                    {
                        $1->push_back($2);
                        $$ = $1;
                    }

                |   statement_list while_stmt
                    {
                        $1->push_back($2);
                        $$ = $1;
                    }

                |   statement_list do_while_stmt
                    {
                        $1->push_back($2);
                        $$ = $1;
                    }

                ;

assignment_statement    :   variable ASSIGN expresssion ';'
                            {
                                $$ = new Assignment_Ast($1, $3, yylineno);
                                $$->check_ast();
                            }

                        |   variable ASSIGN conditional_expr ';'
                            {
                                $$ = new Assignment_Ast($1, $3, yylineno);
                                $$->check_ast();
                            }
                        ;

expresssion :   expresssion '*' expresssion
                {
                    $$ = new Mult_Ast($1, $3, yylineno);
                    $$->set_data_type($1->get_data_type());
                    $$->check_ast();
                }

            |   expresssion '/' expresssion
                {
                    $$ = new Divide_Ast($1, $3, yylineno);
                    $$->set_data_type($1->get_data_type());
                    $$->check_ast();
                }

            |   expresssion '+' expresssion
                {
                    $$ = new Plus_Ast($1, $3, yylineno);
                    $$->set_data_type($1->get_data_type());
                    $$->check_ast();
                }

            |   expresssion '-' expresssion
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

            |   '(' expresssion ')'
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

            |   '-' '(' expresssion ')'
                {
                    $$ = new UMinus_Ast($3, NULL, yylineno);
                    $$->set_data_type($3->get_data_type());
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
                        yyerror("cs316: Error :Variable has not been declared");
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
conditional_expr    :   logical_expr '?' expresssion ':' expresssion
                        {
                            $$ = new Conditional_Expression_Ast($1, $3, $5, yylineno);
                        }



if_stmt     :   IF '(' logical_expr ')'
                '{'
                    statement_list
                '}'
                {
                    Sequence_Ast * seq_ast_then = new Sequence_Ast(yylineno);
                    for (std::list<Ast*>::iterator it = $6->begin(); it != $6->end(); ++it)
                    {
                        seq_ast_then->ast_push_back(*it);
                    }
                    $$ = new Selection_Statement_Ast($3, seq_ast_then, NULL, yylineno);
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
                ;

do_while_stmt       :   DO
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
                    ;


logical_expr      :   logical_expr AND logical_expr
                        {
                            $$ = new Logical_Expr_Ast($1, _logical_and, $3, yylineno);
                        }

                    |   logical_expr OR logical_expr
                        {
                            $$ = new Logical_Expr_Ast($1, _logical_or, $3, yylineno);
                        }

                    |   NOT logical_expr
                        {
                            $$ = new Logical_Expr_Ast($2, _logical_not, NULL, yylineno);
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





relational_expr     :   expresssion LESS_THAN expresssion
                        {
                            $$ = new Relational_Expr_Ast($1, less_than, $3, yylineno);
                            // $$->set_data_type($1->get_data_type());
                            $$->check_ast();
                        }

                    |   expresssion LESS_THAN_EQUAL expresssion
                        {
                            $$ = new Relational_Expr_Ast($1, less_equalto, $3, yylineno);
                            // $$->set_data_type($1->get_data_type());
                            $$->check_ast();
                        }

                    |   expresssion GREATER_THAN expresssion
                        {
                            $$ = new Relational_Expr_Ast($1, greater_than, $3, yylineno);
                            // $$->set_data_type($1->get_data_type());
                            $$->check_ast();                            
                        }

                    |   expresssion GREATER_THAN_EQUAL expresssion
                        {
                            $$ = new Relational_Expr_Ast($1, greater_equalto, $3, yylineno);
                            // $$->set_data_type($1->get_data_type());
                            $$->check_ast();                            
                        }

                    |   expresssion EQUAL expresssion
                        {
                            $$ = new Relational_Expr_Ast($1, equalto, $3, yylineno);
                            // $$->set_data_type($1->get_data_type());
                            $$->check_ast();                            
                        }

                    |   expresssion NOT_EQUAL expresssion
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