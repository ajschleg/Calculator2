//
// Created by flynn on 4/22/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_VARIABLE_NODE_H
#define CS36300_SPRING2018_CALCULATOR1_VARIABLE_NODE_H


#include "Expr_Node.h"
#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <sstream>

class Variable_Node : public Expr_Node {
public:
    explicit Variable_Node(std::string c, std::map<std::string, int> &map) :
            variable(c),
            vars_map(map),
            prec(5),
            number(0)
    {
        vars_map.insert(std::make_pair(this->variable, 0));
    }

    virtual void accept (Expr_Node_Visitor & v) {
        //v.visit variable node
        v.Visit_Variable_Node(*this);
    }

    int getPrec () const {
        return prec;
    }

    virtual int eval(){
//        find variable
//        get number for var
        std::string var_number;
        std::cout << this->variable<<" = ";
        getline(std::cin, var_number);
        this->number = std::stoi(var_number);
        //        find variable
//        set variable iterator
        std::map<std::string, int>::iterator thisVar = vars_map.find(this->variable);
        thisVar->second = this->number;
        return this->number;
    }

    std::string getVar(){
        return this->variable;
    }

    virtual Expr_Node*& getLeft() {}
    virtual Expr_Node*& getRight() {}
    virtual void setLeft(Expr_Node &node) {}
    virtual void setRight(Expr_Node &node) {}

private:
    std::string variable;
    std::map<std::string, int> &vars_map;
    int prec;
    int number;
};


#endif //CS36300_SPRING2018_CALCULATOR1_VARIABLE_NODE_H
