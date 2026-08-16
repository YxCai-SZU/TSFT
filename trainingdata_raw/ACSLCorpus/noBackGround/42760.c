#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (a + b + 1) / 2;
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int result = 0;
    int count;
    int temp_sum;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    sum = a + b + 1;
    //@ assert sum == ((a) + (b) + 1);
    //@ assert 1 <= sum <= 201;

    temp_sum = sum;
    result = 0;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant temp_sum >= 0;
        loop invariant result == (sum - temp_sum) / 2;
        loop invariant sum == a + b + 1;
        loop invariant temp_sum + 2 * result == sum;
        loop invariant 1 <= sum <= 201;
        loop assigns temp_sum, result;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        result += 1;
    }

    count = result;

    //@ assert sum == a + b + 1;
    //@ assert count == (a + b + 1) / 2;

    if (sum & 1 == 1) {
        count = result;
    } else {
        count = result;
    }

    //@ assert count == (a + b + 1) / 2;
    return count;
}
