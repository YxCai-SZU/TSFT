#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 &&
        0 <= (b) <= 100 &&
        0 <= (c) <= 100 &&
        (a) + (b) + (c) == 180);
    ensures \result == 1 <==> ((a) == 60 || (b) == 60 || (c) == 60);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    bool ans;

    //@ assert (0 <= (a) <= 100 &&         0 <= (b) <= 100 &&         0 <= (c) <= 100 &&         (a) + (b) + (c) == 180);
    
    if (a == 60 || b == 60 || c == 60)
    {
        ans = true;
    }
    else
    {
        ans = false;
    }
    
    //@ assert ans == 1 <==> ((a) == 60 || (b) == 60 || (c) == 60);
    
    return ans;
}
