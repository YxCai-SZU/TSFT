#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((l) * (l) * (l)) / 27;
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    // Variable declarations at top of scope
    int64_t l_cubed;
    int64_t ans = 0;
    const int64_t divisor = 27;

    //@ assert (1 <= (l) <= 1000);
    //@ assert ((l) * (l) * (l)) >= 1 && ((l) * (l) * (l)) <= 1000000000;

    l_cubed = l * l * l;

    /*@
        loop invariant 0 <= ans;
        loop invariant 0 <= l_cubed;
        loop invariant l_cubed + ans * divisor == ((l) * (l) * (l));
        loop invariant (1 <= (l) <= 1000);
        loop assigns l_cubed, ans;
        loop variant l_cubed;
    */
    while (l_cubed >= divisor)
    {
        l_cubed -= divisor;
        ans += 1;
    }

    //@ assert ans == ((l) * (l) * (l)) / 27;
    return ans;
}
