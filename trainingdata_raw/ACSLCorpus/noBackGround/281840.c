#include <stdbool.h>
#include <limits.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result >= 1 || \result == -1;
    ensures \result <= 1000 || \result == -1;
*/
int func(unsigned int a, unsigned int b)
{
    unsigned int diff;
    unsigned int sum;
    unsigned int answer;
    bool is_possible;
    unsigned int temp_sum;
    unsigned int count;
    unsigned int temp_diff;

    diff = (b > a) ? (b - a) : (a - b);
    sum = a + b;
    answer = 0;
    is_possible = true;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant sum == a + b;
        loop invariant (((b) > (a)) ? ((diff) == (b) - (a)) : ((diff) == (a) - (b)));
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant temp_sum + 2 * count == sum;
        loop assigns temp_sum, count;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    answer = count;
    temp_diff = diff;

    /*@
        loop invariant 0 <= temp_diff <= diff;
        loop invariant sum == a + b;
        loop invariant (((b) > (a)) ? ((diff) == (b) - (a)) : ((diff) == (a) - (b)));
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant temp_diff + 2 * (diff / 2 - temp_diff / 2) == diff;
        loop assigns temp_diff;
    */
    while (temp_diff >= 2)
    {
        //@ assert temp_diff >= 2;
        temp_diff -= 2;
    }

    if (temp_diff == 1)
    {
        is_possible = false;
    }

    if (is_possible)
    {
        //@ assert answer >= 1;
        //@ assert answer <= 1000;
        return (int)answer;
    }
    else
    {
        return -1;
    }
}
