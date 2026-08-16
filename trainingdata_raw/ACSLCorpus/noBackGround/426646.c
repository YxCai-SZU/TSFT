#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * r * 314 / 100;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t result;
    int64_t i;
    int64_t divisor;
    
    pi = 314;
    result = 2 * r * pi;
    i = 0;
    divisor = 100;
    
    //@ ghost int64_t original_product = 2 * r * pi;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant divisor == 100;
        loop invariant result >= 0;
        loop invariant result <= 2 * 100 * 314;
        loop invariant i * divisor + result == original_product;
        loop assigns result, i;
        loop variant result;
    */
    while (result >= divisor)
    {
        result -= divisor;
        i += 1;
    }
    
    //@ assert i * 100 + result == original_product;
    
    return i;
}

int main()
{
    return 0;
}
