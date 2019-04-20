%{
#include <stdio.h>
#include <list>
extern "C" void yyerror(char *s);
extern int yylex(void);
extern int yylineno;
Symbol_Table *local_symbol_table = new Symbol_Table();
Symbol_Table *global_symbol_table = new Symbol_Table();

int glob_scop = 1;
string present_procedure_name;
Data_Type present_procedure_return_type;

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
    list<Procedure*> * procedure_list;
    Data_Type data_type;
};

%token  INTEGER_NUMBER BBNUM DOUBLE_NUMBER NAME RETURN INTEGER FLOAT ASSIGN VOID UMINUS
%token  WHILE GREATER_THAN NOT_EQUAL LESS_THAN LESS_THAN_EQUAL EQUAL GREATER_THAN_EQUAL IF ELSE DO AND OR NOT PRINT

%start  program
%left   '?' ':'
%left   OR
%left   AND
%left   EQUAL NOT_EQUAL
%left   LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL
%left   '+' '-'
%left   '*' '/'
%right  NOT

%right "then" ELSE


%type <integer_value>   INTEGER_NUMBER
%type <double_value>     DOUBLE_NUMBER
%type <string_value> NAME
%type <ast> assignment_statement expression variable constant relational_expr logical_expr if_stmt while_stmt do_while_stmt single_stmt sequence_list print_stmt
%type <ast> return_stmt function_call
%type <symbol_table> variable_list variable_declaration variable_declaration_list func_def_decl_args_list type_var_list type_list
%type <ast_list> statement_list func_call_args_list func_call_args_list1
%type <data_type> return_type

%%

program     :   total_code
                {
                    program_object.set_global_table(*global_symbol_table);
                    if(!program_object.is_procedure_exists("main") || (program_object.get_procedure_prototype("main")->get_return_type() != void_data_type)){
                        cerr << "cs316: Error : Line: " <<  yylineno << ": Main should be defined and it's type should be void\n";
                        exit(0);
                    }
                    // cout << "exit\n";
                }

total_code  :   variable_declaration total_code  /* No Actions */

            |   function_declaration total_code /* No Actions */

            |   function_definition_list /* No Actions */
            ;

function_definition_list    :   function_definition_list   /* No Actions */
                                function_definition

                            |   function_definition /* No Actions */
                            ;

function_definition    :   return_type NAME '(' func_def_decl_args_list ')'
                            '{'
                            {
                                if(*($2) != "main")
                                    *($2) = *($2) + "_";
                                glob_scop = 0;
                                present_procedure_name = *($2);
                                present_procedure_return_type = $1;

                            }
                                variable_declaration_list
                                statement_list
                            '}'
                            {
                                Procedure* proc;

                                if(program_object.is_procedure_exists(*($2))){
                                    proc = program_object.get_procedure_prototype(*($2));
                                    if(proc->get_return_type() != $1){
                                        cerr << "cs316: Error : Line: " <<  yylineno << ": return type in declaration and definition not matching\n";
                                        exit(0);
                                    }
                                    proc->set_local_list(*local_symbol_table);
                                    proc->set_ast_list(*($9));
                                    proc->set_formal_param_list(*($4));
                                }
                                else{
                                    proc = new Procedure($1, *($2), yylineno);
                                    proc->set_local_list(*local_symbol_table);
                                    proc->set_ast_list(*($9));
                                    proc->set_formal_param_list(*($4));
                                    program_object.set_proc_to_map(*($2), proc);
                                }

                                local_symbol_table = new Symbol_Table();
                            }
                        ;


function_declaration    :   return_type NAME '(' func_def_decl_args_list ')' ';'
                            {
                                if(*($2) != "main")
                                    *($2) = *($2) + "_";

                                Procedure* proc = new Procedure($1, *($2), yylineno);
                                proc->set_local_list(*local_symbol_table);
                                proc->set_formal_param_list(*($4));
                                program_object.set_proc_to_map(*($2), proc);
                            }

                        |   return_type NAME '(' type_list ')' ';'
                            {
                                if(*($2) != "main")
                                    *($2) = *($2) + "_";

                                Procedure* proc = new Procedure($1, *($2), yylineno);
                                proc->set_local_list(*local_symbol_table);
                                proc->set_formal_param_list(*($4));
                                program_object.set_proc_to_map(*($2), proc);
                            }
                        ;

