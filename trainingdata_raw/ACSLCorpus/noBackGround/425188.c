#include <stdint.h>

/*@ requires (1 <= (n) && (n) <= 100); 
    ensures \result == 800 * n - 200 * (n / 15);
*/
uint64_t func(uint64_t n)
{
    uint64_t x;
    uint64_t quotient = 0;
    uint64_t remainder = n;
    uint64_t y;
    uint64_t ans;

    //@ assert remainder == n - 15 * quotient;
    
    x = 800 * n;

    /*@
        loop invariant 0 <= quotient;
        loop invariant 0 <= remainder;
        loop invariant remainder == n - 15 * quotient;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15)
    {
        //@ assert remainder >= 15;
        quotient = quotient + 1;
        remainder = remainder - 15;
        //@ assert remainder == n - 15 * quotient;
    }

    //@ assert remainder == n - 15 * quotient;
    //@ assert remainder < 15;
    
    y = 200 * quotient;
    ans = x - y;
    
    //@ assert ans == 800 * n - 200 * quotient;
    return ans;
}
