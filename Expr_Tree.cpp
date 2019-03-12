//
// Created by flynn on 4/21/18.
//

#include "Expr_Tree.h"

const Expr_Tree &Expr_Tree::operator=(const Expr_Tree &rhs) {
    if(this == &rhs)
        return *this;

    delete this->root_;

    this->root_ = rhs.root_;

    return *this;
}