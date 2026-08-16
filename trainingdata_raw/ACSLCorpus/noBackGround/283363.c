#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (((n) / 2) + ((n) % 2));
    ensures \result >= 1;
    ensures \result <= 50;
*/
size_t func(size_t n)
{
    size_t ans;

    ans = n / 2;
    //@ assert ans == n / 2;

    if (n % 2 == 1)
    {
        ans += 1;
        //@ assert ans == (n / 2) + 1;
    }

    //@ assert ans == (((n) / 2) + ((n) % 2));
    //@ assert ans >= 1;
    //@ assert ans <= 50;

    return ans;
}
