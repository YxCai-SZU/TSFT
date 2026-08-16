#include <stdbool.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures (x % 3 == 0 ==> \result == 1);
    ensures (x % 3 == 1 ==> \result == 2);
    ensures (x % 3 == 2 ==> \result == 3);
*/
int func(int x)
{
    int result;
    int temp_x;
    int count;

    result = 0;
    temp_x = x;
    count = 0;

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= count <= x/3;
        loop invariant temp_x == x - 3 * count;
        loop invariant (0 <= (x) <= 1000000000);
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 3)
    {
        temp_x -= 3;
        count += 1;
    }

    //@ assert temp_x == x % 3;

    if (temp_x == 1)
    {
        result = 2;
    }
    else if (temp_x == 2)
    {
        result = 3;
    }
    else
    {
        result = 1;
    }

    return result;
}
