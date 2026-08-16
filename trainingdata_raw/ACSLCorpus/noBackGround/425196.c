#include <stdbool.h>

/*@
    requires a <= b;
    requires (0 <= (a) <= 100);
    requires (0 <= (b) <= 100);
    requires (0 <= (c) <= 100);
    ensures \result <==> ((a) <= (c) <= (b));
*/
bool func(int a, int b, int c)
{
    //@ assert (0 <= (c) <= 100);
    //@ assert (0 <= (a) <= 100) && (0 <= (b) <= 100);
    //@ assert a <= 100 && b <= 100 && c <= 100;
    return a <= c && c <= b;
}
