#include <limits.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 <==> (((n) % 3 == 0) && ((n) % 5 == 0));
*/
int func(int n)
{
    int original_n = n;
    int is_divisible_by_3 = 0;
    int is_divisible_by_5 = 0;
    int temp;

    // Check divisibility by 3
    temp = n;
    /*@
        loop invariant 1 <= original_n <= 10000;
        loop invariant temp >= 0;
        loop invariant temp <= original_n;
        loop invariant temp % 3 == original_n % 3;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 3)
    {
        temp -= 3;
    }
    if (temp == 0)
    {
        is_divisible_by_3 = 1;
    }

    // Check divisibility by 5
    temp = n;
    /*@
        loop invariant 1 <= original_n <= 10000;
        loop invariant temp >= 0;
        loop invariant temp <= original_n;
        loop invariant temp % 5 == original_n % 5;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 5)
    {
        temp -= 5;
    }
    if (temp == 0)
    {
        is_divisible_by_5 = 1;
    }

    if (is_divisible_by_3)
    {
        if (is_divisible_by_5)
        {
            //@ assert ((original_n) % 3 == 0) && ((original_n) % 5 == 0);
            return 0;
        }
        else
        {
            //@ assert !(((original_n) % 3 == 0) && ((original_n) % 5 == 0));
            return 1;
        }
    }
    else
    {
        //@ assert !(((original_n) % 3 == 0) && ((original_n) % 5 == 0));
        return 1;
    }
}
