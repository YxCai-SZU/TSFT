#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a + b) + 1) / 2);
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int result;
    int count;
    int temp_sum;

    sum = a + b;
    result = 0;
    count = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum;
        loop invariant sum == a + b;
        loop invariant temp_sum + 2 * count == sum;
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant count <= sum / 2;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }

    if (temp_sum == 1)
    {
        result = count + 1;
        //@ assert result == (a + b + 1) / 2;
    }
    else
    {
        result = count;
        //@ assert result == (a + b) / 2;
    }

    return result;
}

int main(void)
{
    return 0;
}
