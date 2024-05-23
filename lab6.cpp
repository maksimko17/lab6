#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    Complex(const Complex& other) : real(other.real), imag(other.imag) {}

    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << " + " << c.imag << "i)";
        return os;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3;

    c3 = c1 + c2;
    std::cout << "Sum: " << c3 << std::endl;

    c3 = c1 - c2;
    std::cout << "Difference: " << c3 << std::endl;

    c3 = c1 * c2;
    std::cout << "Product: " << c3 << std::endl;

    c3 = c1 / c2;
    std::cout << "Quotient: " << c3 << std::endl;

    Complex c4(c1);
    std::cout << "Copy: " << c4 << std::endl;

    if (c1 == c4) {
        std::cout << "c1 and c4 are equal" << std::endl;
    }

    return 0;
}
