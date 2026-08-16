#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == ((10 * (g) + (b)) % 4 == 0);
*/
bool func(int r, int g, int b)
{
    int x;
    bool is_divisible;
    int temp;
    int count;

    x = 10 * g + b;
    is_divisible = false;
    temp = x;
    count = 0;

    /*@
        loop invariant 0 <= temp <= x;
        loop invariant 0 <= count <= x / 4;
        loop invariant temp == x - 4 * count;
        loop assigns temp, count;
    */
    while (temp >= 4)
    {
        temp -= 4;
        count += 1;
    }

    //@ assert temp == x - 4 * count;
    if (temp == 0)
    {
        is_divisible = true;
    }

    return is_divisible;
}
