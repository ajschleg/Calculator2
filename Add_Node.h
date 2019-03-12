//
// Created by flynn on 4/11/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_ADD_NODE_H
#define CS36300_SPRING2018_CALCULATOR1_ADD_NODE_H

#include "Binary_Expr_Node.h"


/*Add_Node inherits from Binary_Expr_Node*/
class Add_Node : public Binary_Expr_Node {
public:
    explicit Add_Node() : prec(1){}

    virtual void accept (Expr_Node_Visitor & v){
        v.Visit_Add_Node(*this);
    }


    virtual int eval(){
        return (this->left_->eval() + this->right_->eval());
    }

    virtual int getPrec() const { return this->prec;}

private:
    int prec;
};


#endif //CS36300_SPRING2018_CALCULATOR1_ADD_NODE_Hcd
