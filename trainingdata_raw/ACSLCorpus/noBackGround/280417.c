#include <stdbool.h>

/*@ requires ((1) <= (a) && (a) <= (5000));
    requires ((1) <= (b) && (b) <= (5000));
    requires ((1) <= (c) && (c) <= (10000));
    ensures \result == (c <= a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    //@ assert ((1) <= (a) && (a) <= (5000));
    //@ assert ((1) <= (b) && (b) <= (5000));
    //@ assert ((1) <= (c) && (c) <= (10000));
    //@ assert ((2) <= (a + b) && (a + b) <= (10000));
    return c <= a + b;
}

/*@ requires ((1) <= (a) && (a) <= (100));
    requires ((1) <= (b) && (b) <= (100));
    requires ((1) <= (c) && (c) <= (100));
    ensures \result == (a <= c && b <= c);
    assigns \nothing;
*/
bool func2(int a, int b, int c) {
    int min;
    //@ assert ((1) <= (a) && (a) <= (100));
    //@ assert ((1) <= (b) && (b) <= (100));
    //@ assert ((1) <= (c) && (c) <= (100));
    
    min = a;
    //@ assert min == a;
    
    if (b < min) {
        min = b;
        //@ assert min == b;
    }
    
    if (c < min) {
        min = c;
        //@ assert min == c;
    }
    
    //@ assert min <= a && min <= b && min <= c;
    return a <= c && b <= c;
}
