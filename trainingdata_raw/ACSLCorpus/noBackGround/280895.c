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
    int result;
    int half_y;
    int abs_y;
    int i;

    result = x;
    half_y = 0;
    //@ assert half_y == 0;

    if (y < 0) {
        abs_y = -y;
    } else {
        abs_y = y;
    }

    i = 0;
    /*@
        loop invariant 0 <= i <= abs_y;
        loop invariant half_y == i / 2;
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant y % 2 == 0;
        loop invariant abs_y % 2 == 0;
        loop invariant i % 2 == abs_y % 2;
        loop assigns i, half_y;
        loop variant abs_y - i;
    */
    while (i < abs_y)
    {
        half_y += 1;
        i += 2;
        //@ assert half_y == i / 2;
    }

    if (y < 0) {
        half_y = -half_y;
    }

    result += half_y;
    //@ assert half_y == y / 2;
    //@ assert result == x + (y / 2);

    return result;
}

int main(void)
{
    return 0;
}
