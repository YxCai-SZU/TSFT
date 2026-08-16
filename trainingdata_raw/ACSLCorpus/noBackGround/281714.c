#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int avg;
    int temp_sum;
    int count;

    sum = a + b;
    avg = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant sum == a + b;
        loop invariant temp_sum + 2 * count == sum;
        loop invariant 0 <= temp_sum <= 1 || temp_sum >= 2;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }
    avg = count;

    if (temp_sum == 1)
    {
        avg += 1;
    }

    //@ assert avg == (((a) + (b) + 1) / 2);
    return avg;
}
