#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 0 <= b && b <= a;
    ensures \result == (b % 3 == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool is_divisible = false;
    int temp = b;

    /*@
        loop invariant 0 <= temp && temp <= b;
        loop invariant temp % 3 == b % 3;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 3)
    {
        temp -= 3;
    }

    if (temp == 0)
    {
        is_divisible = true;
    }

    //@ assert is_divisible == (b % 3 == 0);
    return is_divisible;
}
