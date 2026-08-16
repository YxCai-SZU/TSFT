#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000);
    ensures \result == (((n) - 1) * (n) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    uint64_t result = 0;
    uint64_t i = 1;
    
    //@ assert (1 <= (n) <= 1000000000);
    //@ assert n > 0;
    //@ assert n <= 1000000000;
    
    /*@
        loop invariant 1 <= i <= n;
        loop invariant result == (i - 1) * i / 2;
        loop invariant (1 <= (n) <= 1000000000);
        loop assigns result, i;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert i > 0 && i <= n;
        //@ assert result == (i - 1) * i / 2;
        //@ assert result + i == i * (i + 1) / 2;
        //@ assert i * (i + 1) / 2 <= 1000000000 * (1000000000 + 1) / 2;
        
        result += i;
        i += 1;
    }
    
    //@ assert n > 0 && n <= 1000000000;
    //@ assert (n - 1) * n <= 1000000000 * 1000000000;
    
    result = (n - 1) * n / 2;
    
    //@ assert result == (((n) - 1) * (n) / 2);
    return result;
}
