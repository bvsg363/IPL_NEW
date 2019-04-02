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

	Code_For_Ast & cfa = *(new Code_For_Ast());
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();

	for(list<Icode_Stmt *>::iterator it = lhsstmts.begin(); it != lhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}
	for(list<Icode_Stmt *>::iterator it = rhsstmts.begin(); it != rhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
	} else{
		r = machine_desc_object.get_new_register<float_reg>();
	}
	cfa.set_reg(r);

	return cfa;
	// TODO: free the lhs register
}
Code_For_Ast & Assignment_Ast::compile_and_optimize_ast(Lra_Outcome &lra){}

// Name Ast

Code_For_Ast & Name_Ast::compile(){
	Code_For_Ast &cfa = *(new Code_For_Ast());
	Register_Descriptor * r;
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		cfa.set_reg(r);

		Ics_Opd * o1 = new Mem_Addr_Opd(*variable_symbol_entry);
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Move_IC_Stmt(load, o1, result)));
	} else{
		r = machine_desc_object.get_new_register<float_reg>();
		cfa.set_reg(r);

		Ics_Opd * o1 = new Mem_Addr_Opd(*variable_symbol_entry);
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Move_IC_Stmt(load_d, o1, result)));
	}

	return cfa;
}

Code_For_Ast & Name_Ast::create_store_stmt(Register_Descriptor * store_register){
	Code_For_Ast &cfa = *(new Code_For_Ast());
	Ics_Opd *result = new Mem_Addr_Opd(*variable_symbol_entry);
	Register_Descriptor * r;

	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		cfa.set_reg(r);

		Ics_Opd * o1 = new Register_Addr_Opd(store_register);
		cfa.append_ics(*(new Move_IC_Stmt(store, o1, result)));
	} else{
		r = machine_desc_object.get_new_register<float_reg>();
		cfa.set_reg(r);

		Ics_Opd * o1 = new Register_Addr_Opd(store_register);
		cfa.append_ics(*(new Move_IC_Stmt(store_d, o1, result)));
	}

	return cfa;
}

Code_For_Ast & Name_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}

// Number Ast

template <class T>
Code_For_Ast & Number_Ast<T>::compile(){
	Code_For_Ast &cfa = *(new Code_For_Ast());
	Register_Descriptor * r;
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * o1 = new Const_Opd<int>(constant);
		cfa.set_reg(r);

		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Move_IC_Stmt(imm_load, o1, result)));
	} else{
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
	Code_For_Ast & rhscfa = rhs->compile();
	Code_For_Ast & lhscfa = lhs->compile();
	Code_For_Ast & cfa = *(new Code_For_Ast());
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();

	for(list<Icode_Stmt *>::iterator it = lhsstmts.begin(); it != lhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}
	for(list<Icode_Stmt *>::iterator it = rhsstmts.begin(); it != rhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * o2 = new Register_Addr_Opd(rhscfa.get_reg());
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(add, o1, o2, result)));
	} else{
		r = machine_desc_object.get_new_register<float_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(add_d, o1, o2, result)));
	}
	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}
Code_For_Ast &Plus_Ast::compile_and_optimize_ast(Lra_Outcome &lra){}

// Minus Ast

