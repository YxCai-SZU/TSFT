#include <stdbool.h>

/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100) && (-100 <= (c) && (c) <= 100);
    ensures \result <==> (a <= c && c <= b);
*/
bool func(int a, int b, int c)
{
    bool ans;

    // Variable declarations at top of scope
    ans = a <= c && c <= b;

    //@ assert ans <==> (a <= c && c <= b);

    return ans;
}
