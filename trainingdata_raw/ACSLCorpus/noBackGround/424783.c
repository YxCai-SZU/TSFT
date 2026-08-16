#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100);
    ensures \result == ((((a) + (b) + (c))) / (3));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int sum;
    int average;
    int abs_sum;
    int count;

    sum = a + b + c;
    average = 0;
    abs_sum = sum;
    //@ assert sum == a + b + c;
    if (sum < 0)
    {
        abs_sum = -sum;
    }
    count = 0;

    /*@
        loop invariant 0 <= abs_sum <= 300;
        loop invariant 0 <= count <= 100;
        loop invariant abs_sum == sum - 3 * count;
        loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100);
        loop assigns abs_sum, count;
        loop variant abs_sum;
    */
    while (abs_sum >= 3)
    {
        abs_sum = abs_sum - 3;
        count = count + 1;
    }

    if (sum < 0)
    {
        count = -count;
    }
    average = count;

    //@ assert average == ((((a) + (b) + (c))) / (3));
    return average;
}