Code_For_Ast & Minus_Ast::compile(){
	Code_For_Ast & rhscfa = rhs->compile();
	Code_For_Ast & lhscfa = lhs->compile();
	Code_For_Ast & cfa = *(new Code_For_Ast());
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();

	for(list<Icode_Stmt *>::iterator it = lhsstmts.begin(); it != lhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}
	for(list<Icode_Stmt *>::iterator it = rhsstmts.begin(); it != rhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * o2 = new Register_Addr_Opd(rhscfa.get_reg());
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(sub, o1, o2, result)));
	} else{
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
	Code_For_Ast & rhscfa = rhs->compile();
	Code_For_Ast & lhscfa = lhs->compile();
	Code_For_Ast & cfa = *(new Code_For_Ast());
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();

	for(list<Icode_Stmt *>::iterator it = lhsstmts.begin(); it != lhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}
	for(list<Icode_Stmt *>::iterator it = rhsstmts.begin(); it != rhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * o2 = new Register_Addr_Opd(rhscfa.get_reg());
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(divd, o1, o2, result)));
	} else{
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
	Code_For_Ast & rhscfa = rhs->compile();
	Code_For_Ast & lhscfa = lhs->compile();
	Code_For_Ast & cfa = *(new Code_For_Ast());
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();
	
	for(list<Icode_Stmt *>::iterator it = lhsstmts.begin(); it != lhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}
	for(list<Icode_Stmt *>::iterator it = rhsstmts.begin(); it != rhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * o2 = new Register_Addr_Opd(rhscfa.get_reg());
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Compute_IC_Stmt(mult, o1, o2, result)));
	} else{
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
	Code_For_Ast & lhscfa = lhs->compile();
	Code_For_Ast & cfa = *(new Code_For_Ast());
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	
	for(list<Icode_Stmt *>::iterator it = lhsstmts.begin(); it != lhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
		Ics_Opd * result = new Register_Addr_Opd(r);
		cfa.append_ics(*(new Move_IC_Stmt(uminus, o1, result)));
	} else{
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
	Code_For_Ast & rhscfa = rhs->compile();
	Code_For_Ast & lhscfa = lhs->compile();
	Code_For_Ast & cfa = *(new Code_For_Ast());
	Register_Descriptor * r;

	list<Icode_Stmt *> & condstmts = condcfa.get_icode_list();	
	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();

	for(list<Icode_Stmt *>::iterator it = condstmts.begin(); it != condstmts.end(); ++it){
		cfa.append_ics(**it);
	}
	
	Ics_Opd * o3 = new Register_Addr_Opd(condcfa.get_reg());
	string lbl1 = get_new_label();
	cfa.append_ics(*(new Control_Flow_IC_Stmt(beq, o3, lbl1)));

	for(list<Icode_Stmt *>::iterator it = lhsstmts.begin(); it != lhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	Ics_Opd * o4 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * zr = new Register_Addr_Opd(machine_desc_object.spim_register_table[zero]);
	if(node_data_type == int_data_type){
		r = machine_desc_object.get_new_register<int_reg>();
	} else{
		r = machine_desc_object.get_new_register<float_reg>();
	}
	Ics_Opd * result = new Register_Addr_Opd(r);
	cfa.append_ics(*(new Compute_IC_Stmt(or_t, o4, zr, result)));

	string lbl2 = get_new_label();
	cfa.append_ics(*(new Control_Flow_IC_Stmt(j, zr, lbl2)));

	cfa.append_ics(*(new Label_IC_Stmt(label, lbl1)));

	for(list<Icode_Stmt *>::iterator it = rhsstmts.begin(); it != rhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}
	Ics_Opd * o5 = new Register_Addr_Opd(rhscfa.get_reg());
	cfa.append_ics(*(new Compute_IC_Stmt(or_t, o5, zr, result)));

	cfa.append_ics(*(new Label_IC_Stmt(label, lbl2)));

	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}

// Return Ast

Code_For_Ast & Return_Ast::compile(){}
Code_For_Ast & Return_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}


// Relational Expr Ast

Code_For_Ast & Relational_Expr_Ast::compile(){
	Code_For_Ast & lhscfa = lhs_condition->compile();
	Code_For_Ast & rhscfa = rhs_condition->compile();

	Code_For_Ast & cfa = *(new Code_For_Ast());
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();
	
	for(list<Icode_Stmt *>::iterator it = rhsstmts.begin(); it != rhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	for(list<Icode_Stmt *>::iterator it = lhsstmts.begin(); it != lhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	r = machine_desc_object.get_new_register<int_reg>();
	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * o2 = new Register_Addr_Opd(rhscfa.get_reg());
	Ics_Opd * result = new Register_Addr_Opd(r);
	if(node_data_type == int_data_type){
		switch(rel_op){
		case 0:
			cfa.append_ics(*(new Compute_IC_Stmt(sle, o1, o2, result)));
		case 1:
			cfa.append_ics(*(new Compute_IC_Stmt(slt, o1, o2, result)));
		case 2:
			cfa.append_ics(*(new Compute_IC_Stmt(sgt, o1, o2, result)));
		case 3:
			cfa.append_ics(*(new Compute_IC_Stmt(sge, o1, o2, result)));
		case 4:
			cfa.append_ics(*(new Compute_IC_Stmt(seq, o1, o2, result)));
		case 5:
			cfa.append_ics(*(new Compute_IC_Stmt(sne, o1, o2, result)));
		default:
			printf("wrong operator in compile of Relational_Expr_Ast\n");
			break;
		}
	} else{
		switch(rel_op){
		case 0:
			cfa.append_ics(*(new Compute_IC_Stmt(sle_d, o1, o2, result)));
		case 1:
			cfa.append_ics(*(new Compute_IC_Stmt(slt_d, o1, o2, result)));
		case 2:
			cfa.append_ics(*(new Compute_IC_Stmt(sgt_d, o1, o2, result)));
		case 3:
			cfa.append_ics(*(new Compute_IC_Stmt(sge_d, o1, o2, result)));
		case 4:
			cfa.append_ics(*(new Compute_IC_Stmt(seq_d, o1, o2, result)));
		case 5:
			cfa.append_ics(*(new Compute_IC_Stmt(sne_d, o1, o2, result)));
		default:
			printf("wrong operator in compile of Relational_Expr_Ast\n");
			break;
		}
	}

	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}


// Logical Expr Ast

Code_For_Ast & Logical_Expr_Ast::compile(){
	Code_For_Ast & lhscfa = lhs_op->compile();
	Code_For_Ast & rhscfa = rhs_op->compile();

	Code_For_Ast & cfa = *(new Code_For_Ast());
	Register_Descriptor * r;

	list<Icode_Stmt *> & lhsstmts = lhscfa.get_icode_list();
	list<Icode_Stmt *> & rhsstmts = rhscfa.get_icode_list();
	
	for(list<Icode_Stmt *>::iterator it = rhsstmts.begin(); it != rhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	for(list<Icode_Stmt *>::iterator it = lhsstmts.begin(); it != lhsstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	r = machine_desc_object.get_new_register<int_reg>();
	Ics_Opd * o1 = new Register_Addr_Opd(lhscfa.get_reg());
	Ics_Opd * o2 = new Register_Addr_Opd(rhscfa.get_reg());
	Ics_Opd * result = new Register_Addr_Opd(r);
	switch(bool_op){
	case 0:
		cfa.append_ics(*(new Compute_IC_Stmt(not_t, o1, o2, result)));
	case 1:
		cfa.append_ics(*(new Compute_IC_Stmt(or_t, o1, o2, result)));
	case 2:
		cfa.append_ics(*(new Compute_IC_Stmt(and_t, o1, o2, result)));
	default:
		printf("wrong operator in compile of Logical_Expr_Ast\n");
		break;
	}

	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}


// Selection Statement Ast

Code_For_Ast&Selection_Statement_Ast::compile(){
	Code_For_Ast & condcfa = cond->compile();
	Code_For_Ast & thencfa = then_part->compile();
	Code_For_Ast & elsecfa = else_part->compile();
	Code_For_Ast & cfa = *(new Code_For_Ast());
	Register_Descriptor * r;

	list<Icode_Stmt *> & condstmts = condcfa.get_icode_list();	
	list<Icode_Stmt *> & thenstmts = thencfa.get_icode_list();
	list<Icode_Stmt *> & elsestmts = elsecfa.get_icode_list();
	
	for(list<Icode_Stmt *>::iterator it = condstmts.begin(); it != condstmts.end(); ++it){
		cfa.append_ics(**it);
	}
	
	Ics_Opd * o3 = new Register_Addr_Opd(condcfa.get_reg());
	string lbl1 = get_new_label();
	cfa.append_ics(*(new Control_Flow_IC_Stmt(beq, o3, lbl1)));

	for(list<Icode_Stmt *>::iterator it = thenstmts.begin(); it != thenstmts.end(); ++it){
		cfa.append_ics(**it);
	}

	Ics_Opd * zr = new Register_Addr_Opd(machine_desc_object.spim_register_table[zero]);
	if(else_part != NULL){
		string lbl2 = get_new_label();
		cfa.append_ics(*(new Control_Flow_IC_Stmt(j, zr, lbl2)));
	}

	cfa.append_ics(*(new Label_IC_Stmt(label, lbl1)));

	for(list<Icode_Stmt *>::iterator it = elsestmts.begin(); it != elsestmts.end(); ++it){
		cfa.append_ics(**it);
	}

	cfa.append_ics(*(new Label_IC_Stmt(label, lbl2)));

	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}


// Iteration Statement Ast
Code_For_Ast&Iteration_Statement_Ast::compile(){
	Code_For_Ast &condcfa = cond->compile();
	Code_For_Ast &bodycfa = body->compile();

	Code_For_Ast &cfa = *(new Code_For_Ast());
	Register_Descriptor *r;
	Ics_Opd *zr = new Register_Addr_Opd(machine_desc_object.spim_register_table[zero]);
	list<Icode_Stmt *> &condstmts = condcfa.get_icode_list();
	list<Icode_Stmt *> &bodystmts = bodycfa.get_icode_list();

	string lbl1 = get_new_label();
	string lbl2 = get_new_label();

	if (is_do_form)
	{
		cfa.append_ics(*(new Control_Flow_IC_Stmt(j, zr, lbl2)));
	}
	cfa.append_ics(*(new Label_IC_Stmt(label, lbl1)));

	for (list<Icode_Stmt *>::iterator it = bodystmts.begin(); it != bodystmts.end(); ++it)
	{
		cfa.append_ics(**it);
	}

	cfa.append_ics(*(new Label_IC_Stmt(label, lbl2)));

	for (list<Icode_Stmt *>::iterator it = condstmts.begin(); it != condstmts.end(); ++it)
	{
		cfa.append_ics(**it);
	}

	Ics_Opd *o3 = new Register_Addr_Opd(condcfa.get_reg());
	cfa.append_ics(*(new Control_Flow_IC_Stmt(bne, o3, lbl1)));

	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}

// Sequence Ast
Code_For_Ast&Sequence_Ast::compile(){
	Code_For_Ast & cfa = *(new Code_For_Ast());
	Register_Descriptor * r;

	for(list<Ast *>::iterator it = statement_list.begin(); it != statement_list.end(); ++it){
		Code_For_Ast & bodycfa = (*it)->compile();
		list<Icode_Stmt *> & bodystmts = bodycfa.get_icode_list();

		for(list<Icode_Stmt *>::iterator itr = bodystmts.begin(); itr != bodystmts.end(); ++itr){
			cfa.append_ics(**itr);
		}
	}

	cfa.set_reg(r);

	return cfa;
	// ToDo free the lhs register
}

