#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == ((100 * (r) + 10 * (g) + (b)) % 4 == 0);
*/
bool func(int r, int g, int b)
{
    int x;
    bool is_divisible;
    int abs_x;

    //@ assert (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    x = 100 * r + 10 * g + b;
    is_divisible = false;
    
    if (x < 0) {
        abs_x = -x;
    } else {
        abs_x = x;
    }

    /*@
        loop invariant 0 <= abs_x <= 999;
        loop invariant abs_x <= (100 * (r) + 10 * (g) + (b));
        loop invariant (100 * (r) + 10 * (g) + (b)) % 4 == abs_x % 4;
        loop assigns abs_x;
    */
    while (abs_x >= 4)
    {
        //@ assert abs_x >= 4;
        abs_x -= 4;
        //@ assert abs_x >= 0;
    }

    if (abs_x == 0) {
        is_divisible = true;
    }

    //@ assert is_divisible == ((100 * (r) + 10 * (g) + (b)) % 4 == 0);
    return is_divisible;
}
