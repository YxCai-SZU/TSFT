#include <limits.h>

/*@
    predicate is_valid_input(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer half_of(integer y) =
        y >= 0 ? y / 2 : -(-y / 2);

    lemma half_of_even_positive:
        \forall integer y; y >= 0 && y % 2 == 0 ==> half_of(y) == y / 2;
*/

/*@
    requires is_valid_input(x, y);
    ensures \result == x + half_of(y);
    assigns \nothing;
*/
long func(long x, long y)
{
    long half_y;
    long count;
    long temp_y;

    if (y >= 0)
    {
        count = 0;
        temp_y = y;
        /*@
            loop invariant 0 <= temp_y <= y;
            loop invariant 0 <= count <= y / 2;
            loop invariant temp_y == y - 2 * count;
            loop assigns temp_y, count;
            loop variant temp_y;
        */
        while (temp_y >= 2)
        {
            temp_y -= 2;
            count += 1;
        }
        half_y = count;
    }
    else
    {
        count = 0;
        temp_y = y;
        /*@
            loop invariant y <= temp_y <= 0;
            loop invariant -y / 2 <= count <= 0;
            loop invariant temp_y == y - 2 * count;
            loop assigns temp_y, count;
            loop variant -temp_y;
        */
        while (temp_y <= -2)
        {
            temp_y += 2;
            count -= 1;
        }
        half_y = count;
    }

    //@ assert half_y == half_of(y);
    return x + half_y;
}
