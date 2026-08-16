#include <limits.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (a + b + h) / 2;
    assigns \nothing;
*/
int func(int a, int b, int h)
{
    int sum;
    int result;
    int temp_sum;
    int count;

    sum = a + b + h;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant temp_sum + 2 * count == sum;
        loop invariant 0 <= count;
        loop invariant 0 <= temp_sum;
        loop invariant count <= sum / 2;
        loop invariant temp_sum <= sum;
        loop invariant result == 0;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum = temp_sum - 2;
        count = count + 1;
    }

    result = count;

    //@ assert result == (a + b + h) / 2;

    return result;
}
