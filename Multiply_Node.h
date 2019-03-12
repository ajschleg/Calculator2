//
// Created by flynn on 4/11/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_MULTIPLY_NODE_H
#define CS36300_SPRING2018_CALCULATOR1_MULTIPLY_NODE_H

#include "Binary_Expr_Node.h"


/*Multiply Node*/
class Multiply_Node : public Binary_Expr_Node {
public:
    explicit Multiply_Node () : prec(2){}

    virtual void accept (Expr_Node_Visitor & v){
        v.Visit_Multiply_Node(*this);
    }


    virtual int eval(){
        return (this->left_->eval() * this->right_->eval());
    }

    virtual int getPrec() const { return this->prec;}

private:
    int prec;
};


#endif //CS36300_SPRING2018_CALCULATOR1_MULTIPLY_NODE_H
