#include <stdbool.h>
/*@
    requires 1 <= n <= 1000;
    ensures \result >= 0;
    ensures \result * 3 <= n;
    ensures n < (\result + 1) * 3;
*/
int func(int n)
{
    int count = 0;
    int value = n;
    //@ ghost int original_n = n;

    /*@
        loop invariant (1 <= (original_n) <= 1000 &&
        (value) >= 0 &&
        (count) >= 0 &&
        (value) == (original_n) - 3 * (count) &&
        (count) <= 333);
        loop assigns value, count;
        loop variant value;
    */
    while (value >= 3)
    {
        //@ assert value >= 3;
        value -= 3;
        count += 1;
        //@ assert value == original_n - 3 * count;
    }
    //@ assert value < 3;
    //@ assert count * 3 <= original_n;
    //@ assert original_n < (count + 1) * 3;
    return count;
}
