//
// Created by flynn on 4/11/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_NUMBER_EXPR_NODE_H
#define CS36300_SPRING2018_CALCULATOR1_NUMBER_EXPR_NODE_H

#include "Expr_Node.h"



/*Number_Node inherits from Expr_Command.
 * Number_Node does not have any children because it is a leaf node.
 * Number_Node contains a number.*/
class Number_Node : public Expr_Node {
public:
    explicit Number_Node(int num) :
            number(num),
            prec(5) {}

    void accept (Expr_Node_Visitor & v){
        v.Visit_Number_Node(*this);
    }

    int getPrec () const {
        return prec;
    }

    virtual int eval(){
        return (this->number);
    }

    virtual Expr_Node*& getLeft(){ }
    virtual Expr_Node*& getRight(){ }
    virtual void setLeft(Expr_Node &node) {}
    virtual void setRight(Expr_Node &node) {}

private:
    int number;
    int prec;
};






#endif //CS36300_SPRING2018_CALCULATOR1_NUMBER_EXPR_NODE_H
