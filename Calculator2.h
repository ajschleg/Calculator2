//
// Created by flynn on 4/12/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_CALCULATOR2_H
#define CS36300_SPRING2018_CALCULATOR1_CALCULATOR2_H

#include <iostream>
#include <sstream>
#include <map>
#include "Expr_Builder.h"
#include "Expr_Tree_Builder.h"

/*Calculator2 is what the client interacts with when using the calculator*/
class Calculator2 {
public:
    Calculator2(){}
    ~Calculator2(){}

    /*The parser is the "Director" for the builder pattern.*/
    bool parse_expr (const std::string & infix );

private:
    Expr_Tree_Builder builder_;
    Expr_Tree *tree_, *another_one_;
};


#endif //CS36300_SPRING2018_CALCULATOR1_CALCULATOR2_H
