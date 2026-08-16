#include <stddef.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((((a)) * 800) - ((a) / 15) * 200);
    assigns \nothing;
*/
size_t func(size_t a)
{
    size_t res;
    size_t ans;
    size_t i;
    
    //@ assert (1 <= (a) <= 100);
    
    res = a * 800;
    ans = res;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= a / 15;
        loop invariant ans == ((a) * 800) - i * 200;
        loop invariant ((a) * 800) == a * 800;
        loop invariant (1 <= (a) <= 100);
        loop assigns ans, i;
        loop variant (a / 15) - i;
    */
    while (i < (a / 15))
    {
        //@ assert ans == ((a) * 800) - i * 200;
        ans -= 200;
        //@ assert ans == ((a) * 800) - (i + 1) * 200;
        i += 1;
    }
    
    //@ assert ans == ((((a)) * 800) - ((a) / 15) * 200);
    return ans;
}
