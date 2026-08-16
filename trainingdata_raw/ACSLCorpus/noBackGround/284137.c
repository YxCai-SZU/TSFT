#include <limits.h>

/*@
    requires a > INT_MIN && a < INT_MAX;
    requires b > INT_MIN && b < INT_MAX;
    requires c > INT_MIN && c < INT_MAX;
    ensures \result == 1 <==> ((a) < (b) && (b) < (c));
*/
int func(int a, int b, int c)
{
    int ans;
    //@ assert \true;
    ans = (a < b) && (b < c);
    //@ assert ans == 1 <==> ((a) < (b) && (b) < (c));
    return ans;
}
