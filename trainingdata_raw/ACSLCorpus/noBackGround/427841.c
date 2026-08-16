#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3);
    requires ((a) != (b));
    ensures \result == (6 - (a) - (b));
    ensures (1 <= (\result) <= 3);
    ensures ((\result) != (a)) && ((\result) != (b));
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int ans;
    ans = 6 - a - b;
    //@ assert ans >= 1 && ans <= 3;
    //@ assert ans != a && ans != b;
    return ans;
}
