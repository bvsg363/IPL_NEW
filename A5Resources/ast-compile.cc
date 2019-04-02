#include "ast.hh"
#include <stdlib.h>
#include <list>
#include "symbol-table.hh"
#include "icode.hh"

using namespace std;


// Ast

Code_For_Ast & Ast::compile(){}

Code_For_Ast & Ast::create_store_stmt(Register_Descriptor * store_register){}


// Assignment Ast

Code_For_Ast & Assignment_Ast::compile(){}


// Name Ast

Code_For_Ast & Name_Ast::compile(){}

Code_For_Ast & Name_Ast::create_store_stmt(Register_Descriptor * store_register){
	Code_For_Ast cfa = Code_For_Ast();
	Ics_Opd result = new Mem_Addr_Opd(variable_symbol_entry);
	Register_Descriptor * r;
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
	}
	else{
		r = machine_desc_object.get_new_register<float_reg>();
	}
	Ics_Opd o1 = Register_Addr_Opd(r);
	cfa.append_ics(new Move_IC_Stmt(store, o1, result));
	cfa.set_reg(r);
}


// Number Ast

template <class T>
Code_For_Ast & Number_Ast<T>::compile(){
	Code_For_Ast cfa = new Code_For_Ast();
	Ics_Opd o1 = Const_Opd(constant);
	Register_Descriptor * r;
	if()
	Ics_Opd result = Register_Addr_Opd(r);
	cfa.append_ics(Move_IC_Stmt(iLoad, o1, result));
	cfa.set_reg(r);
}


// Arithmetic Expr Ast

Code_For_Ast & Arithmetic_Expr_Ast::compile(){}


// Plus Ast

Code_For_Ast & Plus_Ast::compile(){}


// Minus Ast

Code_For_Ast & Minus_Ast::compile(){}


// Divide Ast

Code_For_Ast & Divide_Ast::compile(){}


// Mult Ast

Code_For_Ast & Mult_Ast::compile(){}


// UMinus Ast

Code_For_Ast & UMinus_Ast::compile(){}


// Conditional Expression Ast

Code_For_Ast & Conditional_Expression_Ast::compile(){}


// Return Ast

Code_For_Ast & Return_Ast::compile(){}


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
