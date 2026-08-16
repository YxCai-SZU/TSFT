#include <stdbool.h>

/*@
    requires (0 <= (A) <= 100 && 0 <= (P) <= 100);
    ensures \result >= 0;
    ensures \result <= ((A) * 3 + (P));
*/
int func(int A, int P)
{
    int sum;
    int result = 0;
    int temp_sum;

    //@ assert (0 <= (A) <= 100 && 0 <= (P) <= 100);
    sum = A * 3 + P;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant result >= 0;
        loop invariant result <= (sum - temp_sum) / 2;
        loop invariant sum == ((A) * 3 + (P));
        loop invariant (0 <= (A) <= 100 && 0 <= (P) <= 100);
        loop assigns result, temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        result += 1;
        temp_sum -= 2;
        //@ assert result <= (sum - temp_sum) / 2;
    }

    //@ assert result >= 0;
    //@ assert result <= ((A) * 3 + (P));
    return result;
}
