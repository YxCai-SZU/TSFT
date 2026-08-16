#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result < 1000;
    ensures \result == ((1000 - ((n) % 1000)) % 1000);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t ans;
    
    //@ assert n % 1000 < 1000;
    //@ assert 1000 >= n % 1000;
    
    ans = (1000 - n % 1000) % 1000;
    
    //@ assert ans == ((1000 - ((n) % 1000)) % 1000);
    //@ assert ans < 1000;
    
    return ans;
}

int main()
{
    return 0;
}
