#include <stdbool.h>
/*@
    requires (0 <= (x) && (x) <= 1000000000);
    ensures \result >= 0;
    ensures \result * 1000 <= x;
    ensures (\result + 1) * 1000 > x;
    assigns \nothing;
*/
int func(int x)
{
    int result = 0;
    int remaining_x = x;
    int divisor = 1000;

    /*@
        loop invariant 0 <= result;
        loop invariant result <= x / 1000;
        loop invariant remaining_x == x - result * 1000;
        loop invariant 0 <= x <= 1000000000;
        loop assigns result, remaining_x;
        loop variant remaining_x;
    */
    while (remaining_x >= divisor)
    {
        //@ assert remaining_x >= divisor;
        remaining_x -= divisor;
        result += 1;
    }

    //@ assert result >= 0;
    //@ assert result * 1000 <= x;
    //@ assert (result + 1) * 1000 > x;
    return result;
}
