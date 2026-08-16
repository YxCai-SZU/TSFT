#include <limits.h>

/*@
    requires (1 <= (X) && (X) <= 205) && (1 <= (Y) && (Y) <= 205);
    ensures \result >= 0;
    ensures \result == ((X) * 1000 - 500 * (((X)) / 2) - 100 * (((X)) / 2) +
        (Y) * 1000 - 500 * (((Y)) / 2) - 100 * (((Y)) / 2));
*/
int func(int X, int Y)
{
    int money;
    int x;
    int y;
    int x_div_2;
    int temp_x;
    int y_div_2;
    int temp_y;

    money = 0;
    x = X;
    y = Y;

    x_div_2 = 0;
    temp_x = x;
    /*@
        loop invariant 0 <= temp_x;
        loop invariant 0 <= x_div_2;
        loop invariant temp_x + 2 * x_div_2 == x;
        loop assigns temp_x, x_div_2;
    */
    while (temp_x >= 2)
    {
        temp_x -= 2;
        x_div_2 += 1;
    }
    x = x_div_2;

    y_div_2 = 0;
    temp_y = y;
    /*@
        loop invariant 0 <= temp_y;
        loop invariant 0 <= y_div_2;
        loop invariant temp_y + 2 * y_div_2 == y;
        loop assigns temp_y, y_div_2;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
        y_div_2 += 1;
    }
    y = y_div_2;

    //@ assert x == ((X) / 2);
    //@ assert y == ((Y) / 2);
    money = X * 1000 - 500 * x - 100 * x + Y * 1000 - 500 * y - 100 * y;
    return money;
}
