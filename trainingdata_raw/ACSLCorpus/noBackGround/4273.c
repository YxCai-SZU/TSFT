#include <stdbool.h>

/*@
    requires ((a) > -2147483648 && (a) < 2147483647);
    requires ((b) > -2147483648 && (b) < 2147483647);
    requires ((c) > -2147483648 && (c) < 2147483647);
    ensures \result == (a < b && b < c);
*/
bool func(int a, int b, int c)
{
    //@ assert ((a) > -2147483648 && (a) < 2147483647);
    //@ assert ((b) > -2147483648 && (b) < 2147483647);
    //@ assert ((c) > -2147483648 && (c) < 2147483647);
    return (a < b) && (b < c);
}
