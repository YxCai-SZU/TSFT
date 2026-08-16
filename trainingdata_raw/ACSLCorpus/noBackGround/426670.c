#include <stdint.h>

/*@
    requires (1 <= (l) && (l) <= 1000);
    ensures \result == (l * l * l) / 27;
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    // Variable declarations at scope top
    int64_t l_cubed;
    int64_t ans;
    int64_t temp;
    const int64_t divisor = 27;

    //@ assert (1 <= (l) && (l) <= 1000);
    //@ assert 1 <= ((l) * (l)) && ((l) * (l)) <= 1000000;
    //@ assert 1 <= ((l) * (l) * (l)) && ((l) * (l) * (l)) <= 1000000000;

    l_cubed = l * l * l;
    ans = 0;
    temp = l_cubed;

    /*@
        loop invariant (1 <= (l) && (l) <= 1000);
        loop invariant 1 <= ((l) * (l)) && ((l) * (l)) <= 1000000;
        loop invariant 1 <= ((l) * (l) * (l)) && ((l) * (l) * (l)) <= 1000000000;
        loop invariant 0 <= ans;
        loop invariant 0 <= temp <= l_cubed;
        loop invariant temp + ans * divisor == l_cubed;
        loop invariant ans == (l_cubed - temp) / divisor;
        loop assigns ans, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        ans += 1;
    }

    //@ assert ans == (l * l * l) / 27;
    return ans;
}
