#include <stdbool.h>

/*@
    requires (0 <= (a) < 124 && 0 <= (b) < 124 && 0 <= (c) < 124 && 0 <= (d) < 124 && 0 <= (e) < 124 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    requires 0 <= k <= 123;
    ensures \result == ((e - a) <= k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    //@ assert (0 <= (a) < 124 && 0 <= (b) < 124 && 0 <= (c) < 124 && 0 <= (d) < 124 && 0 <= (e) < 124 &&         (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    //@ assert 0 <= k <= 123;
    //@ assert a < b && b < c && c < d && d < e;
    //@ assert (e - a) <= k <==> (e - a) <= k;
    return (e - a) <= k;
}
