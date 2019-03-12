//
// Created by flynn on 4/11/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_EXPR_NODE_VISITOR_H
#define CS36300_SPRING2018_CALCULATOR1_EXPR_NODE_VISITOR_H


//Forward declarations
class Number_Node;
class Add_Node;
class Subtract_Node;
class Multiply_Node;
class Divide_Node;
class Mod_Node;
class Variable_Node;

/*Expr_Node_Visitor is an interface that visits all concrete nodes in the Expression tree*/
class Expr_Node_Visitor {
public:
    virtual ~Expr_Node_Visitor(){}

    /*Methods for Visiting concrete nodes.
     * Concrete visitors only overload desired methods.*/
    virtual void Visit_Number_Node (Number_Node & node){}
    virtual void Visit_Add_Node(const Add_Node & node){}
    virtual void Visit_Subtract_Node (const Subtract_Node & node){}
    virtual void Visit_Multiply_Node (const Multiply_Node & node){}
    virtual void Visit_Divide_Node (const Divide_Node & node){}
    virtual void Visit_Mod_Node (const Mod_Node & node){}
    virtual void Visit_Variable_Node (Variable_Node & node){}
};


#endif //CS36300_SPRING2018_CALCULATOR1_EXPR_NODE_VISITOR_H
