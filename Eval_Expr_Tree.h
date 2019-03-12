//
// Created by flynn on 4/11/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_EVAL_EXPR_TREE_H
#define CS36300_SPRING2018_CALCULATOR1_EVAL_EXPR_TREE_H

#include "Expr_Node_Visitor.h"

/*Eval_Expr_Tree evaluates the expression tree by visiting elements post-order traversal logic*/
class Eval_Expr_Tree : public Expr_Node_Visitor {
public:
    explicit Eval_Expr_Tree();

    ~Eval_Expr_Tree();

    /*Methods for visiting concrete nodes.
     * Each Visit method contains logic for visiting a concrete node.*/
    virtual void Visit_Number_Node ( Number_Node & node);
    virtual void Visit_Add_Node (const Add_Node & node);
    virtual void Visit_Subtract_Node (const Subtract_Node & node);
    virtual void Visit_Multiply_Node (const Multiply_Node & node);
    virtual void Visit_Divide_Node (const Divide_Node & node);
    virtual void Visit_Mod_Node (const Mod_Node & node);
    virtual void Visit_Variable_Node ( Variable_Node & node);

    int getResult_() const {
        return this->result_;
    }

private:
    /*Cumulative state for calculating the result*/
    int result_;
    /*Temp var for numbers*/
    int temp_;

};


#endif //CS36300_SPRING2018_CALCULATOR1_EVAL_EXPR_TREE_H
