//
//  main.cpp
//  Complex
//
//  Created by Jon Horn on 5/23/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include <iostream>
using namespace std;

class Complex {
public:
    
    int a, bi;
    Complex() {
        a = 0;
        bi = 0;
    }
    Complex(int someR, int someI) {
        a = someR;
        bi = someI;
    }
    
    Complex operator+(Complex newRat) {
        Complex c;
        c.a = a + newRat.a;
        c.bi = bi + newRat.bi;
        return newRat;
    }
    Complex operator-(Complex newRat) {
        Complex c;
        c.a = a - newRat.a;
        c.bi = bi - newRat.bi;
        return newRat;
    }
    Complex operator*(Complex newRat) {
        Complex c;
        c.a = a * newRat.a;
        c.bi = bi * newRat.bi;
        return newRat;
    }
    
    friend ostream& operator<<(ostream& os, Complex c);
    friend ostream& operator>>(ostream& os, Complex c);
};

ostream& operator<<(ostream& os, Complex c) {
    os << c.a << " + " << c.bi << "i";
    return os;
}


class Stack {
private:
    int top; // top is the index into the array for the current top
    int * p; // p is a pointer into the heap where the stack is actually
    //located. Just like for SA class.
    int size; // size of the array allocated for the stack
public:
    // a stack to hold 100
    Stack() {
        top = 0;
        size = 99;
        p = new int(size);
    }
    // a stack to hold n elements
    Stack(int n) {
        top = 0;
        size = n;
        p = new int(size);
    }
    ~Stack() {
        delete [] p;
    }
    bool empty() {
        if (p[0] == 0) {
            return true;
        }
        return false;
    }
    // don’t forget to test if stack is full
    void push(int a)  {
        if (top == 100) {
            cout << "Stack is full";
            return;
        }
        p[++top] = a;
        
    }
    // don’t forget to test if the stack is empty
    int pop() {
        int temp = 0;
        if (top != 0) {
            temp = p[top];
            p[top--] = NULL;
            return temp;
        }
        return 0;
    }
    int getSize() {
        return size;
    }
};




int main(int argc, const char * argv[]) {
//    Complex c = Complex(2, 3);
//    Complex d = Complex(1, 4);
//    cout << c + d;
    Stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    for (int i=0; i<3; i++)
        cout<<s.pop(); // should print 3,2 1
    cout << "";
    return 0;
    
}
