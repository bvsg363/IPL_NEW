#include "ast.hh"
#include <stdlib.h>
#include "local-environment.hh"
#include "symbol-table.hh"

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

Eval_Result & Assignment_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    print(file_buffer);
    Eval_Result & rhs_result = rhs->evaluate(eval_env, file_buffer);
    lhs->set_value_of_evaluation(eval_env, rhs_result);
    lhs->print_value(eval_env, file_buffer);
}


// Name Ast

void Name_Ast::print_value(Local_Environment & eval_env, ostream & file_buffer)
{
    file_buffer << "\n" << VAR_SPACE << variable_symbol_entry->get_variable_name() << " : ";

    if(variable_symbol_entry->get_symbol_scope() == global)
    {
        if (get_data_type() == int_data_type)
        {
            file_buffer << get_value_of_evaluation(interpreter_global_table).get_int_value();
        }
        else
        {
            file_buffer << get_value_of_evaluation(interpreter_global_table).get_double_value();
        }
    }
    else
    {
        if (get_data_type() == int_data_type)
        {
            file_buffer << get_value_of_evaluation(eval_env).get_int_value();
        }
        else
        {
            file_buffer << get_value_of_evaluation(eval_env).get_double_value();
        }
    }
        
    file_buffer << "\n";    
}

Eval_Result & Name_Ast::get_value_of_evaluation(Local_Environment & eval_env)
{
    if (variable_symbol_entry->get_symbol_scope() == global)
    {
        return *(interpreter_global_table.get_variable_value(variable_symbol_entry->get_variable_name()));
    }
    else
    {
        return *(eval_env.get_variable_value(variable_symbol_entry->get_variable_name()));
    }
}

void Name_Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result)
{
    result.set_variable_status(true);

    if(variable_symbol_entry->get_symbol_scope() == global){
        interpreter_global_table.put_variable_value(result, variable_symbol_entry->get_variable_name());
    }
    else
    {
        eval_env.put_variable_value(result, variable_symbol_entry->get_variable_name());
    }
}

Eval_Result & Name_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    if (variable_symbol_entry->get_symbol_scope() == global)
    {
        return *(interpreter_global_table.get_variable_value(variable_symbol_entry->get_variable_name()));
    }
    else
    {
        return *(eval_env.get_variable_value(variable_symbol_entry->get_variable_name()));
    }
}


// Number Ast

template <class T>
Eval_Result & Number_Ast<T>::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    if (get_data_type() == int_data_type)
    {
        Eval_Result *eval_res = new Eval_Result_Value_Int();
        eval_res->set_result_enum(int_result);
        eval_res->set_value(constant);
        return *eval_res;
    }
    else
    {
        Eval_Result *eval_res = new Eval_Result_Value_Double();
        eval_res->set_result_enum(double_result);
        eval_res->set_value(constant);
        return *eval_res;
    }
        
}


// Arithmetic Expr Ast

Eval_Result & Arithmetic_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Plus Ast

Eval_Result & Plus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    Eval_Result &lhs_result = lhs->evaluate(eval_env, file_buffer);
    Eval_Result &rhs_result = rhs->evaluate(eval_env, file_buffer);

    if (get_data_type() == int_data_type)
    {
        Eval_Result *eval_res = new Eval_Result_Value_Int();
        eval_res->set_result_enum(int_result);
        eval_res->set_value(lhs_result.get_int_value() + rhs_result.get_int_value());
        return *eval_res;
    }
    else
    {
        Eval_Result *eval_res = new Eval_Result_Value_Double();
        eval_res->set_result_enum(double_result);
        eval_res->set_value(lhs_result.get_double_value() + rhs_result.get_double_value());
        return *eval_res;
    }
}


// Minus Ast

Eval_Result & Minus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    Eval_Result &lhs_result = lhs->evaluate(eval_env, file_buffer);
    Eval_Result &rhs_result = rhs->evaluate(eval_env, file_buffer);

    if (get_data_type() == int_data_type)
    {
        Eval_Result *eval_res = new Eval_Result_Value_Int();
        eval_res->set_result_enum(int_result);
        eval_res->set_value(lhs_result.get_int_value() - rhs_result.get_int_value());
        return *eval_res;
    }
    else
    {
        Eval_Result *eval_res = new Eval_Result_Value_Double();
        eval_res->set_result_enum(double_result);
        eval_res->set_value(lhs_result.get_double_value() - rhs_result.get_double_value());
        return *eval_res;
    }
}


// Divide Ast

Eval_Result & Divide_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)  //check 1/0 case
{
    Eval_Result &lhs_result = lhs->evaluate(eval_env, file_buffer);
    Eval_Result &rhs_result = rhs->evaluate(eval_env, file_buffer);

    if (get_data_type() == int_data_type)
    {
        Eval_Result *eval_res = new Eval_Result_Value_Int();
        eval_res->set_result_enum(int_result);
        eval_res->set_value(lhs_result.get_int_value() / rhs_result.get_int_value());
        return *eval_res;
    }
    else
    {
        Eval_Result *eval_res = new Eval_Result_Value_Double();
        eval_res->set_result_enum(double_result);
        eval_res->set_value(lhs_result.get_double_value() / rhs_result.get_double_value());
        return *eval_res;
    }
}


// Mult Ast

Eval_Result & Mult_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    Eval_Result &lhs_result = lhs->evaluate(eval_env, file_buffer);
    Eval_Result &rhs_result = rhs->evaluate(eval_env, file_buffer);

    if (get_data_type() == int_data_type)
    {
        Eval_Result *eval_res = new Eval_Result_Value_Int();
        eval_res->set_result_enum(int_result);
        eval_res->set_value(lhs_result.get_int_value() * rhs_result.get_int_value());
        return *eval_res;
    }
    else
    {
        Eval_Result *eval_res = new Eval_Result_Value_Double();
        eval_res->set_result_enum(double_result);
        eval_res->set_value(lhs_result.get_double_value() * rhs_result.get_double_value());
        return *eval_res;
    }
}


// UMinus Ast

Eval_Result & UMinus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    Eval_Result &lhs_result = lhs->evaluate(eval_env, file_buffer);

    if (get_data_type() == int_data_type)
    {
        Eval_Result *eval_res = new Eval_Result_Value_Int();
        eval_res->set_result_enum(int_result);
        eval_res->set_value(lhs_result.get_int_value() * -1);
        return *eval_res;
    }
    else
    {
        Eval_Result *eval_res = new Eval_Result_Value_Double();
        eval_res->set_result_enum(double_result);
        eval_res->set_value(lhs_result.get_double_value() * -1.0);
        return *eval_res;
    }
}


// Conditional Expression Ast

Eval_Result & Conditional_Expression_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    Eval_Result &lhs_result = lhs->evaluate(eval_env, file_buffer);
    Eval_Result &rhs_result = rhs->evaluate(eval_env, file_buffer);
    Eval_Result &cond_result = cond->evaluate(eval_env, file_buffer);

    if (get_data_type() == int_data_type)
    {
        Eval_Result *eval_res = new Eval_Result_Value_Int();
        eval_res->set_result_enum(int_result);
        if(cond_result.get_int_value() == 1)
            eval_res->set_value(lhs_result.get_int_value());
        else
            eval_res->set_value(rhs_result.get_int_value());
        
        return *eval_res;
    }
    else
    {
        Eval_Result *eval_res = new Eval_Result_Value_Double();
        eval_res->set_result_enum(double_result);
        if (cond_result.get_int_value() == 1)
            eval_res->set_value(lhs_result.get_double_value());
        else
            eval_res->set_value(rhs_result.get_double_value());
        return *eval_res;
    }
}


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

