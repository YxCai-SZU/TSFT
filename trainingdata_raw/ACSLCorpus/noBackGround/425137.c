#include <stddef.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result <= (1000 * ((x) / 500) + 5 * (((x) % 500) / 5));
    ensures \result >= (1000 * ((x) / 500) + 5 * (((x) % 500) / 5));
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t ans = 0;
    size_t temp_x = x;

    //@ assert 1000 * (temp_x / 500) <= 1000 * 200;
    ans += 1000 * (temp_x / 500);

    temp_x = temp_x % 500;

    //@ assert 5 * (temp_x / 5) <= 5 * 100;
    ans += 5 * (temp_x / 5);

    return ans;
}
