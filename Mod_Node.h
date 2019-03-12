//
// Created by flynn on 4/20/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_MOD_NODE_H
#define CS36300_SPRING2018_CALCULATOR1_MOD_NODE_H


#include "Binary_Expr_Node.h"

class Mod_Node : public Binary_Expr_Node{
public:
    explicit Mod_Node() :
            prec(2){}

    virtual void accept (Expr_Node_Visitor & v){
        v.Visit_Mod_Node(*this);
    }


    virtual int eval(){
        int right = this->right_->eval();
        int left = this->left_->eval();
        if(right == 0){
            std::cout<<"ERROR: Cannot mod by zero\n";
            return 0;
        }

        int i = left / right;
        int j = i * right;
        return (left - j);
    }

    virtual int getPrec() const { return this->prec;}

private:
    int prec;

};


#endif //CS36300_SPRING2018_CALCULATOR1_MOD_NODE_H
