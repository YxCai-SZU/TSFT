#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer scaled_product(integer r) = 2 * 314159 * r;
    
    lemma division_property:
        \forall integer r, integer count, integer temp;
        valid_range(r) && temp == scaled_product(r) - count * 100000 && temp >= 0 ==>
        count * 100000 + temp == scaled_product(r);
*/

/*@
    requires valid_range(r);
    ensures \result == 2 * 314159 * r / 100000;
*/
int64_t func(int64_t r)
{
    // Variable declarations
    int64_t pi;
    int64_t two;
    int64_t scale;
    int64_t scaled_r;
    int64_t product;
    int64_t result;
    int64_t temp;
    int64_t count;
    
    // Initializations
    pi = 314159;
    two = 2;
    scale = 100000;
    scaled_r = r * scale;
    product = two * pi * r;
    result = 0;
    temp = product;
    count = 0;
    
    //@ assert product == 2 * 314159 * r;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant two == 2;
        loop invariant scale == 100000;
        loop invariant scaled_r == r * scale;
        loop invariant product == two * pi * r;
        loop invariant temp >= 0;
        loop invariant temp == product - count * scale;
        loop invariant count * scale + temp == product;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= scale) {
        //@ assert temp >= 100000;
        temp -= scale;
        count += 1;
        //@ assert temp == product - count * scale;
    }
    
    result = count;
    //@ assert result * scale <= product;
    //@ assert product < (result + 1) * scale;
    return result;
}
