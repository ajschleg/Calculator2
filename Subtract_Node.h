//
// Created by flynn on 4/11/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_SUBTRACT_NODE_H
#define CS36300_SPRING2018_CALCULATOR1_SUBTRACT_NODE_H




/*Subtract Node
 * This returns a negative number*/
class Subtract_Node : public Binary_Expr_Node {
public:
    explicit Subtract_Node() : prec(1){}

    virtual void accept (Expr_Node_Visitor & v) {
        v.Visit_Subtract_Node(*this);
    }


    virtual int eval(){
        /*Check if this should be left or right*/
        return (this->left_->eval() - this->right_->eval());
    }

    virtual int getPrec() const {
        return prec;
    }

private:
    int prec;


};


#endif //CS36300_SPRING2018_CALCULATOR1_SUBTRACT_NODE_H
