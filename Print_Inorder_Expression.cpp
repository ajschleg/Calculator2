//
// Created by flynn on 4/23/18.
//
#include <iostream>
#include "Print_Inorder_Expression.h"
#include "Nodes.h"

void Print_Inorder_Expression::Visit_Number_Node(Number_Node &node) {
    int num = node.eval();
    std::cout<<num;
}

void Print_Inorder_Expression::Visit_Variable_Node(Variable_Node &node) {
    std::string string = node.getVar();
    std::cout<<string;
}

void Print_Inorder_Expression::Visit_Add_Node(const Add_Node &node) {
    node.left_->accept(*this);
    std::cout<<" + ";
    node.right_->accept(*this);
}

void Print_Inorder_Expression::Visit_Subtract_Node(const Subtract_Node &node) {
    node.left_->accept(*this);
    std::cout<<" - ";
    node.right_->accept(*this);}

void Print_Inorder_Expression::Visit_Multiply_Node(const Multiply_Node &node) {
    node.left_->accept(*this);
    std::cout<<" * ";
    node.right_->accept(*this);}

void Print_Inorder_Expression::Visit_Divide_Node(const Divide_Node &node) {
    node.left_->accept(*this);
    std::cout<<" / ";
    node.right_->accept(*this);}

void Print_Inorder_Expression::Visit_Mod_Node(const Mod_Node &node) {
    node.left_->accept(*this);
    std::cout<<" % ";
    node.right_->accept(*this);}