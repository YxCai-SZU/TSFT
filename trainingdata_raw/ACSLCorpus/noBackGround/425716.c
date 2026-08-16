#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == (l * l * l) / 27;
    assigns \nothing;
*/
int32_t func(uint32_t l)
{
    int32_t ans = 0;
    uint32_t l_cubed = l * l * l;
    uint32_t divisor = 27;

    //@ assert l_cubed == ((l) * (l) * (l));
    //@ assert l_cubed >= 0;

    /*@
        loop invariant 0 <= l_cubed <= ((l) * (l) * (l));
        loop invariant ans == (((l) * (l) * (l)) - l_cubed) / divisor;
        loop invariant ((l) * (l) * (l)) == l_cubed + ans * divisor;
        loop assigns l_cubed, ans;
        loop variant l_cubed;
    */
    while (l_cubed >= divisor)
    {
        l_cubed -= divisor;
        ans += 1;
    }

    return ans;
}
