#include <stdbool.h>

/*@
    predicate is_even_property(integer product, bool result) =
        result == (product % 2 == 0);
*/

/*@
    lemma product_in_range:
        \forall integer a, b;
        1 <= a <= 10000 && 1 <= b <= 10000 ==>
        a * b <= 9223372036854775807 && a * b >= -9223372036854775808;
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires a * b <= 9223372036854775807;
    requires a * b >= -9223372036854775808;
    ensures \result == (a * b % 2 == 0);
    assigns \nothing;
*/
bool func(long long a, long long b) {
    long long product;
    bool is_even;
    long long abs_product;
    
    product = a * b;
    is_even = true;
    
    if (product < 0) {
        abs_product = -product;
    } else {
        abs_product = product;
    }
    
    /*@
        loop invariant 1 <= a <= 10000;
        loop invariant 1 <= b <= 10000;
        loop invariant a * b <= 9223372036854775807;
        loop invariant a * b >= -9223372036854775808;
        loop invariant 0 <= abs_product <= 9223372036854775807;
        loop invariant (product % 2 == 0) ==> is_even;
        loop invariant abs_product % 2 == product % 2;
        loop assigns abs_product, is_even;
        loop variant abs_product;
    */
    while (abs_product > 0) {
        if (abs_product == 1) {
            is_even = false;
            break;
        }
        
        //@ assert 0 <= abs_product * abs_product <= 9223372036854775807 * 9223372036854775807;
        
        abs_product -= 2;
    }
    
    //@ assert is_even == (product % 2 == 0);
    
    return is_even;
}

int main() {
    return 0;
}
