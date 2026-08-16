#include <stdbool.h>

/*@
    requires ((a) > 0) && ((b) > 0);
    requires ((a) <= 1000) && ((b) <= 1000);
    ensures \result == (((a) * (b)) % 2 != 0);
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int c;
    bool ans;

    //@ assert ((a) * (b)) <= 1000 * 1000;
    c = a * b;
    ans = (c % 2) != 0;
    //@ assert ans == (((a) * (b)) % 2 != 0);
    return ans;
}
