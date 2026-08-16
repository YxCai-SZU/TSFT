#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == ((y % 5) <= (x % 3));
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    unsigned int temp_y;
    unsigned int temp_x;
    bool result;

    temp_y = y;
    /*@
        loop invariant 1 <= y <= 100;
        loop invariant temp_y <= y;
        loop invariant temp_y >= 0;
        loop invariant temp_y == y - 5 * ((y - temp_y) / 5);
        loop assigns temp_y;
    */
    while (temp_y >= 5)
    {
        temp_y -= 5;
    }

    temp_x = x;
    /*@
        loop invariant 1 <= x <= 100;
        loop invariant temp_x <= x;
        loop invariant temp_x >= 0;
        loop invariant temp_x == x - 3 * ((x - temp_x) / 3);
        loop assigns temp_x;
    */
    while (temp_x >= 3)
    {
        temp_x -= 3;
    }

    //@ assert temp_y == y % 5;
    //@ assert temp_x == x % 3;
    //@ assert ((y) >= 1 && (y) <= 100 &&         (temp_y) >= 0 && (temp_y) <= (y) &&         (temp_y) == (y) % 5);
    //@ assert ((x) >= 1 && (x) <= 100 &&         (temp_x) >= 0 && (temp_x) <= (x) &&         (temp_x) == (x) % 3);

    result = (temp_y <= temp_x);
    //@ assert result == ((y % 5) <= (x % 3));
    return result;
}
