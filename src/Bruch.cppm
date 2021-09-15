//
// Created by hbill on 06.03.2020.
//
import std.core;

export module Bruch;

export class Bruch {
private:
    int m_Z;
    int m_N;

public:
    // Constructor
    Bruch();
    Bruch(int zaehler, int nenner);

    // Copy Constructor
    Bruch(const Bruch& other);

    // Destructor
    ~Bruch();

    // Copy Assignment Operator
    Bruch& operator=(const Bruch& other);

    // Infix Operator +
    Bruch operator+(const Bruch &other);

    // Infix Operator -
    Bruch operator-(const Bruch &other);

    // Infix Operator *
    Bruch operator*(const Bruch &other);

    // Infix Operator /
    Bruch operator/(const Bruch &other);

    Bruch& operator+=(const Bruch& rhs);

    // print Bruch
    friend std::ostream& operator<<(std::ostream &stream, const Bruch &bruch);
};

/*
 * *** Auxilliary Functions ***
 */
// Greatest Common Divisor (GCD)
export int gcd(int a, int b);
