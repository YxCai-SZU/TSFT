#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (314159)* (r)) / (100000));
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_scaled;
    int64_t scale;
    int64_t product;
    int64_t ans;
    int64_t remainder;
    
    pi_scaled = 314159;
    scale = 100000;
    product = 2 * r * pi_scaled;
    ans = 0;
    remainder = product;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant ans >= 0;
        loop invariant pi_scaled == 314159;
        loop invariant scale == 100000;
        loop invariant product == 2 * r * pi_scaled;
        loop invariant ans * scale + remainder == product;
        loop invariant 0 <= remainder < scale + 2 * 314159 * 100;
        loop assigns ans, remainder;
        loop variant remainder;
    */
    while (remainder >= scale) {
        //@ assert ans * scale + remainder == product;
        ans += 1;
        remainder -= scale;
        //@ assert ans * scale + remainder == product;
    }
    
    //@ assert remainder < scale;
    return ans;
}
