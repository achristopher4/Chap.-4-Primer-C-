//
//  main.cpp
//  4.1 to 4.3
//
//  Created by Alex Christopher on 6/9/20.
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
//chapter 4

int main() {
    //4.1.1 Basic Concepts
    int i;
    i = 5 + 10 * 20/2;
    cout << i << endl;
    
    //4.1.2
    //When precedence and associativity matter
    int ia[] = {0, 2, 4, 6, 8};
    int last = *(ia + 4); // initializes last to 8, the value of ia[4]
    last = *ia + 4; // last = 4, equivalent to ia[0] + 4
    
    //4.1.3
        // check notes
    
    // 4.2
    int ii = 1024;
    int k = -i; // k is -1024
    bool b = true;
    bool b2 = -b; // b2 is true
    // division between int
    int ival1 = 21/6; // ival1 is 3; result is trunvated; remainder is discarded
    int ival2 = 21/7; // ival2 is 3; no remainder; result is an intergal value
    // the remainder operator
        // must use int type
    int ival3 = 42;
    ival3 % 12; // ok: results in 6
    
    //4.3
    // logical AND and OR
    vector<string> text(4, "Test.");
    // note s as a reference to const; the elements aren't copied and can't be changed
    for (const auto &s : text) {    // for each element in text
        cout << s;  // print the current element
        //blank lines and those that end with a period get a new line
        if (s.empty() || s[s.size() - 1] == '.')
            cout << endl;
        else
            cout << " "; // otherwise just separate with a space
    }
    
    // Logical NOT operator
    if (!text.empty()){
        cout << text[0] << endl;
    }
    
    //The Relational Operator
        // check notes
    
    // 4.4
        // check notes
    
    // Assignment Is Right Associative
    int ival, jval;
    ival = jval = 0; // ok: each assigned to 0
    string s1, s2;
    s1 = s2 = "OK"; // ok: string literal coverted to string
    
    // Assignment Has Low Precedence
        // check notes
    
    // Compound Assignment Operators
        // check notes
    
    return 0;
}
