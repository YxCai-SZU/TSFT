#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x && x <= 100; */

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == (a == b + c || b == a + c || c == a + b);
    assigns \nothing;
*/
bool func(long a, long b, long c) {
    long aa = 0;
    long bb = 0;
    long cc = 0;
    long a_arr[1];
    long b_arr[1];
    long c_arr[1];
    
    a_arr[0] = a;
    b_arr[0] = b;
    c_arr[0] = c;
    
    aa = a_arr[0];
    bb = b_arr[0];
    cc = c_arr[0];
    
    //@ assert aa == a;
    //@ assert bb == b;
    //@ assert cc == c;
    
    return aa == bb + cc || bb == aa + cc || cc == aa + bb;
}
