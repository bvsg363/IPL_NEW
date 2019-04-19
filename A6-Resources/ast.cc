#include "ast.hh"
#include <stdlib.h>
#include <list>
#include "symbol-table.hh"

using namespace std;

template class Number_Ast<double>;
template class Number_Ast<int>;

Ast::Ast() {}
Ast::~Ast() {}

Data_Type Ast::get_data_type()
{
    return node_data_type;
}

void Ast::set_data_type(Data_Type dt)
{
    node_data_type = dt;
}

bool Ast::is_value_zero()
{
}

bool Ast::check_ast()
{
}

Symbol_Table_Entry &Ast::get_symbol_entry() {}

void Ast::print(ostream &file_buffer)
{
}

// Assignment Ast

Assignment_Ast::Assignment_Ast(Ast *temp_lhs, Ast *temp_rhs, int line)
{
    lhs = temp_lhs;
    rhs = temp_rhs;
    lineno = line;
    ast_num_child = binary_arity;
}
Assignment_Ast::~Assignment_Ast() {}

bool Assignment_Ast::check_ast()
{
    if (lhs->get_data_type() == rhs->get_data_type())
    {
        return 1;
    }

    cerr << "cs316: Error: Line: " << lineno << ": Assignment statement data type not compatible\n";
    exit(0);
}

void Assignment_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n"
                << AST_SPACE << "Asgn:\n"
                << AST_NODE_SPACE << "LHS (";
    lhs->print(file_buffer);
    file_buffer << ")";
    file_buffer << "\n"
                << AST_NODE_SPACE << "RHS (";
    rhs->print(file_buffer);
    file_buffer << ")";
}

// Name Ast

Name_Ast::Name_Ast(string &name, Symbol_Table_Entry &var_entry, int line)
{
    // printf("entered name ast constructor\n");
    variable_symbol_entry = &var_entry;
    lineno = line;
    ast_num_child = zero_arity;
    // printf("entered name ast constructor2\n");

    node_data_type = var_entry.get_data_type();
    // printf("entered name ast constructor3\n");
}
Name_Ast::~Name_Ast() {}

Data_Type Name_Ast::get_data_type()
{
    return node_data_type;
}
Symbol_Table_Entry &Name_Ast::get_symbol_entry()
{
    return *variable_symbol_entry;
}
void Name_Ast::set_data_type(Data_Type dt)
{
    node_data_type = dt;
}

void Name_Ast::print(ostream &file_buffer)
{
    file_buffer << "Name : " << variable_symbol_entry->get_variable_name();
}

// Number Ast
template <class T>
Number_Ast<T>::Number_Ast(T number, Data_Type constant_data_type, int line)
{
    // printf("number ast constructor\n");
    constant = number;
    node_data_type = constant_data_type;
    lineno = line;
    ast_num_child = zero_arity;
}
template <class T>
Number_Ast<T>::~Number_Ast() {}

template <class T>
Data_Type Number_Ast<T>::get_data_type()
{
    return node_data_type;
}
template <class T>
void Number_Ast<T>::set_data_type(Data_Type dt)
{
    node_data_type = dt;
}
template <class T>
bool Number_Ast<T>::is_value_zero() {}

template <class T>
void Number_Ast<T>::print(ostream &file_buffer)
{
    file_buffer << "Num : " << constant;
}

// Arithmetic Expr Ast

Data_Type Arithmetic_Expr_Ast::get_data_type()
{
    return node_data_type;
}
void Arithmetic_Expr_Ast::set_data_type(Data_Type dt)
{
    node_data_type = dt;
}
bool Arithmetic_Expr_Ast::check_ast()
{
    if (ast_num_child == 2)
    {
        if (lhs->get_data_type() == rhs->get_data_type())
        {
            return 1;
        }
        else
        {
            cerr << "cs316: Error: Line: " << lineno << ": Arithmetic statement data type not compatible\n";
            exit(0);
        }
    }
    else
        return 1;
}

void Arithmetic_Expr_Ast::print(ostream &file_buffer)
{
}

// Plus Ast

Plus_Ast::Plus_Ast(Ast *l, Ast *r, int line)
{
    lhs = l;
    rhs = r;
    ast_num_child = binary_arity;
    lineno = line;
}

