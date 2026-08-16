#include <stdbool.h>

/*@
    predicate is_valid_range(integer a) = 1 <= a <= 100;
    
    logic integer scaled_pi = 3141592;
    logic integer divisor = 1000000;
    
    logic integer expected_result(integer a) = 
        (2 * scaled_pi * a) / divisor;
    
    lemma product_bounds:
        \forall integer a; is_valid_range(a) ==> 
            2 * scaled_pi * a <= 2 * scaled_pi * 100;
*/

/*@
    requires is_valid_range(a);
    ensures \result == expected_result(a);
    assigns \nothing;
*/
int func(int a)
{
    int pi = 3141592;
    int product;
    int result = 0;
    int remainder;
    int divisor = 1000000;
    
    //@ assert a <= 100;
    //@ assert a >= 1;
    
    //@ assert 2 * pi * a <= 2 * 3141592 * 100;
    product = 2 * pi * a;
    remainder = product;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant result * divisor + remainder == product;
        loop invariant 0 <= remainder;
        loop invariant remainder <= product;
        loop assigns remainder, result;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        result += 1;
    }
    
    return result;
}

int main(void)
{
    return 0;
}
