// -*- C++ -*-
// $Id: Stack.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_STACK_H_
#define _CS507_STACK_H_

#include <cstring>
#include <iostream>
#include "Array.h"
#include "empty_exception.h"


/**
 * @class Stack
 *
 * Basic stack for abitrary elements.
 */
template <typename T>
class Stack
{
public:
  /// Type definition of the type.
  typedef T type;



  /// Default constructor.
  Stack (void);

  /// Copy constructor.
  Stack (const Stack & s);

  /// Destructor.
  ~Stack (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Stack & operator = (const Stack & rhs);

  /**
   * Push a new \a element onto the stack. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void push (T element);

  /**
   * Remove the top-most element from the stack.
   *
   * @exception      empty_exception    The stack is empty.
   */
  void pop (void);

  /**
   * Get the top-most element on the stack. If there are no element 
   * on the stack, then the stack_is_empty exception is thrown.
   *
   * @return         Element on top of the stack.
   * @exception      empty_exception    The stack is empty
   */
  T top (void) const;

  /**
   * Test if the stack is empty
   *
   * @retval         true          The stack is empty
   * @retval         false         The stack is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the stack.
   *
   * @return         Size of the stack.
   */
  size_t size (void) const;

    //get top of stack
  size_t top_ofStk(void) const;

  /// Remove all elements from the stack.
  void clear (void);

    //print stack
  void print();

private:
  // add member variable here
    size_t top_ofStack_;
    size_t size_ofStack_;
  
  // COMMENT You are required to use the Array class.
    //This has been changed from Array<int> *items. but before it was causing most compile errors received
    Array<T> items; //the stack has an array
    //Array<T> *array;
};

// include the inline files
#include "Stack.inl"

// include the source file since template class
#include "Stack.cpp"

#endif  // !defined _CS507_STACK_H_