void Plus_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n"
                << AST_NODE_SPACE << "Arith: PLUS\n"
                << AST_SUB_NODE_SPACE << "LHS (";
    lhs->print(file_buffer);
    file_buffer << ")";
    file_buffer << "\n"
                << AST_SUB_NODE_SPACE << "RHS (";
    rhs->print(file_buffer);
    file_buffer << ")";
}

// Minus Ast

Minus_Ast::Minus_Ast(Ast *l, Ast *r, int line)
{
    lhs = l;
    rhs = r;
    ast_num_child = binary_arity;
    lineno = line;
}

void Minus_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n"
                << AST_NODE_SPACE << "Arith: MINUS\n"
                << AST_SUB_NODE_SPACE << "LHS (";
    lhs->print(file_buffer);
    file_buffer << ")";
    file_buffer << "\n"
                << AST_SUB_NODE_SPACE << "RHS (";
    rhs->print(file_buffer);
    file_buffer << ")";
}

// Divide Ast

Divide_Ast::Divide_Ast(Ast *l, Ast *r, int line)
{
    lhs = l;
    rhs = r;
    ast_num_child = binary_arity;
    lineno = line;
}

void Divide_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n"
                << AST_NODE_SPACE << "Arith: DIV\n"
                << AST_SUB_NODE_SPACE << "LHS (";
    lhs->print(file_buffer);
    file_buffer << ")";
    file_buffer << "\n"
                << AST_SUB_NODE_SPACE << "RHS (";
    rhs->print(file_buffer);
    file_buffer << ")";
}

// Mult Ast

Mult_Ast::Mult_Ast(Ast *l, Ast *r, int line)
{
    lhs = l;
    rhs = r;
    ast_num_child = binary_arity;
    lineno = line;
}

void Mult_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n"
                << AST_NODE_SPACE << "Arith: MULT\n"
                << AST_SUB_NODE_SPACE << "LHS (";
    lhs->print(file_buffer);
    file_buffer << ")";
    file_buffer << "\n"
                << AST_SUB_NODE_SPACE << "RHS (";
    rhs->print(file_buffer);
    file_buffer << ")";
}

// UMinus Ast

UMinus_Ast::UMinus_Ast(Ast *l, Ast *r, int line)
{
    lhs = l;
    rhs = r;
    ast_num_child = unary_arity;
    lineno = line;
}

void UMinus_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n"
                << AST_NODE_SPACE << "Arith: UMINUS\n"
                << AST_SUB_NODE_SPACE << "LHS (";
    lhs->print(file_buffer);
    file_buffer << ")";
}

// Cond Expr Ast

Conditional_Expression_Ast::Conditional_Expression_Ast(Ast *cond_Ast, Ast *l, Ast *r, int line)
{
    cond = cond_Ast;
    lhs = l;
    rhs = r;
    ast_num_child = binary_arity;
    lineno = line;
    get_new_label();
}

void Conditional_Expression_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n"
                << AST_SPACE << "Cond:\n"
                << AST_NODE_SPACE << "IF_ELSE";
    cond->print(file_buffer);
    file_buffer << "\n"
                << AST_NODE_SPACE << "LHS (";
    lhs->print(file_buffer);
    file_buffer << ")\n"
                << AST_NODE_SPACE << "RHS (";
    rhs->print(file_buffer);
    file_buffer << ")";
}

// Print_Ast

Print_Ast::Print_Ast(Ast *v, int line){
    var = v;
    lineno = line;
}
Print_Ast::~Print_Ast(){}

void Print_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n"
                << AST_SPACE << "Print :\n"
                << AST_SUB_NODE_SPACE << "(";
    var->print(file_buffer);
    file_buffer << ")";
}

// Relational Expr Ast

Relational_Expr_Ast::Relational_Expr_Ast(Ast *lhs, Relational_Op rop, Ast *rhs, int line)
{
    lhs_condition = lhs;
    rhs_condition = rhs;
    rel_op = rop;
    ast_num_child = binary_arity;
    lineno = line;
}

Data_Type Relational_Expr_Ast::get_data_type()
{
    return node_data_type;
}

void Relational_Expr_Ast::set_data_type(Data_Type dt)
{
    node_data_type = dt;
}

