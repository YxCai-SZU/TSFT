#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 100);
    requires (1 <= (y) && (y) <= 100);
    requires (1 <= (z) && (z) <= 100);
    requires (1 <= (a) && (a) <= 100);
    requires (1 <= (b) && (b) <= 100);
    requires (1 <= (c) && (c) <= 100);
    ensures \result == (b - a == c - b && a <= x && b <= y && c <= z);
*/
bool func(int x, int y, int z, int a, int b, int c)
{
    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert (1 <= (y) && (y) <= 100);
    //@ assert (1 <= (z) && (z) <= 100);
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    return b - a == c - b && a <= x && b <= y && c <= z;
}
