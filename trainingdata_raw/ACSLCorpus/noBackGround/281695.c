#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 86);
    ensures \result == (((n) * 700) - (((n) / 7) * 100));
    assigns \nothing;
*/
int64_t func(uint32_t n)
{
    int64_t ans = 0;
    uint32_t i = 1;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant ans == (((i) - 1) * 700);
        loop invariant i <= 87;
        loop assigns ans, i;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        ans += 700;
        i += 1;
        //@ assert ans == (((i) - 1) * 700);
    }
    
    i = 1;
    
    /*@
        loop invariant 1 <= i <= n / 7 + 1;
        loop invariant ans == (((n) * 700) - ((i) - 1) * 100);
        loop invariant i <= 13;
        loop assigns ans, i;
        loop variant n / 7 - i + 1;
    */
    while (i <= n / 7)
    {
        ans -= 100;
        i += 1;
        //@ assert ans == (((n) * 700) - ((i) - 1) * 100);
    }
    
    //@ assert ans == (((n) * 700) - (((n) / 7) * 100));
    return ans;
}

int main()
{
    return 0;
}
