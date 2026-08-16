#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int result;
    int temp_sum;

    sum = a + b + 1;
    result = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum + 2 * result == sum;
        loop assigns temp_sum, result;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        result += 1;
    }

    //@ assert result == (((a) + (b) + 1) / 2);
    return result;
}
