#include <stdbool.h>

/*@
    requires a <= b;
    requires (-2147483648 <= (a) && (a) <= 2147483647);
    requires (-2147483648 <= (b) && (b) <= 2147483647);
    requires (-2147483648 <= (c) && (c) <= 2147483647);
    ensures \result == (a <= c && c <= b);
*/
bool func(int a, int b, int c)
{
    //@ assert a <= b;
    //@ assert (-2147483648 <= (a) && (a) <= 2147483647);
    //@ assert (-2147483648 <= (b) && (b) <= 2147483647);
    //@ assert (-2147483648 <= (c) && (c) <= 2147483647);
    return a <= c && c <= b;
}
