//
// Created by flynn on 4/12/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_EXPR_BUILDER_H
#define CS36300_SPRING2018_CALCULATOR1_EXPR_BUILDER_H

#include "Expr_Tree.h"
#include "Expr_Node.h"
#include "Nodes.h"

/*Expr_Builder uses the Builder Pattern.
 * Each method is responsible for building some part of the expression tree without requiring the client or director to
 * understand the internal representation of the final expression. */
class Expr_Builder {
public:
    // ...
    virtual void start_expression (void){};
    virtual void build_number (int n) = 0;
    virtual void build_add_operator (void) = 0;
    virtual void build_subtract_operator (void) = 0;
    virtual void build_multiply_operator (void) = 0;
    virtual void build_divide_operator (void) = 0;
    // ...
    virtual void build_open_parenthesis (void) = 0;
    virtual void build_close_parenthesis (void) = 0;
    // get the current expression
    virtual Expr_Tree * get_expression (void) = 0;
};


#endif //CS36300_SPRING2018_CALCULATOR1_EXPR_BUILDER_H
