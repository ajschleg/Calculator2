
#ifndef CS36300_SPRING2018_CALCULATOR1_UNARY_EXPR_NODE_H
#define CS36300_SPRING2018_CALCULATOR1_UNARY_EXPR_NODE_H

#include "Expr_Node.h"


/*Unary_Expr_Node inherits from Expr_Node and uses composite pattern
 * ie it has a child of type Expr_Node
 * Unary_Expr_Node only has 1 child of type Expr_Node*/
class Unary_Expr_Node : public Expr_Node {
public:
    Unary_Expr_Node() : child_(0){}
    virtual ~Unary_Expr_Node(void);
    virtual int eval(){
        if(this->child_)
            return this->child_->eval();
    }

    virtual Expr_Node* getLeft(){return this->child_;}
    virtual Expr_Node* getRight(){ return nullptr;}
    virtual void setLeft(Expr_Node &node) {this->child_ = &node;}
    virtual void setRight(Expr_Node &node) {}

protected:
    Expr_Node * child_;
    int prec;
};



#endif //CS36300_SPRING2018_CALCULATOR1_UNARY_EXPR_NODE_H
