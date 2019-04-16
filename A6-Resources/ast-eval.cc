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
        
    file_buffer << "\n\n";    
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
        if(eval_env.is_variable_defined(variable_symbol_entry->get_variable_name()))
            return *(eval_env.get_variable_value(variable_symbol_entry->get_variable_name()));
        else{
            cerr << "cs316: Error: Line: " << lineno << ": Variable should be defined before its use\n";
            exit(0);
        }
            
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
        if(rhs_result.get_int_value() == 0){
            cerr << "cs316: Error: Line: " << lineno << ": Divide by 0\n";
            exit(0);
        }
        else{
            eval_res->set_value(lhs_result.get_int_value() / rhs_result.get_int_value());
        }
        return *eval_res;
    }
    else
    {
        Eval_Result *eval_res = new Eval_Result_Value_Double();
        eval_res->set_result_enum(double_result);
        if (rhs_result.get_double_value() == 0.0)
        {
            cerr << "cs316: Error: Line: " << lineno << ": Divide by 0\n";
            exit(0);
        }
        else
        {
            eval_res->set_value(lhs_result.get_double_value() / rhs_result.get_double_value());
        }
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

Eval_Result & Relational_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    Eval_Result &lhs_result = lhs_condition->evaluate(eval_env, file_buffer);
    Eval_Result &rhs_result = rhs_condition->evaluate(eval_env, file_buffer);

    Eval_Result *eval_res = new Eval_Result_Value_Int();
    eval_res->set_result_enum(int_result);

    switch (rel_op)
    {
    case 0:
        // file_buffer << "LE";
        if(lhs_result.get_result_enum() == int_result)
        {
            if(lhs_result.get_int_value() <= rhs_result.get_int_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        else
        {
            if (lhs_result.get_double_value() <= rhs_result.get_double_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        break;

    case 1:
        // file_buffer << "LT";
        if (lhs_result.get_result_enum() == int_result)
        {
            if (lhs_result.get_int_value() < rhs_result.get_int_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        else
        {
            if (lhs_result.get_double_value() < rhs_result.get_double_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        break;

    case 2:
        // file_buffer << "GT";
        if (lhs_result.get_result_enum() == int_result)
        {
            if (lhs_result.get_int_value() > rhs_result.get_int_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        else
        {
            if (lhs_result.get_double_value() > rhs_result.get_double_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        break;

    case 3:
        // file_buffer << "GE";
        if(lhs_result.get_result_enum() == int_result)
        {
            if(lhs_result.get_int_value() >= rhs_result.get_int_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        else
        {
            if (lhs_result.get_double_value() >= rhs_result.get_double_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        break;

    case 4:
        // file_buffer << "EQ";
        if (lhs_result.get_result_enum() == int_result)
        {
            if (lhs_result.get_int_value() == rhs_result.get_int_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        else
        {
            if (lhs_result.get_double_value() == rhs_result.get_double_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        break;

    case 5:
        // file_buffer << "NE";
        if (lhs_result.get_result_enum() == int_result)
        {
            if (lhs_result.get_int_value() != rhs_result.get_int_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        else
        {
            if (lhs_result.get_double_value() != rhs_result.get_double_value())
                eval_res->set_value(1);
            else
                eval_res->set_value(0);
        }
        break;

    default:
        printf("wrong operator in Relational_Expr_Ast\n");
        break;
    }

    return *eval_res;

}


// Logical Expr Ast

Eval_Result & Logical_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    Eval_Result &rhs_result = rhs_op->evaluate(eval_env, file_buffer);
    // Eval_Result &lhs_result = lhs_op->evaluate(eval_env, file_buffer);

    Eval_Result *eval_res = new Eval_Result_Value_Int();
    eval_res->set_result_enum(int_result);

    switch (bool_op)
    {
    case 0:
        // file_buffer << "NOT";
        if (!rhs_result.get_int_value())
            eval_res->set_value(1);
        else
            eval_res->set_value(0);
        break;

    case 1:
        // file_buffer << "OR";
        if (lhs_op->evaluate(eval_env, file_buffer).get_int_value() || rhs_result.get_int_value())
            eval_res->set_value(1);
        else
            eval_res->set_value(0);
        break;

    case 2:
        // file_buffer << "AND";
        if (lhs_op->evaluate(eval_env, file_buffer).get_int_value() && rhs_result.get_int_value())
            eval_res->set_value(1);
        else
            eval_res->set_value(0);
        break;

    default:
        printf("wrong operator in Logical_Expr_Ast\n");
        break;
    }
    return *eval_res;
}


// Selection Statement Ast

Eval_Result & Selection_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    
    Eval_Result &cond_result = cond->evaluate(eval_env, file_buffer);

    if(cond_result.get_int_value()){
        then_part->evaluate(eval_env, file_buffer);
    }
    else{
        if(else_part != NULL)
            else_part->evaluate(eval_env, file_buffer);
    }

}


// Iteration Statement Ast

Eval_Result & Iteration_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    if(is_do_form){
        do{
            body->evaluate(eval_env, file_buffer);
        }
        while(cond->evaluate(eval_env, file_buffer).get_int_value());
    }
    else{
        while(cond->evaluate(eval_env, file_buffer).get_int_value()){
            body->evaluate(eval_env, file_buffer);
        }
    }
    
}


// Sequence Ast

Eval_Result & Sequence_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
    for (std::list<Ast*>::iterator it = statement_list.begin(); it != statement_list.end(); ++it){
        (*it)->evaluate(eval_env, file_buffer);
    }

}


// Call Ast

Eval_Result & Call_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}


// Return Ast

Eval_Result & Return_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{}