//
//  main.cpp
//  4.5 to 4.9
//
//  Created by Alex Christopher on 6/12/20.
//  Copyright © 2020 Alex Christopher. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cstddef>
#include "string.h"

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector; using std::begin; using std::end;

int main() {
    // 4.5
    int i = 0, j;
    j = ++i; // j = 1, i = 1: prefix yields the incremented value
    j = i++; // j = 1, i = 2: postfix yeilds the unincremented value
    
    // Combining Dereference and Increment in a Single Expression
    vector<int> v{1, 2, 3, 4, 5, 6, 7, -7, 8, 9};
    auto pbeg = v.begin();
    // print elements up to first negative value
    while (pbeg != v.end() && *pbeg >= 0){
        cout << *pbeg++ << endl; // print the current value and advance pbeg
    }
    
    // Operands can be remembered in any order
    string s = "this is a test.";
    cout << s << endl;
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it){
        *it = toupper(*it); // capitalize the current character
    }
    cout << s << endl;
    
    // 4.6 The Member Access Operator
    string s1 = "a string", *p = &s1;
    auto n = s1.size(); // run the size member of the string s1
    n = (*p).size(); // run size on the object to which p points
    n = p -> size(); // equivalent to (*p).size()
    
    // 4.7
        // COND ? EXPR1 : EXPR2
    int grade = 91;
    string finalGrade = (grade < 60) ? "fail" : "pass";
    cout << finalGrade << endl;
    
    // Nesting Conditional Operations
    finalGrade = (grade > 90) ? "High pass" : (grade < 60) ? "fail" : "pass";
    cout << finalGrade << endl;
    
    // Using a Conditional operator in an output expression
    cout << ((grade < 60) ? "fail" : "pass") << endl;
    
    // 4.8 Bitwise
        // check notes
    
    // Bitwise Shift Operators
    // 0233 is an octal char literal
    unsigned char bits = 0233; // 10011011
    bits << 8; // bits promoted to int and then shifted left by 8 bits
        // 00000000 00000000 10011011 00000000
    bits << 31; // left shift by 31 bits, left-most bits discarded
        // 00000000 00000000 00000000 00000000
    bits >> 3; // right shift by 3 bits, 3 right most bits discarded
        // 00000000 00000000 00000000 00010011
    
    // Bitwise NOT Operator
    unsigned char bits2 = 0227; // 10010111
    ~bits2;
        // 11111111 11111111 11111111 01101000
    
    // Bitwise AND, OR, and XOR Operators
    unsigned char b1 = 0145; // 01100101
    unsigned char b2 = 0257; // 10101111
    b1 & b2; // 24 higher order bits all 0 | 00100101
    b1 | b2; // 24 higher order bits all 0 | 11101111
    b1 ^ b2; // 24 higher order bits all 0 | 11001010
    
    // Using Bitwise Operators
    unsigned long quiz1 = 0; // using a value to collect bits
    1UL << 27; // generate a value with only bit number 27 set
    quiz1 |= 1UL << 27; // indicates student number 27 passed
    quiz1 &= ~(1UL << 27); // student number 27 failed quiz
    bool status = quiz1 & (1UL << 27); // how did student 27 do?
    
    // Shift Operators Are Left Associative
    cout << "Hi" << "There" << endl;
        // executes as: ((cout << "hi") << "there") << endl;
    cout << 42 + 10 << endl; // pk: + has higher precendence so sum is printed
    cout << (10 < 42) << endl; // ok: parenthses force intended grouping; prints 1
    
    // 4.9 The sizeof Operator
    auto size = sizeof grade;
    cout << size << endl;
    // sizeof(ia)/sizeof(*ia) returns the number of elements in ia
    int ia[5] = {1, 2, 3, 4, 5};
    constexpr size_t sz = sizeof(ia)/sizeof(*ia);
    int arr2[sz]; // ok sizeof returns a constant expression
    cout << *arr2 << " " << sz << endl;
    
    // 4.10 Comma Operator
        // check notes
    
    // 4.11 Type Conversions
    int ival = 3.1234 + 3; // compiler warns about loss of precision
    
    // When Implicit Conversions Occurs
        // Check notes
    
    // 4.11.1 The Arithmetic Conversions
    bool flag;      char cval;
    short sval;     unsigned short usval;
    int ival2;      unsigned int uival;
    long lval;      unsigned long ulval;
    float fval;     double dval;
    3.14159L + 'a'; // 'a' promoted to int, then that int converted to long double
    dval + ival; // ival converted to double
    dval + fval; // fval converted to double
    ival = dval; // dval converted (by truncation) to int
    flag = dval; // if dval is 0, then flag is false, otherwise true
    cval + fval; // cval promoted to int, then that int converted to float
    sval + cval; // sval and cval promoted to int
    cval + lval; // cval converted to long
    ival + ulval; // ival converted to unsigned long
    usval + ival; // promotion depends on the size of unsigned short and int
    uival + lval; // conversion depends on the size of unsigned int and long
    
    // 4.11.2 Other Implicit Conversions
    //Array to pointer conversion
    int ia2[10]; // array of ten ints
    int* ip = ia2; // convert ia to a pointer to the first element
    //Pointer conversions
        // check notes
    //Conversion to bool
        // check notes
    //Conversion to const
    int i4;
    const int &j1 = i4; // convert a noncost to a refernce to const int
    const int *p1 = &i4; // convert address of a nonconst to the address of const
    //Conversion Defined by Class Type
        //check notes
    
    // 4.11.3 Explicit Conversion
    int i5, j5;
    double slope = i5 / j5;
    // static_cast
    // cast used to force floating-point division
    double slope2 = static_cast<double>(j) / i;
    int d;
    void* pv = &d; // ok: address of any nonconst object can be stored in a void*
    double *dp = static_cast<double*>(pv); // ok: converts void* back to the original pointer type
    // const_cast
    const char *pc;
    char *pc2 = const_cast<char*>(pc); // ok but writing through p is undefined
    //static_cast<string>(cp); // ok: converts string literal to string
    // reinterpret_cast
    int *ip2;
    char *pc3 = reinterpret_cast<char*>(ip2);
    string str(pc);
    
    
    
    
    return 0;
}
