#include "local-environment.hh"
#include "symbol-table.hh"
#include <stdlib.h>
using namespace std;

void Symbol_Table::create(Local_Environment &local_global_variables_table){

    for (list<Symbol_Table_Entry *>::iterator it = variable_table.begin(); it != variable_table.end(); ++it)
    {
        // seq_ast_then->ast_push_back(*it);
    }

    // local_global_variables_table.put_variable_value();

}

//Eval_Result

int Eval_Result::get_int_value(){}
void Eval_Result::set_value(int value){}
double Eval_Result::get_double_value(){}
void Eval_Result::set_value(double value){}

bool Eval_Result::is_variable_defined(){}
void Eval_Result::set_variable_status(bool def){}

void Eval_Result::set_result_enum(Result_Enum){}
Result_Enum Eval_Result::get_result_enum(){}

//Eval_result_Value

void Eval_Result_Value::set_value(int number){}
void Eval_Result_Value::set_value(double number){}
int Eval_Result_Value::get_int_value(){}
double Eval_Result_Value::get_double_value(){}

bool Eval_Result_Value::is_variable_defined(){}
void Eval_Result_Value::set_variable_status(bool def){}

void Eval_Result_Value::set_result_enum(Result_Enum res){}
Result_Enum Eval_Result_Value::get_result_enum(){}

//Eval_Result_Value_Int

Eval_Result_Value_Int::Eval_Result_Value_Int() {}
Eval_Result_Value_Int::~Eval_Result_Value_Int() {}

void Eval_Result_Value_Int::set_value(int number) {}
void Eval_Result_Value_Int::set_value(double number) {}
int Eval_Result_Value_Int::get_int_value() {}

void Eval_Result_Value_Int::set_variable_status(bool def) {}
bool Eval_Result_Value_Int::is_variable_defined() {}

void Eval_Result_Value_Int::set_result_enum(Result_Enum res) {}
Result_Enum Eval_Result_Value_Int::get_result_enum() {}

//Eval_Result_Value_Double

Eval_Result_Value_Double::Eval_Result_Value_Double() {}
Eval_Result_Value_Double::~Eval_Result_Value_Double() {}

void Eval_Result_Value_Double::set_value(double number) {}
void Eval_Result_Value_Double::set_value(int number) {}
double Eval_Result_Value_Double::get_double_value() {}

void Eval_Result_Value_Double::set_variable_status(bool def) {}
bool Eval_Result_Value_Double::is_variable_defined() {}

void Eval_Result_Value_Double::set_result_enum(Result_Enum res) {}
Result_Enum Eval_Result_Value_Double::get_result_enum() {}

// Local_Environment
Local_Environment::Local_Environment(){}
Local_Environment::~Local_Environment() {}

void Local_Environment::print(ostream &file_buffer){
}

bool Local_Environment::is_variable_defined(string name)
{
}
Eval_Result * Local_Environment::get_variable_value(string name)
{
}
void Local_Environment::put_variable_value(Eval_Result &value, string name)
{
}
bool Local_Environment::does_variable_exist(string name)
{
}