func_def_decl_args_list  :   /* empty */
                    {
                        $$ = new Symbol_Table();
                    }

                |   type_var_list
                    {
                        $$ = $1;
                    }
                ;
                

function_call   :   NAME '(' func_call_args_list ')' ';'
                    {
                        if(*($1) != "main")
                            *($1)= *($1) + "_";
                        Call_Ast * call_ast = new Call_Ast(*($1), yylineno);
                        call_ast->set_actual_param_list(*($3));
                        call_ast->check_actual_formal_param(program_object.get_procedure_prototype(*($1))->get_formal_param_list());
                        $$ = call_ast;
                    }
                ;

func_call_args_list :   func_call_args_list1
                        {
                            $$ = $1;                            
                        }

                    |   /* empty */
                        {
                            $$ = new list<Ast*>;
                        }
                    ;

func_call_args_list1    :   expression ',' func_call_args_list1
                            {
                                $3->push_back($1);
                                $$ = $3;                                
                            }

                        |   expression
                            {
                                $$ = new list<Ast*>;
                                $$->push_back($1);
                            }
                        ;


type_var_list   :   type_var_list ',' return_type NAME
                    {
                        *($4) = *($4) + "_";
                        if($3 == void_data_type){
                            cerr << "cs316: Error : Line: " <<  yylineno << ": Argument variable cannot be void data type\n";
                            exit(0);
                        }

                        if($1->variable_in_symbol_list_check(*($4))){
                            cerr << "cs316: Error : Line: " <<  yylineno << ": Variable is declared twice\n";                            
                            exit(0);
                        }

                        Symbol_Table_Entry * sym = new Symbol_Table_Entry(*($4), $3, yylineno);
                        $1->push_symbol(sym);
                        $$ = $1;
                    }

                |   return_type NAME
                    {
                        *($2) = *($2) + "_";
                        if($1 == void_data_type){
                            cerr << "cs316: Error : Line: " <<  yylineno << ": Argument variable cannot be void data type\n";                            
                            exit(0);
                        }

                        $$ = new Symbol_Table();
                        Symbol_Table_Entry * sym = new Symbol_Table_Entry(*($2), $1, yylineno);
                        $$->push_symbol(sym);
                    }

                ;

type_list   :   type_list ',' return_type
                {
                    if($3 == void_data_type){
                        cerr << "cs316: Error : Line: " <<  yylineno << ": Argument cannot be void data type\n";
                        exit(0);
                    }
                    
                    string dummy_string = "dummy";
                    Symbol_Table_Entry * sym = new Symbol_Table_Entry(dummy_string, $3, yylineno);
                    $1->push_symbol(sym);
                    $$ = $1;
                }

            |   return_type
                {
                    if($1 == void_data_type){
                        cerr << "cs316: Error : Line: " <<  yylineno << ": Argument cannot be void data type\n";
                        exit(0);
                    }

                    $$ = new Symbol_Table();
                    string dummy_string = "dummy";
                    Symbol_Table_Entry * sym = new Symbol_Table_Entry(dummy_string, $1, yylineno);
                    $$->push_symbol(sym);
                }
            
            ;

return_type     :   INTEGER
                    {
                        $$ = int_data_type;
                        sample_data_type = int_data_type;
                    }
            
                |   FLOAT
                    {
                        $$ = double_data_type;
                        sample_data_type = double_data_type;
                    }

                |   VOID
                    {
                        $$ = void_data_type;
                        sample_data_type = void_data_type;
                    }
            ;

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

variable_declaration    :   return_type variable_list ';'
                            {
                                $$ = $2;
                            }
                        ;

