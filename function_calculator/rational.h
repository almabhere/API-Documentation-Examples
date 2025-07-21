/*  Copyright August 2024.
All Rights Reserved.*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include "mp_integer.h"
#include "number.h"

#include <map>
#include <set>

namespace FunctionalCalculator
{
  bool parenthesesWellFormed(const std::string& str, const std::pair<char, char>& leftRight = { '(', ')' });
  void trimParentheses(std::string& str, const std::pair<char, char>& leftRight = { '(', ')' });

/** \class This class represents Rational numbers. These are fractions where the numerator (top) is an mp integer and the denominator (bottom) is an mp integer. The denominator cannot be zero. */
class Rational : public Number
{
  /** This mp integer is the numerator of the rational number. It is zero by default. Along with the denom, these are simplified to the lowest terms. */
  mp num = 0;
  /** This mp integer is the denominator of the rational number. It is 1 by default. It cannot be zero. Along with num, these are simplified to lowest terms. */
  mp denom = 1;
public:
  /** This constructor takes an integer numerator nn and an integer denominator dd and sets the rational number to nn / dd. By default nn is 0 and dd is 1. Thus the default constructor sets the rational number to zero. This constructor throws an exception if dd is zero. */
  Rational(int nn = 0, int dd = 1);
  /** This constructor takes an mp integer numerator nn and an mp integer denominator dd and sets the rational number to nn / dd. This constructor throws an exception if dd is zero. */
  Rational(const mp& nn, const mp& dd);

  /** This is the copy constructor. That is, it constructs a rational number as a copy of an existing rational number. */
  Rational(const Rational&);
  /** This is the move constructor. That is, it efficiently constructs a rational number from an existing rational number, with no guarantee on the contents of the previous rational number. It does not throw an exception. */
  Rational(Rational&&) noexcept;
  /** This method overloads the = operator as a copy operation. */
  Rational& operator=(const Rational&);
  /** This method overloads the = operator as a move operation. */
  Rational& operator=(Rational&&) noexcept;
  /** This is the virtual destructor for the Rational number. It is implemented as the default destructor. */
  virtual ~Rational() = default;

  /** This method returns the denominator (bottom) of the rational number in simplest terms. */
  mp denominator() const;
  /** This method returns the numerator (top) of the rational number in simplest terms. */
  mp numerator() const;
  /** This method returns the pair of rational numbers { a, b } where a is the maximal number such that this number equals a * a * b. */
  std::pair<Rational, Rational> separateSquaredPart() const;
  /** This returns the current rational number. */
  Rational operator+() const;
  /** This returns the negative of the current rational number. */
  Rational operator-() const;
  /** This returns the sum of the current rational number and rhs. */
  Rational operator+(const Rational& rhs) const;
  /**  This returns the difference of the current rational number and rhs. */
  Rational operator-(const Rational& rhs) const;
  /** This returns the product of the current rational number and rhs. */
  Rational operator*(const Rational& rhs) const;
  /** This returns the quotient of the current rational number and rhs. The method throws an exception if rhs == 0. */
  Rational operator/(const Rational& rhs) const;
  /** This returns the p'th power of the rational number. The exponent p is allowed to be negative. */
  Rational pow(int p) const;
  /** This returns true if and only if rhs equals the current number. */
  bool operator==(const Rational& rhs) const;
  /** This returns true if and only if rhs does not equal the current number. */
  bool operator!=(const Rational& rhs) const;
  /** This returns true if and only if the current number is less than rhs. */
  bool operator<(const Rational& rhs) const;
  /** This returns true if and only if the current number is greater than rhs. */
  bool operator>(const Rational& rhs) const;
  /** This returns true if and only if the current number is less than or equal to rhs. */
  bool operator<=(const Rational& rhs) const;
  /** This returns true if and only if the current number is greater than or equal to rhs. */
  bool operator>=(const Rational& rhs) const;
  /** This returns the prime factorization of the number as a map. The keys of the map are the prime factors. The value for a given key is the number of times it appears in the prime factorization (its exponent). */
  std::map<mp, int> primeFactorization() const;
  /** This method prints the prime factorization of the rational number. There is an optional parameter to enclose the prime factorization in parentheses, which is off by default. */
  std::string printFactors(bool useParentheses = false) const;

  /** This overrides the get() method in the base Number class. The first element in the pair attempts to evaluate the rational number as a double. The second element in the pair is set to zero, since the rational number is real. */
  virtual std::pair<double, double> get() const override;
  /** This method returns true if and only if the rational number is actually an mp integer. This is the same as saying that the denominator (in simplest terms) is one. */
  bool isInt() const;
  /** This method overrides the print() method in the base Number class. The method prints the number as a string, with an optional parameter indicating whether the number should be enclosed in parentheses. By default this parameter is off. */
  virtual std::string print(bool useParentheses = false) const override;
};
}

#endif //def RATIONAL_H
