#include <stdint.h>

/*@
    predicate valid_a(integer a) = 1 <= a <= 100;
    
    logic integer scaled_pi(integer a) = 2 * 3141592653589793 * a / 1000000000000000;
*/

/*@
    requires valid_a(a);
    ensures \result == scaled_pi(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t pi = 3141592653589793;
    int64_t result = 0;
    int64_t temp = a * 2 * pi;
    int64_t divisor = 1000000000000000;
    
    //@ ghost int64_t original_product = a * 2 * pi;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant pi == 3141592653589793;
        loop invariant divisor == 1000000000000000;
        loop invariant temp >= 0;
        loop invariant result * divisor + temp == original_product;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        result += 1;
    }
    
    //@ assert result * 1000000000000000 + temp == 2 * pi * a;
    
    return result;
}

int main(void)
{
    return 0;
}
