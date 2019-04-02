#include "ast.hh"
#include <stdlib.h>
#include <list>
#include "icode.hh"
#include "symbol-table.hh"
#include "icode.hh"
#include "reg-alloc.hh"

using namespace std;
template class Number_Ast<int>;
template class Number_Ast<double>;

// Ast

Code_For_Ast & Ast::compile(){}

Code_For_Ast & Ast::create_store_stmt(Register_Descriptor * store_register){}


// Assignment Ast

Code_For_Ast & Assignment_Ast::compile(){
	Code_For_Ast & rhscfa = rhs->compile();
	Code_For_Ast & lhscfa = lhs->create_store_stmt(rhscfa.get_reg());

	Code_For_Ast & cfa = new Code_For_Ast();
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();
	for(int i = 0; i < rhsstmts.size(); i++){
		cfa.append_ics(rhsstmts.pop_back());
	}
	for(int i = 0; i < lhsstmts.size(); i++){
		cfa.append_ics(lhsstmts.pop_back());
	}

	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
	}
	else{
		r = machine_desc_object.get_new_register<float_reg>();
	}
	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}
Code_For_Ast & Assignment_Ast::compile_and_optimize_ast(Lra_Outcome &lra){}

// Name Ast

Code_For_Ast & Name_Ast::compile(){
	Code_For_Ast cfa = new Code_For_Ast();
	Register_Descriptor * r;
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		cfa.set_reg(r);

		Ics_Opd * o1 = new Mem_Addr_Opd(variable_symbol_entry);
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Move_IC_Stmt(load, o1, result)));
	}
	else{
		r = machine_desc_object.get_new_register<float_reg>();
		cfa.set_reg(r);

		Ics_Opd * o1 = new Mem_Addr_Opd(variable_symbol_entry);
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Move_IC_Stmt(load_d, o1, result)));
	}

	return cfa;
}

Code_For_Ast & Name_Ast::create_store_stmt(Register_Descriptor * store_register){
	Code_For_Ast cfa = new Code_For_Ast();
	Ics_Opd *result = new Mem_Addr_Opd(*variable_symbol_entry);
	Register_Descriptor * r;

	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		cfa.set_reg(r);

		Ics_Opd * o1 = new Register_Addr_Opd(store_register);
		Ics_Opd * result = new Mem_Addr_Opd(variable_symbol_entry);
		cfa.append_ics(*(new Move_IC_Stmt(store, o1, result)));
	}
	else{
		r = machine_desc_object.get_new_register<float_reg>();
		cfa.set_reg(r);

		Ics_Opd * o1 = new Register_Addr_Opd(store_register);
		Ics_Opd * result = new Mem_Addr_Opd(variable_symbol_entry);
		cfa.append_ics(*(new Move_IC_Stmt(store_d, o1, result)));
	}

	return cfa;
}

Code_For_Ast & Name_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}

// Number Ast

template <class T>
Code_For_Ast & Number_Ast<T>::compile(){
	Code_For_Ast cfa = new Code_For_Ast();
	Register_Descriptor * r;
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * o1 = new Const_Opd<int>(constant);
		cfa.set_reg(r);

		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Move_IC_Stmt(imm_load, o1, result)));
	}
	else{
		r = machine_desc_object.get_new_register<float_reg>();
		Ics_Opd * o1 = new Const_Opd<double>(constant);
		cfa.set_reg(r);

		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Move_IC_Stmt(imm_load_d, o1, result)));
	}

	return cfa;
}

template <class T>
Code_For_Ast & Number_Ast<T>::compile_and_optimize_ast(Lra_Outcome & lra){}


// Arithmetic Expr Ast

Code_For_Ast & Arithmetic_Expr_Ast::compile(){}
Code_For_Ast & Arithmetic_Expr_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}


// Plus Ast

Code_For_Ast & Plus_Ast::compile(){
	Code_For_Ast & rhscfa = lhs->compile();
	Code_For_Ast & lhscfa = rhs->compile();
	Code_For_Ast & cfa = new Code_For_Ast();
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();
	for(int i = 0; i < lhsstmts.size(); i++){
		cfa.append_ics(lhsstmts.pop_back());
	}
	for(int i = 0; i < rhsstmts.size(); i++){
		cfa.append_ics(rhsstmts.pop_back());
	}

	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * o2 = new Register_Addr_Opd(rhscfa.get_reg());
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(add, o1, o2, result)));
	}
	else{
		r = machine_desc_object.get_new_register<float_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Move_IC_Stmt(add_d, o1, o2, result)));
	}
	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}
Code_For_Ast &Plus_Ast::compile_and_optimize_ast(Lra_Outcome &lra){}

// Minus Ast