bool Relational_Expr_Ast::check_ast()
{
    if (lhs_condition->get_data_type() == rhs_condition->get_data_type())
    {
        node_data_type = lhs_condition->get_data_type();
        return 1;
    }

    cerr << "cs316: Error: Line: " << lineno << ": Relational statement data type not compatible\n";
    exit(0);
}

void Relational_Expr_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n" << AST_NODE_SPACE << "Condition: ";
    // printf("%d\n", rel_op);
    switch (rel_op)
    {
    case 0:
        file_buffer << "LE";
        break;
    case 1:
        file_buffer << "LT";
        break;
    case 2:
        file_buffer << "GT";
        break;
    case 3:
        file_buffer << "GE";
        break;
    case 4:
        file_buffer << "EQ";
        break;
    case 5:
        file_buffer << "NE";
        break;
    default:
        printf("wrong operator in Relational_Expr_Ast\n");
        break;
    }
    file_buffer << "\n" << AST_SUB_NODE_SPACE << "LHS (";
    lhs_condition->print(file_buffer);
    file_buffer << ")\n" << AST_SUB_NODE_SPACE << "RHS (";
    rhs_condition->print(file_buffer);
    file_buffer << ")";
}

// Logical Expr Ast

Logical_Expr_Ast::Logical_Expr_Ast(Ast *lhs, Logical_Op bop, Ast *rhs, int line)
{
    lhs_op = lhs;
    rhs_op = rhs;
    bool_op = bop;
    if (lhs_op == NULL)
        ast_num_child = unary_arity;
    else
        ast_num_child = binary_arity;
    lineno = line;
}

Data_Type Logical_Expr_Ast::get_data_type()
{
    return node_data_type;
}

void Logical_Expr_Ast::set_data_type(Data_Type dt)
{
    node_data_type = dt;
}

bool Logical_Expr_Ast::check_ast() {

    if(lhs_op != NULL){
        if (lhs_op->get_data_type() == rhs_op->get_data_type())
        {
            node_data_type = lhs_op->get_data_type();
            return 1;
        }

        cerr << "cs316: Error: Line: " << lineno << ": Logical statement data type not compatible\n";
        exit(0);
    }
    else{
        node_data_type = rhs_op->get_data_type();
        return 1;
    }

    
}

void Logical_Expr_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n"
                << AST_NODE_SPACE << "Condition: ";
    switch (bool_op)
    {
    case 0:
        file_buffer << "NOT";
        break;
    case 1:
        file_buffer << "OR";
        break;
    case 2:
        file_buffer << "AND";
        break;
    default:
        printf("wrong operator in Logical_Expr_Ast\n");
        break;
    }
    if(lhs_op != NULL){
        file_buffer << "\n"
                    << AST_SUB_NODE_SPACE << "LHS (";
        lhs_op->print(file_buffer);
        file_buffer << ")";
    }
    file_buffer << "\n"
                << AST_SUB_NODE_SPACE << "RHS (";
    rhs_op->print(file_buffer);
    file_buffer << ")";
}

// Selection Statement Ast

Selection_Statement_Ast::Selection_Statement_Ast(Ast *cond_Ast, Ast *then_part_Ast, Ast *else_part_Ast, int line)
{
    cond = cond_Ast;
    then_part = then_part_Ast;
    else_part = else_part_Ast;
    if (else_part == NULL)
        ast_num_child = binary_arity;
    else
        ast_num_child = ternary_arity;
    lineno = line;
}

Data_Type Selection_Statement_Ast::get_data_type()
{
    return node_data_type;
}

void Selection_Statement_Ast::set_data_type(Data_Type dt)
{
    node_data_type = dt;
}

bool Selection_Statement_Ast::check_ast(){}

void Selection_Statement_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n"
                << AST_SPACE << "IF : \n"
                << AST_SPACE << "CONDITION (";
    cond->print(file_buffer);
    file_buffer << ")\n"
                << AST_SPACE << "THEN (";
    then_part->print(file_buffer);
    file_buffer << ")";
    if (else_part != NULL)
    {
        file_buffer << "\n"
                    << AST_SPACE << "ELSE (";
        else_part->print(file_buffer);
        file_buffer << ")";
    }
}

// Iteration Statement Ast

