//
// Created by hbill on 06.03.2020.
//
#include <iostream>
#include <ostream>
#include "Bruch.h"

void Bruch::kuerzen() {
  unsigned int tmp(gcd(m_Z, m_N));
  m_Z /= tmp;
  m_N /= tmp;
}

int Bruch::zaehler() const { return m_Z; }
unsigned int Bruch::nenner() const { return m_N; }

// default Constructor
// Bruch::Bruch() : m_Z(0), m_N(1) {
Bruch::Bruch() = default;
//    std::cout << "default Constructor" << std::endl;

// Constructor mit Argumenten
Bruch::Bruch(int zaehler, unsigned int nenner) : m_Z(zaehler), m_N(nenner) {
//    std::cout << "Constructor mit Argumenten" << std::endl;
}

// delegating Constructor
Bruch::Bruch(int nenner) : Bruch(1, nenner) {
//    std::cout << "delegating Constructor" << std::endl;
}

// Copy Constructor
Bruch::Bruch(const Bruch& other) : m_Z(other.m_Z), m_N(other.m_N) {
//    std::cout << "Copy Constructor" << std::endl;
}

// Move Constructor
Bruch::Bruch(Bruch&& other) noexcept : m_Z(other.m_Z), m_N(other.m_N) {
//    std::cout << "Move Constructor" << std::endl;

    other.m_Z = 0;
    other.m_N = 0;
}

// Destructor
Bruch::~Bruch() = default;
    //std::cout << "destructed" << std::endl;
//}

// Copy Assignment Operator
Bruch& Bruch::operator=(const Bruch& other) {
//    std::cout << "Copy Assignmet" << std::endl;

    if (this == &other) {
        return *this;
    }

    m_Z = other.m_Z;
    m_N = other.m_N;

    return *this;
}

// Move Assignment Operator
Bruch &Bruch::operator=(Bruch&& other) noexcept {
//    std::cout << "Move Assignmet" << std::endl;

    if (this == &other) {
        return *this;
    }

    m_Z = other.m_Z;
    m_N = other.m_N;

    other.m_Z = 0;
    other.m_N = 0;

    return *this;
}

// Infix Operator +
Bruch Bruch::operator+(const Bruch& other) const {
    int Z = m_Z * other.m_N + m_N * other.m_Z;
    unsigned int N = m_N * other.m_N;
    return {Z / gcd(Z, N), N / gcd(Z, N)};
}

// Infix Operator -
Bruch Bruch::operator-(const Bruch& other) const {
    int Z = m_Z * other.m_N - m_N * other.m_Z;
    unsigned int N = m_N * other.m_N;
    return {Z / gcd(Z, N), N / gcd(Z, N)};
}

// Infix Operator *
Bruch Bruch::operator*(const Bruch& other) const {
    int Z = m_Z * other.m_Z;
    unsigned int N = m_N * other.m_N;
    return {Z / gcd(Z, N), N / gcd(Z, N)};
}

// Infix Operator /
Bruch Bruch::operator/(const Bruch& other) const {
    int Z = m_Z * other.m_N;
    unsigned int N = m_N * other.m_Z;
    return {Z / gcd(Z, N), N / gcd(Z, N)};
}

Bruch& Bruch::operator+=(const Bruch& other) {
    int Z = this->m_Z * other.m_N + this->m_N * other.m_Z;
    unsigned int N = this->m_N * other.m_N;
    this->m_Z = Z / gcd(Z, N);
    this->m_N = N / gcd(Z, N);
    return *this;
}

bool Bruch::operator==(const Bruch& other) const {
    return (m_Z * other.m_N == m_N * other.m_Z);
}

bool Bruch::operator!=(const Bruch& other) const {
    return (m_Z * other.m_N != m_N * other.m_Z);
}

bool Bruch::operator>(const Bruch& other) const {
    return (m_Z * other.m_N > m_N * other.m_Z) && *this != other;
}

bool Bruch::operator<(const Bruch& other) const {
    return (m_Z * other.m_N < m_N * other.m_Z) && *this != other;
}

// print Bruch
std::ostream& operator<<(std::ostream& stream, const Bruch& bruch) {
    if (bruch.m_Z == 0) {
        stream << "0";
    }
    else if (bruch.m_Z == bruch.m_N) {
        stream << "1";
    }
    else if (bruch.m_N == 1) {
        stream << bruch.m_Z;
    }
    else {
        stream << bruch.m_Z << " / " << bruch.m_N;
    }
    return stream;
}

/*
 * *** Auxilliary Functions ***
 */
// greatest common divisor (gcd) = ggT
int gcd(int a, unsigned int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// least common multiple (lcm) = kgV
unsigned int lcm(unsigned int a, unsigned int b) {
    return (a * b) / gcd(a, b);
}
