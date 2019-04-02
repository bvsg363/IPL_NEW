#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>

#include "icode.hh"
#include "symbol-table.hh"
#include "reg-alloc.hh"
using namespace std;

template class Const_Opd<double>;
template class Const_Opd<int>;


///////////////////////// Instruction Descriptor ///////////////////////////////////
Instruction_Descriptor::Instruction_Descriptor(Tgt_Op op, string desc_name, string mnn, string ics, Icode_Format icf, Assembly_Format af) {
	inst_op = op;
	name = desc_name;
	mnemonic = mnn;
	ic_symbol = ics;
	ic_format = icf;
	assem_format = af;
}

Instruction_Descriptor::Instruction_Descriptor(){}

Tgt_Op Instruction_Descriptor::get_op(){
	return inst_op;
}
string Instruction_Descriptor::get_name(){
	return name;
}
string Instruction_Descriptor::get_mnemonic(){
	return mnemonic;
}
string Instruction_Descriptor::get_ic_symbol(){
	return ic_symbol;
}
Icode_Format Instruction_Descriptor::get_ic_format(){
	return ic_format;
}
Assembly_Format Instruction_Descriptor::get_assembly_format(){
	return assem_format;
}

void Instruction_Descriptor::print_instruction_descriptor(ostream &file_buffer){
	file_buffer << "\n";
}


///////////////////////////// Icode statement operand ///////////////////////////////////
Register_Descriptor* Ics_Opd::get_reg(){}

void Ics_Opd::print_ics_opd(ostream &file_buffer){}
void Ics_Opd::print_asm_opd(ostream &file_buffer){}


/////// Mem_Addr_Opd
Mem_Addr_Opd::Mem_Addr_Opd(Symbol_Table_Entry &se){
	symbol_entry = &se;
}

void Mem_Addr_Opd::print_ics_opd(ostream &file_buffer){
	file_buffer << symbol_entry->get_variable_name();
}
void Mem_Addr_Opd::print_asm_opd(ostream &file_buffer){}
Mem_Addr_Opd & Mem_Addr_Opd::operator=(const Mem_Addr_Opd &rhs){}


/////// Register_Addr_Opd
Register_Addr_Opd::Register_Addr_Opd(Register_Descriptor *rd){
	register_description = rd;
}

Register_Descriptor* Register_Addr_Opd::get_reg(){
	return register_description;
}
void Register_Addr_Opd::print_ics_opd(ostream &file_buffer){
	file_buffer << register_description->get_name();
}
void Register_Addr_Opd::print_asm_opd(ostream &file_buffer){}

Register_Addr_Opd & Register_Addr_Opd::operator=(const Register_Addr_Opd &rhs){}


////// Const_Opd
template <class T>
Const_Opd<T>::Const_Opd(T t_num){
	num = t_num;
}

template <class T>
void Const_Opd<T>::print_ics_opd(ostream &file_buffer){
	file_buffer << num;
}

template <class T>
void Const_Opd<T>::print_asm_opd(ostream &file_buffer){
}

template <class T>
Const_Opd<T> &Const_Opd<T>::operator=(const Const_Opd &rhs){
}


///////////////////////////////// Intermediate code statements //////////////////////////
Instruction_Descriptor & Icode_Stmt::get_op(){
	return op_desc;
}
Ics_Opd * Icode_Stmt::get_opd1(){}
Ics_Opd * Icode_Stmt::get_opd2(){}
Ics_Opd * Icode_Stmt::get_result(){}

void Icode_Stmt::set_opd1(Ics_Opd * io){}
void Icode_Stmt::set_opd2(Ics_Opd * io){}
void Icode_Stmt::set_result(Ics_Opd * io){}

void Icode_Stmt::print_icode(ostream & file_buffer){}
void Icode_Stmt::print_assembly(ostream & file_buffer){}


///////// Move_IC_Stmt
Move_IC_Stmt::Move_IC_Stmt(Tgt_Op inst, Ics_Opd *opd_1, Ics_Opd *result_opd){
	op_desc = Instruction_Descriptor(inst, "", "", "", i_op_r_o1, a_op_r_o1);
	opd1 = opd_1;
	result = result_opd;
}
Move_IC_Stmt &Move_IC_Stmt::operator=(const Move_IC_Stmt &rhs){}

Instruction_Descriptor &Move_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}

