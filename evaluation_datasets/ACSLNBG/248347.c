#include <stdbool.h>


bool func(const unsigned int numbers[3]) {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int temp;
    
    a = numbers[0];
    b = numbers[1];
    c = numbers[2];
    
    //@ assert a >= 1 && a <= 13;
    //@ assert b >= 1 && b <= 13;
    //@ assert c >= 1 && c <= 13;
    
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    //@ assert a <= b;
    
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    //@ assert a <= c;
    
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    //@ assert b <= c;
    
    //@ assert ((a) <= (b) && (b) <= (c));
    
    //@ assert ((numbers[0]) + (numbers[1]) >= (numbers[2]) && (numbers[0]) + (numbers[2]) >= (numbers[1]) && (numbers[1]) + (numbers[2]) >= (numbers[0])) <==> ((a) + (b) >= (c) && (a) + (c) >= (b) && (b) + (c) >= (a));
    
    return a + b >= c;
}
