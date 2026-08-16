#include <stdbool.h>

/*@
    predicate is_mod(integer x, integer m, integer i) =
        x >= 0 && m >= 0 && i >= 0 && m == x - 100 * i && m < 100;

    lemma mod_lemma:
        \forall integer x, m, i;
            is_mod(x, m, i) ==> m == x % 100;
*/

/*@
    requires 0 <= x <= 1000000000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (x % 100) * 21 <= x;
    ensures \result == 0 ==> (x % 100) * 21 > x;
*/
int func(int x)
{
    int xx;
    int m;
    int i;

    xx = x;
    m = 0;
    i = 0;

    /*@
        loop invariant 0 <= xx <= x;
        loop invariant i <= x / 100;
        loop invariant xx == x - 100 * i;
        loop assigns xx, i;
        loop variant xx;
    */
    while (xx >= 100)
    {
        //@ assert xx >= 100;
        xx = xx - 100;
        i = i + 1;
    }

    m = xx;

    //@ assert is_mod(x, m, i);
    //@ assert m == x % 100;

    if (m * 21 <= x)
    {
        //@ assert (x % 100) * 21 <= x;
        return 1;
    }
    else
    {
        //@ assert (x % 100) * 21 > x;
        return 0;
    }
}
