#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == ( (a + b) % 2 == 0 );
*/
bool func(int a, int b)
{
    int sum;
    bool is_even;
    int temp_sum;

    sum = a + b;

    if (sum > 0)
    {
        temp_sum = sum;
        /*@
            loop invariant 0 <= temp_sum <= sum;
            loop invariant temp_sum % 2 == sum % 2;
            loop invariant 1 <= a <= 100;
            loop invariant 1 <= b <= 100;
            loop invariant sum == a + b;
            loop assigns temp_sum;
        */
        while (temp_sum >= 2)
        {
            temp_sum -= 2;
        }
        is_even = (temp_sum == 0);
    }
    else
    {
        is_even = false;
    }

    //@ assert is_even == ( (a + b) % 2 == 0 );
    return is_even;
}
