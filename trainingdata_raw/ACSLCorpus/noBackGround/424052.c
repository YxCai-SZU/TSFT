#include <stdint.h>

/*@
    requires 1 <= a <= b <= 20;
    ensures \result == a + b || \result == b - a;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t ans;
    int64_t i;
    
    ans = a + b;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= 2;
        loop invariant 1 <= a <= b <= 20;
        loop invariant ans == a + b || ans == b - a;
        loop assigns ans, i;
        loop variant 2 - i;
    */
    while (i < 2)
    {
        //@ assert ans == a + b || ans == b - a;
        ans = (ans < b - a) ? ans : (b - a);
        i = i + 1;
    }
    
    //@ assert ans == a + b || ans == b - a;
    return ans;
}
