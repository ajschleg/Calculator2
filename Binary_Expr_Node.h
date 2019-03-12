
#ifndef CS36300_SPRING2018_CALCULATOR1_BINARY_EXPR_NODE_H
#define CS36300_SPRING2018_CALCULATOR1_BINARY_EXPR_NODE_H

#include "Expr_Node.h"

/*Binary_Expr_Node inherits from Expr_Node.
 * It has 2 children of type Expr_Node.*/
class Binary_Expr_Node : public Expr_Node {
public:
    friend class Expr_Tree;
    friend class Eval_Expr_Tree;
    friend class Print_Inorder_Expression;

    Binary_Expr_Node() :
            left_(0),
            right_(0)
    {}
    Binary_Expr_Node(Expr_Node *left, Expr_Node *right) : left_(left), right_(right){}

    virtual Expr_Node*& getLeft(){return this->left_;}
    virtual Expr_Node*& getRight(){ return this->right_;}
    virtual void setLeft(Expr_Node &node) {this->left_ = &node;}
    virtual void setRight(Expr_Node &node) {this->right_ = &node;}

    virtual int eval(){}

    virtual int getPrec() const = 0;

protected:
    Expr_Node *left_;
    Expr_Node *right_;
};


#endif //CS36300_SPRING2018_CALCULATOR1_BINARY_EXPR_NODE_H
