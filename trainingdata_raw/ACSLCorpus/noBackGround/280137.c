#include <stdbool.h>

/*@
    requires 1 <= n <= 1000000;
    ensures \result == 0 || \result == 1;
    ensures ((\result) == 0 || (\result) == 1);
*/
int func(int n)
{
    bool is_divisible = false;
    int i = 2;
    //@ ghost int original_n = n;

    /*@
        loop invariant 2 <= i <= 10;
        loop invariant 1 <= n <= 1000000;
        loop invariant is_divisible == false || is_divisible == true;
        loop invariant n == original_n;
        loop assigns i, is_divisible;
        loop variant 10 - i;
    */
    while (i < 10)
    {
        int temp_n = n;

        /*@
            loop invariant 1 <= n <= 1000000;
            loop invariant 2 <= i <= 10;
            loop invariant 0 <= temp_n <= n;
            loop invariant is_divisible == false || is_divisible == true;
            loop invariant n == original_n;
            loop assigns temp_n;
            loop variant temp_n;
        */
        while (temp_n >= i)
        {
            temp_n -= i;
        }

        //@ assert temp_n >= 0 && temp_n < i;
        if (temp_n == 0)
        {
            is_divisible = true;
            break;
        }
        i++;
    }

    //@ assert is_divisible == false || is_divisible == true;
    if (is_divisible)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
