#include <stdbool.h>

/*@
    requires a <= b;
    requires (-2147483648 <= (a) <= 2147483647);
    requires (-2147483648 <= (b) <= 2147483647);
    requires (-2147483648 <= (c) <= 2147483647);
    ensures \result == 1 <==> ((a) <= (c) && (c) <= (b));
*/
bool func(int a, int b, int c)
{
    //@ assert a <= b;
    return a <= c && c <= b;
}
