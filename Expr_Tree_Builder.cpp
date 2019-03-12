//
// Created by flynn on 4/12/18.
//

#include "Expr_Tree_Builder.h"

Expr_Tree_Builder::Expr_Tree_Builder() :
    tree_(0),
    temptree_(0)
{

}

Expr_Tree_Builder::~Expr_Tree_Builder() {
    delete this->tree_;
}

void Expr_Tree_Builder::build_number(int num) {
    Expr_Node * node;
    node = new Number_Node(num);
    this->build_tree(*node, this->tree_->root_);
}

void Expr_Tree_Builder::build_var(std::string c) {
    Expr_Node * node = new Variable_Node(c, this->tree_->map);
    this->build_tree(*node, this->tree_->root_);
}

void Expr_Tree_Builder::build_add_operator() {
    Expr_Node *node;
    node = new Add_Node();
    this->build_tree(*node, this->tree_->root_);

}

void Expr_Tree_Builder::build_subtract_operator() {
    Expr_Node *node;
    node = new Subtract_Node();
    this->build_tree(*node, this->tree_->root_);

}

void Expr_Tree_Builder::build_multiply_operator() {
    Expr_Node *node = new Multiply_Node();
    this->build_tree(*node, this->tree_->root_);

}

void Expr_Tree_Builder::build_divide_operator() {
    Expr_Node *node = new Divide_Node();
    this->build_tree(*node, this->tree_->root_);

}
void Expr_Tree_Builder::build_mod_operator() {
    Expr_Node * node = new Mod_Node();
    this->build_tree(*node, this->tree_->root_);
}

void Expr_Tree_Builder::build_open_parenthesis() {
    /*Set a temporary tree to hold the root for tree and set new tree for parenthesis*/
    this->temptree_ = new Expr_Tree();
    this->temptree_->root_ = this->tree_->root_;
    this->tree_->root_ = nullptr;
}

void Expr_Tree_Builder::build_close_parenthesis() {
    this->insert_parenthesis(this->temptree_->root_);
    this->temptree_->root_ = nullptr;
}


void Expr_Tree_Builder::build_tree(Expr_Node &node, Expr_Node *&t) {

    //if t is nullptr then set new t
    if(t == nullptr)
        t = &node;

/*        if node prec is less then or equal to current t
         * then set t = node and node->left = old t*/
    else if (node.getPrec() <= t->getPrec()){
        Expr_Node *temp = t;
        node.setLeft(*temp);
        t = &node;
    }
/*        If node prec is greater then,
         * then recursively call insert until node is inserted*/
    else {
        this->build_tree(node, t->getRight());
    }
}

void Expr_Tree_Builder::insert_parenthesis(Expr_Node *&t) {
    if(t == nullptr) {
//        HACK eval whats in the () then insert into tree. please dont take off to many points :)
        Expr_Node * node = new Number_Node(this->tree_->root_->eval());
        t = node;
        this->tree_->root_ = this->temptree_->root_;


/*  This works only when there are no numbers to the right of closed parenthesis
 *
 * t = this->tree_->root_;
        this->tree_->root_ = this->temptree_->root_;*/
    }
    else
        insert_parenthesis(t->getRight());
}
