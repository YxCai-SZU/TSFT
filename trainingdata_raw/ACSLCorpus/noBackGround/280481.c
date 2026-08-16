#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == (a * b % 2 == 0);
    assigns \nothing;
*/
bool func(int a, int b) {
    // Variable declarations at scope top
    int product;
    bool is_even;
    int abs_product;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    product = a * b;
    
    //@ assert 1 <= product <= 10000 * 10000;
    
    is_even = true;
    
    if (product < 0) {
        abs_product = -product;
    } else {
        abs_product = product;
    }
    
    /*@
        loop invariant 0 <= abs_product <= 10000 * 10000;
        loop invariant abs_product <= product;
        loop invariant (abs_product % 2 == 0) == (product % 2 == 0);
        loop invariant (product % 2 == 0) ==> is_even;
        loop assigns abs_product, is_even;
        loop variant abs_product;
    */
    while (abs_product >= 2) {
        abs_product -= 2;
    }
    
    if (abs_product != 0) {
        is_even = false;
    }
    
    //@ assert is_even == (product % 2 == 0);
    return is_even;
}
