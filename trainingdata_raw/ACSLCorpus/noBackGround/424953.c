#include <stdbool.h>
#include <limits.h>

/*@ requires ((4) == 4 &&
        \valid((v) + (0 .. 3)) &&
        (1 <= ((v)[0]) <= 10000) &&
        (1 <= ((v)[1]) <= 10000) &&
        (1 <= ((v)[2]) <= 10000) &&
        (1 <= ((v)[3]) <= 10000));
    ensures \result == ((v[0]) * (v[1])) || 
            \result == ((v[2]) * (v[3]));
    ensures \result >= 1;
    assigns \nothing; */
int func(int* v) {
    int a;
    int b;
    int c;
    int d;
    int max_val;
    
    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    //@ assert ((a) * (b)) <= INT_MAX;
    //@ assert ((c) * (d)) <= INT_MAX;
    
    //@ assert ((a) * (b)) >= 1;
    //@ assert ((c) * (d)) >= 1;
    
    if (a * b > c * d) {
        max_val = a * b;
    } else {
        max_val = c * d;
    }
    
    //@ assert max_val == ((a) * (b)) || max_val == ((c) * (d));
    //@ assert max_val >= 1;
    
    return max_val;
}
