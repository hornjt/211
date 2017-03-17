<<<<<<< HEAD
//
//  integration.cpp
//  hw10
//  CS 211 - 52B
//
//  Created by Jon Horn on 3/16/17.

#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

double square(double x){
    return x * x;
}

double line(double x){
    return x;
}

double cube(double x) {
    return x * x * x;
}

double integrate(FUNC f, double a, double b) {
    double integratedValue = 0.0;
    for (double i = a; i <= b ; i = (i + .0001)) {
        integratedValue += (f(i) * .0001);
    }
    return integratedValue;
}

int main() {
    cout << "The integral of f(x)=x between 1 and 5 is: " <<integrate(line, 1, 5) << endl;
    cout<< "The integral of f(x)=x^2 between 1 and 5 is: " <<integrate(square, 1, 5) << endl;
    cout << "The integral of f(x)=x^3 between 1 and 5 is: " <<integrate(cube, 1, 5) << endl;
    
}
