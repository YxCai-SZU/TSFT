#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == ((n) * ((n) - 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t ans;
    uint64_t res;
    uint64_t cnt;
    
    // Precondition check
    //@ assert (1 <= (n) && (n) <= 1000000000);
    
    // Overflow safety verification
    //@ assert n * (n - 1) <= 1000000000 * 999999999;
    
    ans = n * (n - 1);
    res = 0;
    cnt = 0;
    
    /*@
        loop invariant (1 <= (n) && (n) <= 1000000000);
        loop invariant ans + 2 * cnt == n * (n - 1);
        loop invariant cnt <= ((n) * ((n) - 1) / 2);
        loop invariant ans <= n * (n - 1);
        loop assigns ans, cnt;
        loop variant ans;
    */
    while (ans >= 2)
    {
        //@ assert ans >= 2;
        ans -= 2;
        cnt += 1;
        //@ assert ans + 2 * cnt == n * (n - 1);
    }
    
    res = cnt;
    
    // Postcondition verification
    //@ assert res == ((n) * ((n) - 1) / 2);
    
    return res;
}
