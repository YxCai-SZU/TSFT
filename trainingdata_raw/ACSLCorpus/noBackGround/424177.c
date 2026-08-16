#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == ((((a) * (b)) % 2) == 0);
    assigns \nothing;
*/
bool func(int a, int b) {
    // Variable declarations at top of scope
    int product;
    bool is_even;
    int abs_product;
    
    // Precondition assertions
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    
    // Product range verification
    //@ assert 0 <= a * b <= 100000000;
    
    product = a * b;
    is_even = true;
    abs_product = (product < 0) ? -product : product;
    
    /*@
        loop invariant 0 <= abs_product <= 100000000;
        loop invariant abs_product % 2 == product % 2;
        loop invariant (product % 2 == 0) ==> is_even == \true;
        loop invariant (product % 2 != 0) ==> (abs_product > 0 ==> is_even == \true);
        loop assigns abs_product, is_even;
        loop variant abs_product;
    */
    while (abs_product > 0) {
        if (abs_product == 1) {
            is_even = false;
            break;
        }
        
        // Arithmetic reasoning
        //@ assert 0 <= abs_product * abs_product <= 100000000 * 100000000;
        
        abs_product -= 2;
    }
    
    // Postcondition verification
    //@ assert (product % 2 == 0) ==> is_even == \true;
    //@ assert (product % 2 != 0) ==> is_even == \false;
    
    return is_even;
}
