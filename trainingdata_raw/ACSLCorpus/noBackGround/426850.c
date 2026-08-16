#include <limits.h>

/*@
    requires (1 <= (x) && (x) <= 100) && (1 <= (y) && (y) <= 100) && ((y) % 2 == 0);
    ensures \result >= 0;
    ensures \result == ((x) + (((y)) / 2));
    assigns \nothing;
*/
long func(long x, long y) {
    long half_y;
    long count;
    long temp_y;

    if (y >= 0) {
        count = 0;
        temp_y = y;
        /*@
            loop invariant 0 <= temp_y && temp_y <= y;
            loop invariant 0 <= count && count <= y / 2;
            loop invariant temp_y == y - 2 * count;
            loop invariant 1 <= y && y <= 100;
            loop assigns temp_y, count;
            loop variant temp_y;
        */
        while (temp_y >= 2) {
            temp_y -= 2;
            count += 1;
        }
        half_y = count;
    } else {
        count = 0;
        temp_y = y;
        /*@
            loop invariant temp_y <= 0 && temp_y >= y;
            loop invariant 0 <= count && count <= -y / 2;
            loop invariant temp_y == y - 2 * count;
            loop invariant 1 <= y && y <= 100;
            loop assigns temp_y, count;
            loop variant -temp_y;
        */
        while (temp_y <= -2) {
            temp_y += 2;
            count -= 1;
        }
        half_y = count;
    }

    long ans = x + half_y;
    //@ assert ans >= 0;
    //@ assert ans == ((x) + (((y)) / 2));
    return ans;
}
