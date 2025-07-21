/*  Copyright May 2025.
All Rights Reserved.*/

#ifndef MP_INTEGER_H
#define MP_INTEGER_H

#include <map>
#include <ostream>
#include <vector>

namespace FunctionalCalculator
{
/** \class mp is a multiple-precision integer. A multiple-precision integer is useful for avoiding overflow when the integer gets too large and can display numbers that are much larger than typical integers.
 */
class mp
{
  /** \brief Integers in the vector are stored in reverse place-value as a_0 + a_1 * b + ... + a_p * b^p. The integers are always nonnegative. Self is a private member.
   */
  std::vector<int> self;
  /** Negative is a boolean. Booleans can be true or false. Negative is true if and only if the mp is negative. Self is a private member.
   */
  bool negative = false;
  /** This is a private method. It simplifies the mp after additions, subtractions, and multiplications. */
  void clean();
  /** digPow = 6. It is a static private member. */
  const static int digPow;
  /** Limit is the upper bound that integers within self can attain. Limit equals 10 raised to the power digPow. It equals 100,000. */
  const static int limit;

  mp division(const mp& rhs, mp& remainder) const;

public:
  /** This is the default constructor. It initializes the mp to a given integer value, which is 0 by default. */
  mp(int value = 0);
  /** This is a constructor. It initializes the mp to a given value. */
  mp(const long long& value);

  /** This method returns the i'th decimal digit of the mp number. The method throws an exception if i is negative. */
  int getDigit(int i) const;
  /** This method sets the i'th decimal digit of the mp number to a given value. It throws an exception if the value of i is negative. The digit "value" must be between 0 and 9, inclusive, or else the method throws an exception. */
  void setDigit(int i, int val);
  /** This method returns the number of decimal digits in the mp number. */
  int numDigits() const;
  /** This method returns the mp number as a plain integer. It does not signal an exception if the mp number is larger than the limit above. Rather, it returns the remainder upon division by limit. */
  int toInt() const;
  /** This returns the greatest common divisor of two mp numbers aa and bb. */
  static mp gcd(const mp& aa, const mp& bb);
  /** This method returns the greatest common divisor of a collection of mp numbers.  */
  static mp gcd(const std::vector<mp>& arguments);
  /** This method returns { a, b } where a is the maximal number such that this integer == a * a * b.  */
  std::pair<mp, mp> separateSquaredPart() const;

  /**  This method returns the number unchanged. */
  mp operator+() const;
  /** This method returns the negative of the current number.  */
  mp operator-() const;
  /** This mehtod returns the sum of the current number and rhs.  */
  mp operator+(const mp& rhs) const;
  /** This method returns the difference of the current number and rhs. That is, rhs subtracted from the current number. */
  mp operator-(const mp& rhs) const;
  /** This method returns the product of the current number and rhs.  */
  mp operator*(const mp& rhs) const;
  /** This method returns the quotient of the current number and rhs. That is, the current number divided by rhs. This is integer division, so it does not return any remaining decimal part. Throws an exception of rhs is zero. */
  mp operator/(const mp& rhs) const;
  /** This method returns the remainder of the division that takes place when you divide this number by rhs. It throws an exception if rhs is zero. */
  mp operator%(const mp& rhs) const;
  /** This method returns the absolute value of the mp.*/
  mp abs() const;
  /** This method returns the current number raised to the p'th power. The power p must be nonnegative or else the method throws an exception. */
  mp pow(int p) const;
  /** This method returns true if the current number equals rhs, and it is false otherwise. */
  bool operator==(const mp& rhs) const;
  /** This method returns true if and only if the two numbers are not equal. */
  bool operator!=(const mp& rhs) const;
  /** This method returns whether the current number is less than the righthand side. The existence of this method allows mp instances to be keys for maps. */
  bool operator<(const mp& rhs) const;
  /** This method returns whether the current number is greater than rhs. */
  bool operator>(const mp& rhs) const;
  /** This method returns whether the current number is less than or equal to rhs. */
  bool operator<=(const mp& rhs) const;
  /** This method returns whether the current number is greater than or equal to rhs. */
  bool operator>=(const mp& rhs) const;

  /** This method returns the binomial coefficient, "n choose k". This is the number of ways k items can be chosen from n total. It is used to count combinations. If n is less than or equal to 0, this method returns 0. If k is less than or equal to 0 or greater than n, this method returns 0. For integers k between 0 and n, this equals n! / ((n - k)! * k!) */
  static mp binomialCoeff(int n, int k);
  /** This returns the prime factorization of the number as a map. The keys are the prime factors. The value of a key is the number of occurrences of that prime factor. */
  std::map<mp, int> primeFactorization() const;

  friend std::ostream& operator<<(std::ostream& strm, const mp& mpIn);
};

/** This prints the current number to an output stream. */
std::ostream& operator<<(std::ostream& strm, const mp& mpIn);

}

#endif //def MP_INTEGER_H
