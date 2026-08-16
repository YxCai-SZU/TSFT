#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (((((a) + (b) + (c) + 1)) / 2) + 1);
*/
int func(int a, int b, int c)
{
    int sum;
    int result;
    int count;
    int temp_sum;

    sum = a + b + c + 1;
    result = 0;
    count = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum + 2 * count == sum;
        loop assigns temp_sum, count;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }

    result = count + 1;

    //@ assert result == (((((a) + (b) + (c) + 1)) / 2) + 1);

    return result;
}
