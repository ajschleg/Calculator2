//
// Created by flynn on 4/12/18.
//
#include "Calculator2.h"

bool Calculator2::parse_expr(const std::string &infix) {
    std::istringstream input (infix); // create a input stream parser
    std::string token;                // current token in string/stream
    builder_.start_expression ();            // start a new expression

    while (!input.eof ()) {
        input >> token;
        if (token == "+")
            this->builder_.build_add_operator ();
        else if (token == "-")
            this->builder_.build_subtract_operator ();
        else if (token == "*")
            this->builder_.build_multiply_operator ();
        else if (token == "/")
            this->builder_.build_divide_operator();
        else if (token == "%")
            this->builder_.build_mod_operator();
        else if (token == "(" || token == "[")
            this->builder_.build_open_parenthesis();
        else if (token == ")" || token == "]")
            this->builder_.build_close_parenthesis();
        else if (token[0] >= 65)
            this->builder_.build_var(token);
        else {
            int num = std::stoi(token);
            this->builder_.build_number(num);
        }
    }



    /*Get the parsed tree*/
    this->tree_ = builder_.get_expression();
    this->tree_->evaluate();
    this->tree_->print();

    return true;
}

