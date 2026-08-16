#include <stdbool.h>

/*@
    predicate is_even(integer product) = product % 2 == 0;
    predicate is_odd(integer product) = product % 2 != 0;
    
    lemma product_range: \forall integer a, b; 1 <= a <= 10000 && 1 <= b <= 10000 ==> a * b <= 100000000;
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures (a * b % 2 != 0 ==> \result == 0);
    ensures (a * b % 2 == 0 ==> \result == 1);
*/
int func(unsigned int a, unsigned int b) {
    unsigned int product;
    bool is_even;
    unsigned int temp_product;
    
    product = a * b;
    is_even = false;
    temp_product = product;
    
    /*@
        loop invariant 1 <= a <= 10000;
        loop invariant 1 <= b <= 10000;
        loop invariant temp_product <= a * b;
        loop invariant temp_product % 2 == product % 2;
        loop invariant (product % 2 == 0 ==> is_even == true) || (product % 2 != 0 ==> is_even == false);
        loop invariant temp_product >= 0;
        loop assigns temp_product, is_even;
        loop variant temp_product;
    */
    while (temp_product > 0) {
        if (temp_product == 1) {
            is_even = false;
            break;
        }
        temp_product -= 2;
    }
    
    if (temp_product == 0) {
        is_even = true;
    }
    
    if (is_even) {
        return 1;
    } else {
        return 0;
    }
}
