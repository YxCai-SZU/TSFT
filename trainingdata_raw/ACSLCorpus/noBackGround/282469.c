#include <limits.h>

/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == x + ((y) / 2);
    assigns \nothing;
*/
int func(int x, int y)
{
    int ans = x;
    int temp_y = y;
    int count = 0;

    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant y % 2 == 0;
        loop invariant 0 <= temp_y;
        loop invariant 0 <= count <= ((y) / 2);
        loop invariant temp_y == y - 2 * count;
        loop assigns temp_y, count;
        loop variant temp_y;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
        count += 1;
    }

    //@ assert count <= 50;
    //@ assert ans + count <= 150;

    ans += count;
    return ans;
}
