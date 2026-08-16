#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at top
    int32_t ans;
    
    //@ assert (1 <= (r) <= 100);
    
    //@ assert (3 * (r) * (r)) >= 3;
    //@ assert (3 * (r) * (r)) <= 30000;
    
    ans = 3 * r * r;
    
    //@ assert ans == (3 * (r) * (r));
    return ans;
}

int main(void)
{
    return 0;
}
