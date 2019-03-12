cmake_minimum_required(VERSION 3.9)
project(cs36300_spring2018_calculator2)

set(CMAKE_CXX_STANDARD 11)

add_executable(cs36300_spring2018_calculator2
        Base_Array.h
        Base_Array.inl
        Array.h
        Array.inl
        Stack.h
        Stack.inl
        driver.cpp
        auto_ptr.h
        array_auto_ptr.h
        Array_Iterator.h
        Expr_Node.h
        Binary_Expr_Node.h
        Unary_Expr_Node.h
        Number_Node.h
        Expr_Node_Visitor.h
        Eval_Expr_Tree.h
        Print_Inorder_Expression.h
        Add_Node.h
        Subtract_Node.h
        Multiply_Node.h
        Divide_Node.h
        Nodes.h
        Expr_Builder.h
        Calculator2.cpp
        Calculator2.h
        Expr_Tree_Builder.cpp
        Expr_Tree_Builder.h
        Expr_Tree.h
        Eval_Expr_Tree.cpp
        Mod_Node.h
        Expr_Tree.cpp
        Variable_Node.h Print_Inorder_Expression.cpp)