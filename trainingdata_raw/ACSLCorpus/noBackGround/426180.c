#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == 180 * (n - 2);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t ans = 0;
    uint32_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == 180 * (int32_t)i;
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n)
    {
        ans += 180;
        i += 1;
    }
    
    ans -= 360;
    return ans;
}

int main(void)
{
    return 0;
}
