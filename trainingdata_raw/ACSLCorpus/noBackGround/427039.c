#include <stdint.h>

/*@
    requires (0 <= (A) <= 100 && 0 <= (P) <= 100);
    ensures \result >= 0;
    ensures \result <= ((A) * 3 + (P));
*/
int64_t func(int64_t A, int64_t P)
{
    int64_t ans;
    int64_t count;
    int64_t temp;

    ans = A * 3 + P;
    count = 0;
    temp = ans;

    /*@
        loop invariant (0 <= (temp) <= (((A)) * 3 + ((P))) &&
        0 <= (count) <= ((((A)) * 3 + ((P))) - (temp)) / 2 &&
        (temp) + 2 * (count) == (((A)) * 3 + ((P))));
        loop assigns temp, count;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
    }

    ans = count;
    return ans;
}
