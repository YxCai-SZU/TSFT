#include <stdbool.h>

/*@
    requires ((1) <= (a) && (a) <= (500)) && ((1) <= (b) && (b) <= (500)) && ((1) <= (c) && (c) <= (1000));
    ensures \result == (a + b >= c);
*/
bool func(int a, int b, int c)
{
    //@ assert ((1) <= (a) && (a) <= (500));
    //@ assert ((1) <= (b) && (b) <= (500));
    //@ assert ((1) <= (c) && (c) <= (1000));
    //@ assert a + b <= 1000;
    bool ans;
    ans = (a + b) >= c;
    return ans;
}
