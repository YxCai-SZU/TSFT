#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((((n)) * 800) - (((((n)) / 15)) * 200));
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    // Variable declarations at scope top
    int64_t x;
    int64_t quotient = 0;
    int64_t remainder = n;
    int64_t y;
    int64_t ans;
    
    // Precondition check
    //@ assert (1 <= (n) && (n) <= 100);
    
    // Calculate n * 800
    //@ assert ((n) * 800) <= 80000;
    x = n * 800;
    
    // Division by 15 using loop
    /*@
        loop invariant 0 <= quotient <= ((n) / 15);
        loop invariant 0 <= remainder <= n;
        loop invariant remainder == n - quotient * 15;
        loop invariant quotient * 15 <= n;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15)
    {
        quotient = quotient + 1;
        remainder = remainder - 15;
    }
    
    // Verify quotient equals n/15
    //@ assert quotient == ((n) / 15);
    
    // Calculate quotient * 200
    //@ assert ((quotient) * 200) <= 1200;
    y = quotient * 200;
    
    // Final calculation
    //@ assert x - y == ((((n)) * 800) - (((((n)) / 15)) * 200));
    ans = x - y;
    
    return ans;
}

int main(void)
{
    return 0;
}
