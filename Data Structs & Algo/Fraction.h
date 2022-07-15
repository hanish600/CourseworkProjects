
#ifndef CS301_HW05_FRACTIONS__FRACTION_H
#define CS301_HW05_FRACTIONS__FRACTION_H

/*
 * This class contains methods
 * for dealing with fractions
*/

class Fraction {
public:
    Fraction(long numerator, long denominator);
    long getNumerator() const;
    long getDenominator() const;
    // Overloaded operators
    // These do operations on fractions
    Fraction operator+(const Fraction &Fraction2);
    Fraction operator+(long number);
    Fraction operator-(const Fraction &Fraction2);
    Fraction operator-(long number);
    Fraction operator*(const Fraction &Fraction2);
    Fraction operator*(long number);
    Fraction operator/(const Fraction &Fraction2);
    Fraction operator/(long number);

    // Overloaded assignment operators
    // These compare two fractions
    bool operator==(const Fraction &Fraction2);
    bool operator!=(const Fraction &Fraction2);
    bool operator>(const Fraction &Fraction2);
    bool operator<(const Fraction &Fraction2);
    bool operator>=(const Fraction &Fraction2);
    bool operator<=(const Fraction &Fraction2);


private:
    long numerator;
    long denominator;
    // Hidden method for reducing/simplifying fractions
    void reducedFraction(long &numerator,long &denominator);
};


#endif //CS301_HW05_FRACTIONS__FRACTION_H
