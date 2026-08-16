#include <stdbool.h>

/*@ requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ( (a * b) % 2 == 0 );
    assigns \nothing;
*/
bool func(int a, int b) {
    int c;
    bool is_even;
    int temp_c;
    
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert a * b <= 100000000;
    
    c = a * b;
    temp_c = c;
    
    /*@ loop invariant 0 <= temp_c <= c;
        loop invariant temp_c % 2 == c % 2;
        loop assigns temp_c;
        loop variant temp_c;
    */
    while (temp_c >= 2) {
        temp_c -= 2;
    }
    
    is_even = (temp_c == 0);
    
    //@ assert is_even == ((a * b) % 2 == 0);
    
    return is_even;
}
