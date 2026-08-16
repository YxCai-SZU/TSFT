#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result == ((a) * 100 + (b) * 10 + (c) + 111);
*/
int func(int a, int b, int c)
{
    int ans;
    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);
    ans = a * 100 + b * 10 + c + 111;
    //@ assert ans == ((a) * 100 + (b) * 10 + (c) + 111);
    return ans;
}
