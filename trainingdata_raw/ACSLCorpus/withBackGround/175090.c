#include <stdbool.h>

/*@ predicate is_even_sum(integer x, integer y) = (x + y) % 2 == 0; */

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == true <==> is_even_sum(x, y);
*/
bool func(long x, long y) {
    long x_local = x;
    long y_local = y;
    bool is_even = true;
    long sum = 0;

    //@ assert 1 <= x_local <= 100;
    //@ assert 1 <= y_local <= 100;
    
    if (x_local < 0) {
        x_local = -x_local;
    }
    if (y_local < 0) {
        y_local = -y_local;
    }
    
    //@ assert x_local >= 0;
    //@ assert y_local >= 0;
    
    if ((x_local + y_local) < 0) {
        x_local = -x_local;
        y_local = -y_local;
    }
    
    //@ assert x_local >= 0;
    //@ assert y_local >= 0;
    //@ assert 1 <= x_local <= 100;
    //@ assert 1 <= y_local <= 100;
    
    sum = x_local + y_local;
    
    /*@
        loop invariant sum >= 0;
        loop invariant sum <= x_local + y_local;
        loop invariant x_local >= 0;
        loop invariant y_local >= 0;
        loop invariant 1 <= x_local <= 100;
        loop invariant 1 <= y_local <= 100;
        loop invariant sum % 2 == (x_local + y_local) % 2;
        loop assigns sum;
        loop variant sum;
    */
    while (sum >= 2) {
        sum -= 2;
    }
    
    if (sum == 1) {
        is_even = false;
    }
    
    //@ assert is_even == true <==> is_even_sum(x, y);
    return is_even;
}
