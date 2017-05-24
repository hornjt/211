//
//  main.cpp
//  finalExamPractice
//
//  Created by Jon Horn on 5/23/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Rat {
public:
    int numerator, denominator;
    Rat() {
        numerator = 0;
        denominator = 1;
    }
    Rat(int i) {
        denominator = i;
        numerator = 1;
    }
    Rat(int n, int d) {
        Rat rat;
        numerator = n;
        denominator = d;
    }
    
    void setNumerator(int n) {
        numerator = n;
    }
    void setDenominator(int d) {
        denominator = d;
    }
    
    Rat operator+(Rat r) {
        Rat newRat;
        newRat.numerator = numerator * r.denominator + denominator * r.numerator;
        newRat.denominator = denominator * r.denominator;
        newRat.reduce();
        return newRat;
    }
    Rat operator-(Rat r) {
        Rat newRat;
        newRat.numerator = numerator * r.denominator - denominator * r.numerator;
        newRat.denominator = denominator * r.denominator;
        return newRat;
        return newRat;
    }
    Rat operator*(Rat r) {
        Rat newRat;
        newRat.numerator = numerator * r.numerator;
        newRat.denominator = denominator * r.denominator;
        return newRat;
    }
    Rat operator/(Rat r) {
        Rat newRat;
        newRat.numerator = numerator * r.denominator;
        newRat.denominator = denominator * r.numerator;
        return newRat;
    }
    
    void reduce() {
        int test = denominator % numerator;
        
            for (int i = numerator; i > 1; i--) {
                if (denominator % i == 0 && numerator % i == 0) {
                    numerator /= i;
                    denominator /= i;
                }
            }
        
    }
    
    // 2 overloaded i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
};

ostream& operator<<(ostream& os, Rat r){
    os<<r.numerator<<" / "<<r.denominator<<endl;
    return os;}
// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its provate parts.
istream& operator>>(istream& is, Rat& r){
    is>>r.numerator>>r.denominator;
    return is;
}

void f(int n){
    int a=0;
    int b=1;
    while (a < n){
        cout<<a<<endl;
        a=b;
        b=a+b;
    }
};

void iSquared(int n) {
    if (n == 50)
        return;
    else {
        cout<<"i= "<<n<<endl;
        int a=0;
        int b=1;
        while (a < n){
            cout<<a<<endl;
            a=b;
            b=a+b;
        }
        cout << endl;
        iSquared(n + 1);
    }
}

int removeFirst(int n) {
    if (n < 10)
        return n;
    else {
        return removeFirst(n / 10);
    }
    
}

void s(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void r(int x[], int from, int to) {
    if (from >= to) return;
    s(x, from, to);
    r(x, from + 1, to - 1);
}

vector<int> merge( vector<int> a, vector<int> b) {
    vector<int> mergedVec;
    int i = 0;
    while (a.size() != 0 || b.size() != 0) {
        if (a.size() == 0 || b[0] < a[0]) {
            mergedVec.push_back(b[0]);
            b.erase(b.begin());
        }
        else {
            mergedVec.push_back(a[0]);
            a.erase(a.begin());
        }
    }
    return mergedVec;
}



int main(int argc, const char * argv[]) {
    vector<int> a = {2,4,6,8};
    vector<int> b = {1,3,7,10,13};
    vector<int> merged = merge(a, b);
    for (auto a : merged)
        cout << a << " ";
}





























