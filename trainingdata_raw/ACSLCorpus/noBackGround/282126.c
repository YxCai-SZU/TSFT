#include <stdbool.h>

/*@
    requires 1 <= x <= 10000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((\exists integer k; ((x)) == 3 * k) && (\exists integer k; ((x)) == 5 * k));
    ensures \result == 0 ==> !((\exists integer k; ((x)) == 3 * k) && (\exists integer k; ((x)) == 5 * k));
*/
int func(int x)
{
    bool is_divisible_by_3 = false;
    bool is_divisible_by_5 = false;
    int temp;
    int count;

    // Check divisibility by 3
    temp = x;
    count = 0;
    /*@
        loop invariant 0 <= temp <= x;
        loop invariant temp == x - 3 * count;
        loop invariant \forall integer k; 0 <= k < count ==> x - 3 * k >= 3;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 3)
    {
        temp -= 3;
        count++;
    }
    if (temp == 0)
    {
        is_divisible_by_3 = true;
    }

    // Check divisibility by 5
    temp = x;
    count = 0;
    /*@
        loop invariant 0 <= temp <= x;
        loop invariant temp == x - 5 * count;
        loop invariant \forall integer k; 0 <= k < count ==> x - 5 * k >= 5;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 5)
    {
        temp -= 5;
        count++;
    }
    if (temp == 0)
    {
        is_divisible_by_5 = true;
    }

    // Use is_divisible_by_3 and is_divisible_by_5 to determine the result
    if (is_divisible_by_3 && is_divisible_by_5)
    {
        //@ assert is_divisible_by_3 && is_divisible_by_5;
        return 1;
    }
    else
    {
        //@ assert !is_divisible_by_3 || !is_divisible_by_5;
        return 0;
    }
}
