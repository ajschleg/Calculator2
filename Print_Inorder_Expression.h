//
// Created by flynn on 4/11/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_PRINT_INORDER_EXPRESSION_H
#define CS36300_SPRING2018_CALCULATOR1_PRINT_INORDER_EXPRESSION_H

#include <iostream>
#include "Expr_Node_Visitor.h"
/*Print_Inorder_Expression visitor prints the expression as an infix expression to the specified output*/
class Print_Inorder_Expression : public Expr_Node_Visitor {
public:
    explicit Print_Inorder_Expression (){}
    virtual ~Print_Inorder_Expression() {}

    /*Methods for visiting concrete nodes*/
    virtual void Visit_Number_Node ( Number_Node & node);
    virtual void Visit_Add_Node (const Add_Node & node);
    virtual void Visit_Subtract_Node (const Subtract_Node & node);
    virtual void Visit_Multiply_Node (const Multiply_Node & node);
    virtual void Visit_Divide_Node (const Divide_Node & node);
    virtual void Visit_Mod_Node(const Mod_Node & node);
    virtual void Visit_Variable_Node ( Variable_Node & node);


private:
    /*Output stream*/
    //ERROR instantiating an unknown structure without a reference
//    std::ostream out_;

};


#endif //CS36300_SPRING2018_CALCULATOR1_PRINT_INORDER_EXPRESSION_H
