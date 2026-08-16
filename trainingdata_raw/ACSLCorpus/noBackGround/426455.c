#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == true <==> (x / 100) >= ((x - (x / 100) * 100) / 5 + (x - (x / 100) * 100) % 5);
*/
bool func(unsigned int x)
{
    unsigned int t;
    unsigned int Y;
    bool ans;

    //@ assert (1 <= (x) <= 100000);
    t = x / 100;
    Y = x - (x / 100) * 100;
    ans = false;

    if (t >= (Y / 5 + Y % 5))
    {
        ans = true;
    }

    //@ assert ans == true <==> (x / 100) >= ((x - (x / 100) * 100) / 5 + (x - (x / 100) * 100) % 5);
    return ans;
}
