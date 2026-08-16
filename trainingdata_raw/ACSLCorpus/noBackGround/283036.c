#include <stdbool.h>

/*@
    requires (1 <= (l) && (l) <= (r) && (r) <= 100 &&
        1 <= (d) && (d) <= 100);
    ensures \result >= 0;
    ensures \result <= r - l + 1;
    assigns \nothing;
*/
int func(int l, int r, int d)
{
    int count = 0;
    int i = l;
    //@ ghost int old_i;

    /*@
        loop invariant ((1 <= ((l)) && ((l)) <= ((r)) && ((r)) <= 100 &&
        1 <= ((d)) && ((d)) <= 100) &&
        (l) <= (i) && (i) <= (r) + 1 &&
        (count) >= 0 &&
        (count) <= (i) - (l));
        loop assigns i, count;
        loop variant r - i + 1;
    */
    while (i <= r)
    {
        int j = 0;
        int is_multiple = 0;
        //@ ghost int old_j;

        /*@
            loop invariant ((1 <= ((l)) && ((l)) <= ((r)) && ((r)) <= 100 &&
        1 <= ((d)) && ((d)) <= 100) &&
        0 <= (j) && (j) <= (d) &&
        (l) <= (i) && (i) <= (r) + 1 &&
        (count) >= 0 &&
        (count) <= (i) - (l) &&
        ((j) < (d) ==> (is_multiple) == 0));
            loop assigns j, is_multiple;
            loop variant d - j;
        */
        while (j < d)
        {
            if (i == j)
            {
                is_multiple = 1;
                break;
            }
            //@ assert j < d && is_multiple == 0;
            j += 1;
        }
        //@ assert is_multiple == 1 || j == d;

        if (is_multiple == 1)
        {
            count += 1;
        }
        i += 1;
    }
    return count;
}
