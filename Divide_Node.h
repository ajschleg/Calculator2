//
// Created by flynn on 4/11/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_DIVIDE_NODE_H
#define CS36300_SPRING2018_CALCULATOR1_DIVIDE_NODE_H

#include "Binary_Expr_Node.h"


/*Divide Command*/
class Divide_Node : public Binary_Expr_Node {
public:
    explicit Divide_Node () : prec(2){}

    virtual void accept (Expr_Node_Visitor & v) {
        v.Visit_Divide_Node(*this);
    }


    virtual int eval(){
        int right = this->right_->eval();
        int left = this->left_->eval();
        if(right == 0){
            std::cout<<"ERROR: Cannot divide by zero\n";
            return 0;
        }
        return (left / right);
    }

    virtual int getPrec() const { return this->prec;}
private:
    int prec;

};


#endif //CS36300_SPRING2018_CALCULATOR1_DIVIDE_NODE_H
