#include <limits.h>

/*@
    requires 0 <= x <= 1000000000;
    ensures ((x) % 2 == 0) ==> \result == x / 2;
    ensures ((x) % 2 != 0) ==> \result == -1;
    assigns \nothing;
*/
int func(int x)
{
    int res;
    int temp_x;
    int count;

    res = 0;
    temp_x = x;
    count = 0;

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= count <= x / 2;
        loop invariant temp_x == x - 2 * count;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 2)
    {
        temp_x -= 2;
        count += 1;
    }

    //@ assert temp_x == 0 || temp_x == 1;
    
    if (temp_x == 1)
    {
        res = -1;
    }
    else
    {
        res = count;
    }

    //@ assert (((x) % 2 == 0) ==> res == x / 2) && (((x) % 2 != 0) ==> res == -1);
    return res;
}
