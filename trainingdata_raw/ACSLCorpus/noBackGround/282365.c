#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures ((\result) >= 0 &&
        ((\result) == (((a)) * ((b))) ||
         (\result) == (((a)) * ((b))) + 1 ||
         (\result) == (((a)) * ((b))) + 2));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert 1 <= a * b <= 10000;
    
    int ans;
    int i;
    
    ans = a * b;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= 2;
        loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100);
        loop invariant ans >= 0;
        loop invariant ((ans) >= 0 &&
        ((ans) == (((a)) * ((b))) ||
         (ans) == (((a)) * ((b))) + 1 ||
         (ans) == (((a)) * ((b))) + 2));
        loop invariant ans <= a * b + i;
        loop assigns ans, i;
        loop variant 2 - i;
    */
    while (i < 2)
    {
        ans += 1;
        i += 1;
    }
    
    //@ assert ((ans) >= 0 &&         ((ans) == (((a)) * ((b))) ||          (ans) == (((a)) * ((b))) + 1 ||          (ans) == (((a)) * ((b))) + 2));
    return ans;
}