Ics_Opd *Move_IC_Stmt::get_opd1(){
	return opd1;
}
void Move_IC_Stmt::set_opd1(Ics_Opd *io){
	opd1 = io;
}

Ics_Opd *Move_IC_Stmt::get_result(){
	return result;
}
void Move_IC_Stmt::set_result(Ics_Opd *io){
	result = io;
}

void Move_IC_Stmt::print_icode(ostream &file_buffer){
	// file_buffer << op_desc->print_instruction_descriptor(file_buffer) << ":" << "\t\t" << result->print_ics_opd(file_buffer) << " <- " << opd1->print_ics_opd(file_buffer);
}
void Move_IC_Stmt::print_assembly(ostream &file_buffer){}


/////// Compute_IC_Stmt
Compute_IC_Stmt::Compute_IC_Stmt(Tgt_Op inst, Ics_Opd *opd_1, Ics_Opd *opd_2, Ics_Opd *result_opd){
	// inst_op = inst;
	opd1 = opd_1;
	opd2 = opd_2;
	result = result_opd;
}
Compute_IC_Stmt &Compute_IC_Stmt::operator=(const Compute_IC_Stmt &rhs){}

Instruction_Descriptor &Compute_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}

Ics_Opd *Compute_IC_Stmt::get_opd1(){
	return opd1;
}
void Compute_IC_Stmt::set_opd1(Ics_Opd *io){
	opd1 = io;
}

Ics_Opd *Compute_IC_Stmt::get_opd2(){
	return opd2;
}
void Compute_IC_Stmt::set_opd2(Ics_Opd *io){
	opd2 = io;
}

Ics_Opd *Compute_IC_Stmt::get_result(){
	return result;
}
void Compute_IC_Stmt::set_result(Ics_Opd *io){
	result = io;
}

void Compute_IC_Stmt::print_icode(ostream &file_buffer){}
void Compute_IC_Stmt::print_assembly(ostream &file_buffer){}


///// Control_Flow_IC_Stmt
Control_Flow_IC_Stmt::Control_Flow_IC_Stmt(Tgt_Op inst, Ics_Opd *opd_1, string label_given){
	// inst_op = inst;
	opd1 = opd_1;
	label = label_given;
}
Control_Flow_IC_Stmt &Control_Flow_IC_Stmt::operator=(const Control_Flow_IC_Stmt &rhs){}

Instruction_Descriptor &Control_Flow_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}

Ics_Opd *Control_Flow_IC_Stmt::get_opd1(){
	return opd1;
}
void Control_Flow_IC_Stmt::set_opd1(Ics_Opd *io){
	opd1 = io;
}

string Control_Flow_IC_Stmt::get_label(){
	return label;
}
void Control_Flow_IC_Stmt::set_label(string label_given){
	label = label_given;
}

void Control_Flow_IC_Stmt::print_icode(ostream &file_buffer){}
void Control_Flow_IC_Stmt::print_assembly(ostream &file_buffer){}


/////// Label_IC_Stmt
Label_IC_Stmt::Label_IC_Stmt(Tgt_Op inst, string label_given){
	// inst_op = inst;
	label = label_given;
}
Label_IC_Stmt &Label_IC_Stmt::operator=(const Label_IC_Stmt &rhs){}

Instruction_Descriptor &Label_IC_Stmt::get_inst_op_of_ics(){}

string Label_IC_Stmt::get_label(){
	return label;
}
void Label_IC_Stmt::set_label(string label_given){
	label = label_given;
}

void Label_IC_Stmt::print_icode(ostream &file_buffer){}
void Label_IC_Stmt::print_assembly(ostream &file_buffer){}


//////////////////////// Intermediate code for Ast statements ////////////////////////
Code_For_Ast::Code_For_Ast(){}
Code_For_Ast::Code_For_Ast(list<Icode_Stmt *> &ic_l, Register_Descriptor *reg){
	ics_list = ic_l;
	result_register = reg;
}

void Code_For_Ast::append_ics(Icode_Stmt &ics){
	ics_list.push_back(&ics);
}
list<Icode_Stmt *> &Code_For_Ast::get_icode_list(){
	return ics_list;
}

Register_Descriptor *Code_For_Ast::get_reg(){
	return result_register;
}
void Code_For_Ast::set_reg(Register_Descriptor *reg){
	result_register = reg;
}

Code_For_Ast &Code_For_Ast::operator=(const Code_For_Ast &rhs){}