Iteration_Statement_Ast::Iteration_Statement_Ast(Ast *cond_Ast, Ast *body_Ast, int line, bool do_form)
{
    cond = cond_Ast;
    body = body_Ast;
    is_do_form = do_form;
    ast_num_child = binary_arity;
    lineno = line;
}

Data_Type Iteration_Statement_Ast::get_data_type()
{
    return node_data_type;
}

void Iteration_Statement_Ast::set_data_type(Data_Type dt)
{
    node_data_type = dt;
}

bool Iteration_Statement_Ast::check_ast() {}

void Iteration_Statement_Ast::print(ostream &file_buffer)
{
    if (is_do_form)
    {
        file_buffer << "\n"
                    << AST_SPACE << "DO (";
        body->print(file_buffer);
        file_buffer << ")\n"
                    << AST_SPACE << "WHILE CONDITION (";
        cond->print(file_buffer);
        file_buffer << ")";
    }
    else
    {
        file_buffer << "\n"
                    << AST_SPACE << "WHILE : \n"
                    << AST_SPACE << "CONDITION (";
        cond->print(file_buffer);
        file_buffer << ")\n"
                    << AST_SPACE << "BODY (";
        body->print(file_buffer);
        file_buffer << ")";
    }
}

// Sequence Ast

Sequence_Ast::Sequence_Ast(int line)
{
    lineno = line;
    // list<Ast *> statement_list = new list<Ast *>;
    get_new_label();
}

void Sequence_Ast::ast_push_back(Ast *ast)
{
    statement_list.push_back(ast);
}

void Sequence_Ast::print(ostream &file_buffer)
{
    for (list<Ast *>::iterator it = statement_list.begin(); it != statement_list.end(); it++)
    {
        file_buffer << "\n" << AST_NODE_SPACE;
        (*it)->print(file_buffer);
    }
}

// Call Ast

Call_Ast::Call_Ast(string name, int line)
{
    procedure_name = name;
    lineno = line;
    // ast_num_child = unary_arity;
}

Data_Type Call_Ast::get_data_type()
{
    // Procedure * p = get_procedure_prototype(procedure_name);
    // return p.get_return_type();
}

void Call_Ast::set_register(Register_Descriptor * reg)
{
    return_value_reg = reg;
}

void Call_Ast::check_actual_formal_param(Symbol_Table & formal_param_list)
{
    list<Symbol_Table_Entry *> & symbol_table_list = formal_param_list.get_table();
    if(actual_param_list.size() != symbol_table_list.size()){
        cerr << "cs316: Error: Line: " << lineno << ": Actual and formal parameter count do not match\n";
        exit(0);
    }
    list<Ast *>::iterator itr_ast = actual_param_list.begin();
    for(list<Symbol_Table_Entry *>::iterator it = symbol_table_list.begin(); it != symbol_table_list.end(); it++)
    {
        if((*itr_ast)->get_data_type() != (*it)->get_data_type()){
            cerr << "cs316: Error: Line: " << lineno << ": Actual and formal parameters data types are not matching\n";
            exit(0);
        }
        itr_ast++;
    }
}

void Call_Ast::set_actual_param_list(list<Ast *> & param_list)
{
    actual_param_list = param_list; 
}

void Call_Ast::print(ostream & file_buffer)
{
    file_buffer << "\n"
                << AST_SPACE << "FN CALL: " << procedure_name << "("; //TODO: iterate over actual_param_list

    // list<Symbol_Table_Entry *> &symbol_table_list = actual_param_list;

    // for(list<Symbol_Table_Entry *>::iterator it = symbol_table_list.begin(); it != symbol_table_list.end(); it++)
    // {
    //     file_buffer << "\n" << AST_NODE_SPACE << "Name : " << (*it).get_variable_name();
    // }
    file_buffer << ")";
}

// Return Ast

Return_Ast::Return_Ast(Ast *ret_val, string name, int line)
{
    lineno = line;
    ast_num_child = unary_arity;
    return_value = ret_val;
}
Return_Ast::~Return_Ast(){}

Data_Type Return_Ast::get_data_type()
{
    return return_value->get_data_type();
}

void Return_Ast::print(ostream &file_buffer)
{
    file_buffer << "\n"
                << AST_SPACE << "RETURN ";
    return_value->print(file_buffer);
}