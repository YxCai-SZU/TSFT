#include <stdbool.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000);
    ensures \result == (((A) * (B)) % 2 == 0);
    assigns \nothing;
*/
bool func(int A, int B) {
    // Variable declarations at scope top
    int product;
    bool is_even;
    int abs_product;
    
    //@ assert 1 <= A <= 10000;
    //@ assert 1 <= B <= 10000;
    
    //@ assert 1 <= ((A) * (B)) <= 100000000;
    product = A * B;
    
    is_even = true;
    abs_product = (product < 0) ? -product : product;
    
    /*@
        loop invariant 0 <= abs_product <= 100000000;
        loop invariant abs_product <= ((A) * (B));
        loop invariant (abs_product % 2 == 0) == (((A) * (B)) % 2 == 0);
        loop invariant (((A) * (B)) % 2 == 0) ==> is_even;
        loop assigns abs_product, is_even;
    */
    while (abs_product > 0) {
        if (abs_product == 1) {
            is_even = false;
            break;
        }
        abs_product -= 2;
    }
    
    //@ assert is_even ==> (((A) * (B)) % 2 == 0);
    return is_even;
}
