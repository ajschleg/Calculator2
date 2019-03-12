//
// Created by flynn on 4/12/18.
//


/*Dont do eval on the input tree
 * create a copy of the tree or something.*/
#include "Eval_Expr_Tree.h"
#include "Nodes.h"
Eval_Expr_Tree::Eval_Expr_Tree() :
        result_(0),
        temp_(0)
{

}

Eval_Expr_Tree::~Eval_Expr_Tree()
{

}


void Eval_Expr_Tree::Visit_Number_Node( Number_Node &node) {
    this->result_ = node.eval();
}

void Eval_Expr_Tree::Visit_Add_Node(const Add_Node &node) {
    /*get left and right child then add them together*/
    this->result_ = node.left_->eval() + node.right_->eval();
}

void Eval_Expr_Tree::Visit_Subtract_Node(const Subtract_Node &node) {
    this->result_ = node.left_->eval() - node.right_->eval();
}

void Eval_Expr_Tree::Visit_Multiply_Node(const Multiply_Node &node) {
    this->result_ = node.left_->eval() * node.right_->eval();
}

void Eval_Expr_Tree::Visit_Divide_Node(const Divide_Node &node) {
    int left = node.left_->eval();
    int right = node.right_->eval();
    if(right == 0){
        std::cout<<"ERROR: Cannot divide by zero\n";
    }
    this->result_ = left / right;
}

void Eval_Expr_Tree::Visit_Mod_Node(const Mod_Node &node) {
    int right = node.right_->eval();
    int left = node.left_->eval();
    if(right == 0){
        std::cout<<"ERROR: Cannot Mod by zero\n";
    }
    int i = left / right;
    int j = i * right;
    this->result_ = left - j;
}

void Eval_Expr_Tree::Visit_Variable_Node( Variable_Node &node) {
    this->result_ = node.eval();
}