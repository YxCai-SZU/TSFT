#include <limits.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 10000;

    logic integer original_x(integer x, integer div_500, integer temp_x) = 
        temp_x + 500 * div_500;

    logic integer original_temp_x(integer x, integer div_5) = 
        x + 5 * div_5;
*/

/*@
    requires is_valid_range(x);
    ensures \result == (x / 500) * 1000 + (x % 500 / 5) * 5;
*/
int func(int x)
{
    int x_local = x;
    int result = 0;
    int div_500 = 0;
    int temp_x = x_local;

    //@ ghost int original_x_value = x_local;

    /*@
        loop invariant 0 <= temp_x;
        loop invariant temp_x == original_x_value - 500 * div_500;
        loop invariant 0 <= div_500;
        loop invariant div_500 <= original_x_value / 500;
        loop assigns temp_x, div_500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        temp_x -= 500;
        div_500 += 1;
    }

    x_local = temp_x;
    result += div_500 * 1000;

    //@ ghost int original_temp_x_value = temp_x;
    int div_5 = 0;

    /*@
        loop invariant 0 <= x_local;
        loop invariant x_local == original_temp_x_value - 5 * div_5;
        loop invariant 0 <= div_5;
        loop invariant div_5 <= original_temp_x_value / 5;
        loop assigns x_local, div_5;
        loop variant x_local;
    */
    while (x_local >= 5)
    {
        x_local -= 5;
        div_5 += 1;
    }

    result += div_5 * 5;
    return result;
}

int main()
{
    return 0;
}
