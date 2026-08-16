#include <limits.h>

/*@
    requires (1 <= (x) <= 179);
    ensures \result == (((x) / 2) + ((x) % 2));
    assigns \nothing;
*/
int func(int x)
{
    int result;
    int count;
    int temp_x;

    result = 0;
    count = 0;
    temp_x = x;

    //@ assert (1 <= (x) <= 179);

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x == x - 2 * count;
        loop invariant 0 <= count <= x / 2;
        loop invariant (1 <= (x) <= 179);
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 2)
    {
        temp_x -= 2;
        count += 1;
    }

    //@ assert temp_x == 0 || temp_x == 1;
    result = count + (temp_x == 1 ? 1 : 0);

    //@ assert result == (((x) / 2) + ((x) % 2));
    return result;
}
