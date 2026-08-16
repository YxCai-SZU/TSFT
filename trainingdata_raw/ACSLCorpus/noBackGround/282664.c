#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000);
    ensures \result == (((n) * ((n) - 1)) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    uint64_t ans;
    
    //@ assert (1 <= (n) <= 1000000000);
    //@ assert n >= 1 && n <= 1000000000;
    
    // Proof of overflow safety
    //@ assert n * (n - 1) <= 1000000000 * 999999999;
    //@ assert (n * (n - 1)) / 2 <= 499999999500000000;
    
    ans = n * (n - 1) / 2;
    
    //@ assert ans == (((n) * ((n) - 1)) / 2);
    return ans;
}

#ifdef TEST
#include <assert.h>

int main()
{
    uint64_t n = 1000000000;
    uint64_t result = func(n);
    assert(result == 499999999500000000);
    return 0;
}
#endif
