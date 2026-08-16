#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ((a * b) % 2 == 0);
*/
bool func(long long a, long long b) {
    long long product;
    bool is_even;
    long long abs_product;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    //@ assert a * b <= 10000 * 10000;
    
    product = a * b;
    is_even = false;
    
    if (product < 0) {
        abs_product = -product;
    } else {
        abs_product = product;
    }
    
    /*@
        loop invariant 0 <= abs_product <= 100000000;
        loop invariant abs_product % 2 == product % 2;
        loop assigns abs_product;
    */
    while (abs_product >= 2) {
        abs_product = abs_product - 2;
    }
    
    if (abs_product == 0) {
        is_even = true;
    }
    
    //@ assert is_even == ((a * b) % 2 == 0);
    
    return is_even;
}
