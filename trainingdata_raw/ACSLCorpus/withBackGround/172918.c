#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer initial_product(integer pi, integer r) = 2 * pi * r;
    
    lemma circumference_nonnegative:
        \forall integer r, pi, circ, temp, divisor;
        valid_range(r) && pi == 314159 && divisor == 100000 &&
        circ >= 0 && temp >= 0 && temp + circ * divisor == initial_product(pi, r) ==>
        circ >= 0;
*/

/*@
    requires valid_range(r);
    ensures \result >= 0;
    ensures \result <= 314159 * 2 * r / 100000;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t circumference;
    int64_t temp;
    int64_t divisor;
    
    pi = 314159;
    circumference = 0;
    temp = 2 * pi * r;
    divisor = 100000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant 0 <= circumference;
        loop invariant temp >= 0;
        loop invariant temp + circumference * divisor == 2 * pi * r;
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference >= 0;
    
    return circumference;
}

int main()
{
    return 0;
}