variable_list   :   NAME
                    {
                        $$ = new Symbol_Table();
                        string s = *($1)+"_";
                        Symbol_Table_Entry * sym = new Symbol_Table_Entry(s, sample_data_type, yylineno);
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
                        string s = *($3) + "_";
                        Symbol_Table_Entry * sym = new Symbol_Table_Entry(s, sample_data_type, yylineno);
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

                |   sequence_list
                    {
                        $$ = $1;
                    }

                |   print_stmt
                    {
                        $$ = $1;
                    }

                |   function_call
                    {
                        $$ = $1;
                    }

                |   return_stmt
                    {
                        $$ = $1;
                    }
                ;

assignment_statement    :   variable ASSIGN expression ';'
                            {
                                $$ = new Assignment_Ast($1, $3, yylineno);
                                $$->check_ast();
                            }

                        |   variable ASSIGN function_call
                            {
                                $$ = new Assignment_Ast($1, $3, yylineno);
                                $$->check_ast();
                            }
                        ;

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


            |   '-' expression %prec '*'
                {
                    $$ = new UMinus_Ast($2, NULL, yylineno);
                    $$->set_data_type($2->get_data_type());
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
                    string s = *($1) + "_";
                    if(local_symbol_table->variable_in_symbol_list_check(s)){
                        $$ = new Name_Ast(s, local_symbol_table->get_symbol_table_entry(s), yylineno);
                    }
                    else if(global_symbol_table->variable_in_symbol_list_check(s)){
                        $$ = new Name_Ast(s, global_symbol_table->get_symbol_table_entry(s), yylineno);
                    }
                    else{
                        cerr << "cs316: Error : Line: " <<  yylineno << ": Variable has not been declared\n";
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

if_stmt     :   IF '(' logical_expr ')'
                    single_stmt %prec "then"
                {
                    $$ = new Selection_Statement_Ast($3, $5, NULL, yylineno);
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
                        single_stmt
                    {
                        $$ = new Iteration_Statement_Ast($3, $5, yylineno, false);
                    }
                ;

do_while_stmt   :   DO
                        single_stmt
                    WHILE '(' logical_expr ')' ';'
                    {
                        $$ = new Iteration_Statement_Ast($5, $2, yylineno, true);
                    }
                ;

print_stmt  :   PRINT variable ';'
                {
                    $$ = new Print_Ast($2, yylineno);
                }
                
            ;

logical_expr    :   logical_expr AND logical_expr
                    {
                        $$ = new Logical_Expr_Ast($1, _logical_and, $3, yylineno);
                        $$->check_ast();
                    }

                |   logical_expr OR logical_expr
                    {
                        $$ = new Logical_Expr_Ast($1, _logical_or, $3, yylineno);
                        $$->check_ast();
                    }

                |   NOT logical_expr
                    {
                        $$ = new Logical_Expr_Ast(NULL, _logical_not, $2, yylineno);
                        $$->check_ast();
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
                            $$->check_ast();
                        }

                    |   expression LESS_THAN_EQUAL expression
                        {
                            $$ = new Relational_Expr_Ast($1, less_equalto, $3, yylineno);
                            $$->check_ast();
                        }

                    |   expression GREATER_THAN expression
                        {
                            $$ = new Relational_Expr_Ast($1, greater_than, $3, yylineno);
                            $$->check_ast();                            
                        }

                    |   expression GREATER_THAN_EQUAL expression
                        {
                            $$ = new Relational_Expr_Ast($1, greater_equalto, $3, yylineno);
                            $$->check_ast();                            
                        }

                    |   expression EQUAL expression
                        {
                            $$ = new Relational_Expr_Ast($1, equalto, $3, yylineno);
                            $$->check_ast();
                        }

                    |   expression NOT_EQUAL expression
                        {
                            $$ = new Relational_Expr_Ast($1, not_equalto, $3, yylineno);
                            $$->check_ast();
                        }
                    ;

sequence_list   :   '{'
                        statement_list
                    '}'
                    {
                        if ($2->empty())
                        {
                            cerr << "cs316: Error : Line: " <<  yylineno << ": Block of statements cannot be empty (Invariant at line 404, file parser.y).\n";
                            exit(0);
                        }
                        Sequence_Ast * seq_ast_body = new Sequence_Ast(yylineno);
                        for (std::list<Ast*>::iterator it = $2->begin(); it != $2->end(); ++it)
                        {
                            seq_ast_body->ast_push_back(*it);
                        }

                        $$ = seq_ast_body;
                    }

return_stmt :   RETURN expression ';'
                {
                    if(present_procedure_return_type != $2->get_data_type()){
                        cerr << "cs316: Error : Line: " <<  yylineno << ": Return type not matching\n";
                        exit(0);
                    }
                    $$ = new Return_Ast($2, present_procedure_name, yylineno); //TODO: check 2nd argument - procedure name
                }

            |   RETURN ';'
                {
                    if(present_procedure_return_type != void_data_type){
                        cerr << "cs316: Error : Line: " <<  yylineno << ": Return type not matching\n";
                        exit(0);
                    }
                    $$ = new Return_Ast(NULL, present_procedure_name, yylineno);
                }

            ;