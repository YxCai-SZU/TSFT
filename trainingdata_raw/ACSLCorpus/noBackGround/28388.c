#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * 314159 * r / 100000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t ans;
    int64_t result;
    int64_t temp;

    pi = 314159;
    ans = 2 * r * pi;

    result = 0;
    temp = ans;

    /*@
        loop invariant (1 <= (r) <= 100 &&
        (pi) == 314159 &&
        (((ans)) == 2 * ((r)) * ((pi))) &&
        (result) * 100000 + (temp) == (ans) &&
        0 <= (result) &&
        0 <= (temp) <= (ans));
        loop assigns result, temp;
        loop variant ((temp));
    */
    while (temp >= 100000)
    {
        //@ assert temp >= 100000;
        result += 1;
        temp -= 100000;
    }

    //@ assert result * 100000 + temp == ans;
    return result;
}
