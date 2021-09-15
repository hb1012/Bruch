//
// Created by hbill on 06.03.2020.
//
#ifndef BRUCH_BRUCH_H
#define BRUCH_BRUCH_H

class Bruch {
private:
    int m_Z = 0;
    unsigned int m_N = 1;

    void kuerzen();
public:
    // Getter
    [[nodiscard("Getter Zähler")]] int zaehler() const;
    [[nodiscard("Getter Nenner")]] unsigned int nenner() const;

    // Constructor
    Bruch();
    Bruch(int zaehler, unsigned int nenner);
    explicit Bruch(int nenner);

    // Copy Constructor
    Bruch(const Bruch& other);

    // Move Constructor
    Bruch(Bruch&& other) noexcept;

    // Destructor
    ~Bruch();

    // Copy Assignment Operator
    Bruch& operator=(const Bruch& other);

    // Move Assignment Operator
    Bruch &operator=(Bruch&& other) noexcept;

    // Infix Operator +
    Bruch operator+(const Bruch& other) const;

    // Infix Operator -
    Bruch operator-(const Bruch& other) const;

    // Infix Operator *
    Bruch operator*(const Bruch& other) const;

    // Infix Operator /
    Bruch operator/(const Bruch& other) const;

    Bruch& operator+=(const Bruch& other);

    bool operator==(const Bruch& other) const;

    bool operator!=(const Bruch& other) const;

    bool operator>(const Bruch& other) const;

    bool operator<(const Bruch& other) const;

    // print Bruch
    friend std::ostream& operator<<(std::ostream& stream, const Bruch& bruch);
};

/*
 * *** Auxilliary Functions ***
 */
// Greatest Common Divisor (GCD)
int gcd(int a, unsigned int b);

unsigned int lcm(unsigned int a, unsigned int b);
#endif //BRUCH_BRUCH_H
