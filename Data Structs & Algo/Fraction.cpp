
#include "Fraction.h"
#include <iostream>
/*
 * This file contains deals with fractions
 * and performs multiple operations on fractions
 */

// This takes a fraction and checks the divisor
// if the divisor is zero, it throws and displays a message
// It sets the values
// After that, it attempts to reduce the fraction
// This reducing is done through a private method
Fraction::Fraction(long numerator, long denominator) {
    try
    {
        if (denominator==0)
        {
            throw "Error";
        }
    }
    catch (const char Error) {
        std::cout<<"Invalid Division By Zero "<<std::endl;
    }
    this->numerator=numerator;
    this->denominator=denominator;
    reducedFraction(this->numerator,this->denominator);
}

// returns numerator
long Fraction::getNumerator() const {
    return numerator;
}

// returns denominator
long Fraction::getDenominator() const {
    return denominator;
}

// checks if fraction can be reduced
// attempts to reduce the fraction
// returns a negative or positive fraction
void Fraction::reducedFraction(long &numerator,long &denominator) {
    // check for divisibility
    if (denominator==1 || numerator==1)
    {
        return;
    }

    // All values should be positive abs() for division otherwise
    // They modify the original sign

    // stores the number before modulus (modulusNumber mod x)
    long modulusNumber = abs(numerator);
    // stores the number after modulus (x mod numberModulus)
    long numberModulus = abs(denominator);
    // stores the past number before modulus (prev_modulusNumber mod x)
    long prev_modulusNumber = abs(numerator);

    // checks for modulus
    while (modulusNumber%numberModulus!=0)
    {
        // sets new value to mod
        modulusNumber=numberModulus;
        // sets modded value
        numberModulus=prev_modulusNumber%numberModulus;
        // sets new value to mod
        prev_modulusNumber=modulusNumber;
    }
    // divides by the modded value
    numerator/=numberModulus;
    denominator/=numberModulus;

    // flips sign if both numerator and denominator
    // are negative
    if (numerator<0 && denominator<0)
    {
        numerator*=-1;
        denominator*=-1;
        return;
    }

    // if denominator is negative
    // denominator makes numerator negative
    // denominator becomes positive
    if (denominator<0)
    {
        numerator*=-1;
        denominator*=-1;
        return;
    }
    return;
}

// Adds two fractions
Fraction Fraction::operator+(const Fraction &Fraction2) {
    // Initializes a new object
    Fraction Result(this->numerator,this->denominator);
    // Does cross addition
    Result.numerator = this->numerator * Fraction2.denominator;
    Result.numerator += Fraction2.numerator*this->denominator;
    // Finds common denominator
    Result.denominator *= Fraction2.denominator;
    // Reduces the new fraction
    reducedFraction(Result.numerator,Result.denominator);
    return Result;
}

// Adds an integer to the fraction
Fraction Fraction::operator+(const long number) {
    Fraction Result(number,1);
    // Performs same steps as adding with another object
    Result.numerator = Result.numerator*this->denominator;
    Result.numerator += this->numerator*Result.denominator;
    Result.denominator=this->denominator;
    reducedFraction(Result.numerator,Result.denominator);
    return Result;
}

// Subtracts two fractions
Fraction Fraction::operator-(const Fraction &Fraction2) {
    Fraction Result(this->numerator,this->denominator);
    // Performs same steps as adding, but subtracts numerator
    Result.numerator=this->numerator*Fraction2.denominator;
    Result.numerator-=Fraction2.numerator*this->denominator;
    Result.denominator*=Fraction2.denominator;
    reducedFraction(Result.numerator,Result.denominator);
    return Result;
}

// Subtracts an integer from a fraction
Fraction Fraction::operator-(const long number) {
    // Performs same step as subtracting from an object
    Fraction Result(number,1);
    Result.numerator=this->numerator;
    Result.numerator-=number*this->denominator;
    Result.denominator=this->denominator;
    reducedFraction(Result.numerator,Result.denominator);
    return Result;
}

// Multiplies two fractions
Fraction Fraction::operator*(const Fraction &Fraction2) {
    // Multiplies two fractions directly
    Fraction Result(this->numerator,this->denominator);
    Result.numerator*=Fraction2.numerator;
    Result.denominator*=Fraction2.denominator;
    reducedFraction(Result.numerator,Result.denominator);
    return Result;
}

// Multiplies an integer with a fraction
Fraction Fraction::operator*(const long number) {
    Fraction Result(number,1);
    Result.numerator*=this->numerator;
    Result.denominator=this->denominator;
    reducedFraction(Result.numerator,Result.denominator);
    return Result;
}

// Divides two fractions
Fraction Fraction::operator/(const Fraction &Fraction2) {
    Fraction Result(this->numerator,this->denominator);
    // Same as direct multiplication by flipping second fraction
    Result.numerator*=Fraction2.denominator;
    Result.denominator*=Fraction2.numerator;
    reducedFraction(Result.numerator,Result.denominator);
    return Result;
}

// Divides a fraction with an integer
Fraction Fraction::operator/(const long number) {
    // Flips the fraction while initalization
    Fraction Result(1,number);
    // Returns the multiplication of the reciprocal
    Result.numerator*=this->numerator;
    Result.denominator*=this->denominator;
    reducedFraction(Result.numerator,Result.denominator);
    return Result;
}

// Checks equivalency of two fractions
bool Fraction::operator==(const Fraction &Fraction2) {
    // Takes the numerator with common denominator in mind
    long numerator1=this->numerator*Fraction2.denominator;
    long numerator2=Fraction2.numerator*this->denominator;
    if (numerator1==numerator2)
    {
        return true;
    }
    return false;
}

// Checks non-equivalency of two fractions
bool Fraction::operator!=(const Fraction &Fraction2) {
    // Same as ==
    return !(operator==(Fraction2));
}

// Check if current fraction is bigger than another
bool Fraction::operator>(const Fraction &Fraction2) {
    // Takes numerator with common denominator
    long numerator1=this->numerator*Fraction2.denominator;
    long numerator2=Fraction2.numerator*this->denominator;
    if (numerator1>numerator2)
    {
        return true;
    }
    return false;
}

// Checks if current fraction is less than another
bool Fraction::operator<(const Fraction &Fraction2) {
    // Takes numerator with common denominator
    long numerator1=this->numerator*Fraction2.denominator;
    long numerator2=Fraction2.numerator*this->denominator;
    if (numerator1<numerator2)
    {
        return true;
    }
    return false;
}

// Checks if the fraction is equivalent or more than another
bool Fraction::operator>=(const Fraction &Fraction2) {
    if (operator==(Fraction2) || operator>(Fraction2))
    {
        return true;
    }
    return false;
}

// Checks if fraction is less than or equal than another
bool Fraction::operator<=(const Fraction &Fraction2) {
    if (operator==(Fraction2) || operator<(Fraction2))
    {
        return true;
    }
    return false;
}


