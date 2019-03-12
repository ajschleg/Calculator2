//
// Created by flynn on 4/12/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_EXPR_TREE_BUILDER_H
#define CS36300_SPRING2018_CALCULATOR1_EXPR_TREE_BUILDER_H

#include "Expr_Builder.h"
#include "Expr_Tree.h"
#include "Nodes.h"
#include "Stack.h"


/*Expr_Tree_Builder builds an expr tree for use in calculator2.*/
class Expr_Tree_Builder : public Expr_Builder {
public:
    Expr_Tree_Builder();
    virtual ~Expr_Tree_Builder();

    virtual void start_expression (void) {
        // ...
        this->tree_ = new Expr_Tree ();
    }
    virtual void build_number (int n);
    virtual void build_var(std::string c);
    virtual void build_add_operator (void);
    virtual void build_subtract_operator (void);
    virtual void build_multiply_operator (void);
    virtual void build_divide_operator (void);
    virtual void build_mod_operator (void);
    virtual void build_open_parenthesis (void);
    virtual void build_close_parenthesis (void);

    void build_tree(Expr_Node &node, Expr_Node *&t);
    // ...
    Expr_Tree * get_expression (void) {
        return this->tree_; }
private:
    // current state of expression tree
    Expr_Tree * tree_;
    // other variables to coordinate build process
//    temporary tree for parenthesis use
    Expr_Tree * temptree_;


//    Internal method to put () root into tree_
    void insert_parenthesis(Expr_Node *&t);



};




#endif //CS36300_SPRING2018_CALCULATOR1_EXPR_TREE_BUILDER_H
