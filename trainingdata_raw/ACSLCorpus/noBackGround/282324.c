#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 100 &&
        1 <= (y) && (y) <= 100 &&
        1 <= (z) && (z) <= 100);
    ensures \result == ((((x)) * ((y))) / 2);
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    int ans = 0;
    int temp = 0;
    int count = 0;

    //@ assert 1 <= ((x) * (y)) && ((x) * (y)) <= 10000;
    temp = x * y;
    count = 0;

    /*@
        loop invariant (1 <= (x) && (x) <= 100 &&
        1 <= (y) && (y) <= 100 &&
        1 <= (z) && (z) <= 100);
        loop invariant 0 <= temp && temp <= ((x) * (y));
        loop invariant temp + 2 * count == ((x) * (y));
        loop invariant count <= ((((x)) * ((y))) / 2);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
        count += 1;
    }

    ans = count;
    return ans;
}
