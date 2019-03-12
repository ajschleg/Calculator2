
#include "Base_Array.h"
#include "Array.h"
#include "Stack.h"
#include "auto_ptr.h"
#include "Array_Iterator.h"
#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
#include <map>
#include "Calculator2.h"




int main(void)
{
    std::string infix;
  /*  std::map<char, int> mymap;
    int num;
    char var;
    std::cin>>var;

    *//*for variable
     * Need to store var char and then ask user to input number*//*
    mymap[var];
    std::cin>>num;

    // show content:
    for (auto it=mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';*/


    while(1) {

            std::cout << "Please enter your expression: ";
            std::getline(std::cin, infix);
            if(infix == "Quit" || infix == "quit" || infix == "QUIT")
                return 0;


            Calculator2 calculator2;
            calculator2.parse_expr(infix);


    }
    return 0;
}

