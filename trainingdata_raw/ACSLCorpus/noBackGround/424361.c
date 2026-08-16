#include <stdbool.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 <==> ((\exists integer k; (n) == 2 * k) && (\exists integer k; (n) == 5 * k));
    assigns \nothing;
*/
int func(long n)
{
    long temp;
    long counter;
    bool is_divisible_by_2 = false;
    bool is_divisible_by_5 = false;
    long temp2;

    // Check divisibility by 2
    temp = n;
    counter = 0;
    /*@
        loop invariant 0 <= temp <= n;
        loop invariant temp == ((n) - 2 * (counter));
        loop invariant counter >= 0;
        loop assigns temp, counter;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
        counter += 1;
    }
    if (temp == 0)
    {
        is_divisible_by_2 = true;
    }

    // Check divisibility by 5
    temp2 = n;
    counter = 0;
    /*@
        loop invariant 0 <= temp2 <= n;
        loop invariant temp2 == ((n) - 5 * (counter));
        loop invariant counter >= 0;
        loop assigns temp2, counter;
        loop variant temp2;
    */
    while (temp2 >= 5)
    {
        temp2 -= 5;
        counter += 1;
    }
    if (temp2 == 0)
    {
        is_divisible_by_5 = true;
    }

    //@ assert is_divisible_by_2 == (temp == 0);
    //@ assert is_divisible_by_5 == (temp2 == 0);
    //@ assert is_divisible_by_2 && is_divisible_by_5 ==> (\exists integer k; (n) == 2 * k) && (\exists integer k; (n) == 5 * k);
    
    if (is_divisible_by_2 && is_divisible_by_5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
