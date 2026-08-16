#include <stdbool.h>
/*@
    requires 1 <= x <= 1000;
    ensures \result >= 0;
    ensures \result * 3 <= x;
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
        loop invariant ((temp_x) >= 0 && (count) >= 0 && (temp_x) + 3 * (count) == (x));
        loop invariant 1 <= x <= 1000;
        loop assigns temp_x, count;
    */
    while (temp_x >= 3)
    {
        //@ assert temp_x >= 3;
        temp_x = temp_x - 3;
        count = count + 1;
        //@ assert ((temp_x) >= 0 && (count) >= 0 && (temp_x) + 3 * (count) == (x));
    }

    res = count;
    //@ assert res >= 0;
    //@ assert res * 3 <= x;
    return res;
}
