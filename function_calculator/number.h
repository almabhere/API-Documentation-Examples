/*  Copyright May 2025.
All Rights Reserved.*/

#ifndef NUMBER_H
#define NUMBER_H

#include <string>

namespace FunctionalCalculator
{

/** \class Number is the Base class from which numbers should derive.  */
class Number
{
public:
  /** A class should have this virtual function implemented in order to derive from the Number class. This method returns a complex number as a pair of double-precision real numbers a + bi.  */
  virtual std::pair<double, double> get() const;
  /** A class should have this virtual function implemented in order to derive from the Number class. This method prints the number as a string, with an optional parameter that indicates whether the number should be enclosed in parentheses. By default this parameter is off.  */
  virtual std::string print(bool useParentheses = false) const;
};
}

#endif //def NUMBER_H
