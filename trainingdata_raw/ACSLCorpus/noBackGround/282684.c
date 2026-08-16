#include <stdbool.h>

/*@
    requires a <= 10000 && b <= 10000 && c <= 10000;
    ensures \result == (a + b + c >= 10000);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int total;
    bool ans;

    total = a + b + c;
    ans = false;

    if (total >= 10000)
    {
        ans = true;
    }
    else
    {
        ans = false;
    }

    //@ assert ans == (a + b + c >= 10000);
    return ans;
}
