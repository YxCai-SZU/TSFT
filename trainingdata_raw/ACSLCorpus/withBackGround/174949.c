#include <stdint.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 != 0;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> (a * b) % 2 == 0;
    ensures \result == 1 ==> (a * b) % 2 != 0;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t product;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert a * b <= 10000;
    
    product = a * b;
    
    if (product % 2 == 0) {
        //@ assert is_even(product);
        return 0;
    } else {
        //@ assert is_odd(product);
        return 1;
    }
}
