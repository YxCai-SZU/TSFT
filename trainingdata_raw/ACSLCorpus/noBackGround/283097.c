#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == ((g * 10 + b) % 4 < 1);
*/
bool func(int r, int g, int b)
{
    int sum;
    int temp_sum;

    //@ assert (1 <= (r) <= 9);
    //@ assert (1 <= (g) <= 9);
    //@ assert (1 <= (b) <= 9);

    sum = g * 10 + b;

    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum % 4 == sum % 4;
        loop invariant (1 <= (r) <= 9);
        loop invariant (1 <= (g) <= 9);
        loop invariant (1 <= (b) <= 9);
        loop assigns temp_sum;
    */
    while (temp_sum >= 4)
    {
        //@ assert temp_sum % 4 == sum % 4;
        temp_sum = temp_sum - 4;
        //@ assert temp_sum % 4 == sum % 4;
    }

    //@ assert temp_sum == sum % 4;

    return temp_sum < 1;
}
