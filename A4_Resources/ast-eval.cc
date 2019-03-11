#include "ast.hh"
#include <stdlib.h>
#include "local-environment.hh"

using namespace std;

template class Number_Ast<double>;
template class Number_Ast<int>;

int Ast::labelCounter;

// Ast

void Ast::print_value(Local_Environment & eval_env, ostream & file_buffer){}
Eval_Result & Ast::get_value_of_evaluation(Local_Environment & eval_env){}
void Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result){}
Eval_Result & Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Assignment Ast

Eval_Result & Assignment_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Name Ast

void Name_Ast::print_value(Local_Environment & eval_env, ostream & file_buffer){}
Eval_Result & Name_Ast::get_value_of_evaluation(Local_Environment & eval_env){}
void Name_Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result){}
Eval_Result & Name_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Number Ast

template <class T>
Eval_Result & Number_Ast<T>::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Arithmetic Expr Ast

Eval_Result & Arithmetic_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Plus Ast

Eval_Result & Plus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Minus Ast

Eval_Result & Minus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Divide Ast

Eval_Result & Divide_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Mult Ast

Eval_Result & Mult_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// UMinus Ast

Eval_Result & UMinus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Conditional Expression Ast

Eval_Result & Conditional_Expression_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Return Ast

Eval_Result & Return_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Relational Expr Ast

Eval_Result & Relational_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Logical Expr Ast

Eval_Result & Logical_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Selection Statement Ast

Eval_Result & Selection_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Iteration Statement Ast

Eval_Result & Iteration_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Sequence Ast

Eval_Result & Sequence_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}

