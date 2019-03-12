//
// Created by flynn on 4/11/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_EXPR_NODE_H
#define CS36300_SPRING2018_CALCULATOR1_EXPR_NODE_H

//ERROR Including visitor header file also includes children of Expr Node. Working on a solution
//Solution: forward declare nodes in visitor
#include <iostream>
#include "Expr_Node_Visitor.h"
//class Expr_Node_Visitor;

/*Expr_Node is the base class for all node types in the expression tree
 * Expr_Node uses the composite pattern.
 * Expr_Node uses the template method to provide common functionality to all subclasses.*/
class Expr_Node {
public:
    //friends

    Expr_Node(void){}
    virtual ~Expr_Node(void){}

/*
    Used to traverse the tree.
    evaluate() is an "operation" that evaluates each node in the tree (ie the composite)
*/
    virtual int eval(void) = 0;

    /*Accepts only takes Expr Node Visitor*/
    virtual void accept (Expr_Node_Visitor & v) = 0;

    virtual int getPrec () const = 0;

    virtual Expr_Node *& getLeft()= 0;
    virtual Expr_Node *& getRight() = 0;
    virtual void setLeft(Expr_Node &node) = 0;
    virtual void setRight(Expr_Node &node) = 0;

};





#endif //CS36300_SPRING2018_CALCULATOR1_EXPR_NODE_H
