#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (a) != (c)) ||
        ((a) == (c) && (a) != (b)) ||
        ((b) == (c) && (a) != (b)));
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int t = 0;

    //@ assert t == 0;
    if (a == b)
    {
        t += 1;
    }
    //@ assert (a == b) ==> (t == 1);
    //@ assert (a != b) ==> (t == 0);
    if (a == c)
    {
        t += 1;
    }
    //@ assert (a == b && a == c) ==> (t == 2);
    //@ assert (a == b && a != c) ==> (t == 1);
    //@ assert (a != b && a == c) ==> (t == 1);
    //@ assert (a != b && a != c) ==> (t == 0);
    if (b == c)
    {
        t += 1;
    }
    //@ assert t == 1 ==> (((a) == (b) && (a) != (c)) ||         ((a) == (c) && (a) != (b)) ||         ((b) == (c) && (a) != (b)));
    return t == 1;
}
