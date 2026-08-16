#include <stdbool.h>

/*@
    requires ((a) < 124 && (b) < 124 && (c) < 124 && (d) < 124 && (e) < 124 && (k) < 124 &&
        (a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
    ensures \result == (e - a <= k);
 */
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int i;
    bool result;

    i = a;
    /*@
        loop invariant a <= i && i <= b;
        loop invariant ((a) < 124 && (b) < 124 && (c) < 124 && (d) < 124 && (e) < 124 && (k) < 124 &&
        (a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
        loop assigns i;
     */
    while (i < b)
    {
        i = i + 1;
    }

    i = b;
    /*@
        loop invariant b <= i && i <= c;
        loop invariant ((a) < 124 && (b) < 124 && (c) < 124 && (d) < 124 && (e) < 124 && (k) < 124 &&
        (a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
        loop assigns i;
     */
    while (i < c)
    {
        i = i + 1;
    }

    i = c;
    /*@
        loop invariant c <= i && i <= d;
        loop invariant ((a) < 124 && (b) < 124 && (c) < 124 && (d) < 124 && (e) < 124 && (k) < 124 &&
        (a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
        loop assigns i;
     */
    while (i < d)
    {
        i = i + 1;
    }

    i = d;
    /*@
        loop invariant d <= i && i <= e;
        loop invariant ((a) < 124 && (b) < 124 && (c) < 124 && (d) < 124 && (e) < 124 && (k) < 124 &&
        (a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
        loop assigns i;
     */
    while (i < e)
    {
        i = i + 1;
    }

    result = (e - a <= k);
    //@ assert result == (e - a <= k);
    return result;
}
