#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_valid_range(integer a) = 1 <= a <= 100; */

/*@ predicate is_common_divisor(integer a, integer b, integer x) =
      a % x == 0 && b % x == 0; */

/*@ lemma gcd_exists: \forall integer a, b;
      is_valid_range(a) && is_valid_range(b) ==>
      \exists integer d; 1 <= d <= a && 1 <= d <= b && is_common_divisor(a, b, d); */

/*@ requires is_valid_range(a) && is_valid_range(b);
    ensures \result <= a && \result <= b && \result >= 1;
    ensures is_common_divisor(a, b, \result);
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t x;
    
    if (a < b) {
        x = a;
    } else {
        x = b;
    }
    
    //@ assert 1 <= x <= (a < b ? a : b);
    //@ assert x <= a && x <= b;
    
    /*@ loop invariant 1 <= x <= (a < b ? a : b);
        loop invariant x <= a && x <= b;
        loop invariant is_valid_range(a) && is_valid_range(b);
        loop assigns x;
        loop variant x;
    */
    while (x >= 1) {
        bool a_is_divisible = (a % x == 0);
        bool b_is_divisible = (b % x == 0);
        
        //@ assert a_is_divisible == (a % x == 0);
        //@ assert b_is_divisible == (b % x == 0);
        
        if (a_is_divisible && b_is_divisible) {
            //@ assert is_common_divisor(a, b, x);
            return x;
        }
        
        //@ assert x > 1;
        x = x - 1;
        
        //@ assert x >= 0;
    }
    
    //@ assert x == 0;
    return 1;
}

int main() {
    return 0;
}
