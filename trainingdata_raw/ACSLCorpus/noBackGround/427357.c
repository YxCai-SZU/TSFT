#include <stdbool.h>

/*@
    requires ((a) == 1 || (a) == 2 || (a) == 3) && ((b) == 1 || (b) == 2 || (b) == 3) && ((a) != (b));
    ensures (((\result) == 1 || (\result) == 2 || (\result) == 3) && (\result) != (a) && (\result) != (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;

    ans = 6 - a - b;

    //@ assert (((ans) == 1 || (ans) == 2 || (ans) == 3) && (ans) != (a) && (ans) != (b));
    
    return ans;
}