Code_For_Ast & Minus_Ast::compile(){
	Code_For_Ast & rhscfa = lhs->compile();
	Code_For_Ast & lhscfa = rhs->compile();
	Code_For_Ast & cfa = new Code_For_Ast();
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();
	for(int i = 0; i < lhsstmts.size(); i++){
		cfa.append_ics(lhsstmts.pop_back());
	}
	for(int i = 0; i < rhsstmts.size(); i++){
		cfa.append_ics(rhsstmts.pop_back());
	}

	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * o2 = new Register_Addr_Opd(rhscfa.get_reg());
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(sub, o1, o2, result)));
	}
	else{
		r = machine_desc_object.get_new_register<float_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(sub_d, o1, o2, result)));
	}
	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}
Code_For_Ast &Minus_Ast::compile_and_optimize_ast(Lra_Outcome &lra){}

// Divide Ast

Code_For_Ast & Divide_Ast::compile(){
	Code_For_Ast & rhscfa = lhs->compile();
	Code_For_Ast & lhscfa = rhs->compile();
	Code_For_Ast & cfa = new Code_For_Ast();
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();
	for(int i = 0; i < lhsstmts.size(); i++){
		cfa.append_ics(lhsstmts.pop_back());
	}
	for(int i = 0; i < rhsstmts.size(); i++){
		cfa.append_ics(rhsstmts.pop_back());
	}

	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * o2 = new Register_Addr_Opd(rhscfa.get_reg());
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(divd, o1, o2, result)));
	}
	else{
		r = machine_desc_object.get_new_register<float_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(div_d, o1, o2, result)));
	}
	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}
Code_For_Ast &Divide_Ast::compile_and_optimize_ast(Lra_Outcome &lra){}

// Mult Ast

Code_For_Ast & Mult_Ast::compile(){
	Code_For_Ast & rhscfa = lhs->compile();
	Code_For_Ast & lhscfa = rhs->compile();
	Code_For_Ast & cfa = new Code_For_Ast();
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();
	for(int i = 0; i < lhsstmts.size(); i++){
		cfa.append_ics(lhsstmts.pop_back());
	}
	for(int i = 0; i < rhsstmts.size(); i++){
		cfa.append_ics(rhsstmts.pop_back());
	}

	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * o2 = new Register_Addr_Opd(rhscfa.get_reg());
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(mult, o1, o2, result)));
	}
	else{
		r = machine_desc_object.get_new_register<float_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(mult_d, o1, o2, result)));
	}
	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}
Code_For_Ast &Mult_Ast::compile_and_optimize_ast(Lra_Outcome &lra){}

// UMinus Ast

Code_For_Ast & UMinus_Ast::compile(){
	Code_For_Ast & rhscfa = lhs->compile();
	Code_For_Ast & cfa = new Code_For_Ast();
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	for(int i = 0; i < lhsstmts.size(); i++){
		cfa.append_ics(lhsstmts.pop_back());
	}

	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Move_IC_Stmt(uminus, o1, result)));
	}
	else{
		r = machine_desc_object.get_new_register<float_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Move_IC_Stmt(uminus_d, o1, result)));
	}
	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}
Code_For_Ast & UMinus_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}


// Conditional Expression Ast

Code_For_Ast & Conditional_Expression_Ast::compile(){
	Code_For_Ast & condcfa = cond->compile();
	Code_For_Ast & rhscfa = lhs->compile();
	Code_For_Ast & lhscfa = rhs->compile();
	Code_For_Ast & cfa = new Code_For_Ast();
	Register_Descriptor * r;

	list<Icode_Stmt *> & condstmts = condcfa.get_icode_list();	
	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();
	for(int i = 0; i < condstmts.size(); i++){
		cfa.append_ics(condstmts.pop_back());
	}
	for(int i = 0; i < lhsstmts.size(); i++){
		cfa.append_ics(lhsstmts.pop_back());
	}
	for(int i = 0; i < rhsstmts.size(); i++){
		cfa.append_ics(rhsstmts.pop_back());
	}

	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * o2 = new Register_Addr_Opd(rhscfa.get_reg());
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(mult, o1, o2, result)));
	}
	else{
		r = machine_desc_object.get_new_register<float_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(mult_d, o1, o2, result)));
	}
	cfa.set_reg(r);

	return cfa;
}

// Return Ast

Code_For_Ast & Return_Ast::compile(){}
Code_For_Ast & Return_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}


// Relational Expr Ast

Code_For_Ast & Relational_Expr_Ast::compile(){}


// Logical Expr Ast

Code_For_Ast & Logical_Expr_Ast::compile(){}


// Selection Statement Ast

Code_For_Ast & Selection_Statement_Ast::compile(){}


// Iteration Statement Ast

Code_For_Ast & Iteration_Statement_Ast::compile(){}


// Sequence Ast
Code_For_Ast & Sequence_Ast::compile(){}
