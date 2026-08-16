#include <stdbool.h>
#include <stddef.h>

/*@
    requires 0 <= a <= 50;
    requires 0 <= b <= 50;
    requires 0 <= c <= 50;
    ensures \result >= 0;
    ensures \result <= 2;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t ans = 0;

    //@ assert \true;

    if (a == b && b == c)
    {
        ans = 1;
    }

    //@ assert ans == 0 || ans == 1;

    if (a != b && b != c && a != c)
    {
        ans = 2;
    }

    //@ assert ans >= 0 && ans <= 2;

    return ans;
}
