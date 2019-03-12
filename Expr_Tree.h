//
// Created by flynn on 4/12/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_EXPR_TREE_H
#define CS36300_SPRING2018_CALCULATOR1_EXPR_TREE_H

#include <iostream>
#include <sstream>
#include <map>
#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"
#include "Print_Inorder_Expression.h"

class Expr_Tree {
public:
    /*Friend with Builder*/
    friend class Expr_Tree_Builder;

    Expr_Tree() :
            root_(nullptr)
    {}

    Expr_Tree(Expr_Tree &tree) :
            root_(tree.root_)
    {}

    ~Expr_Tree() {
        delete this->root_;
    }


    /*Evaluate the tree using visitor*/
    int evaluate(){
        this->root_->accept(this->eval_expr_tree_);
        std::cout<<"Answer: "<<this->eval_expr_tree_.getResult_()<<std::endl;
    }

    void print(){
        this->root_->accept(this->print_inorder_expression);
        std::cout<<std::endl;
    }

    /*Need a copy constructor for this because it returns by value*/
    const Expr_Tree&operator = (const Expr_Tree & tree);

private:
    Expr_Node * root_;
    Eval_Expr_Tree eval_expr_tree_;
    Print_Inorder_Expression print_inorder_expression;

    //    map for variable
    std::map<std::string, int> map;
};


#endif //CS36300_SPRING2018_CALCULATOR1_EXPR_TREE_H
