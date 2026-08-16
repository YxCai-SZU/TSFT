#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == ((a * 3 + b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int d;
    bool is_divisible;
    unsigned int temp_d;

    d = a * 3 + b;
    is_divisible = false;
    temp_d = d;

    /*@
        loop invariant 0 <= temp_d <= d;
        loop invariant temp_d % 2 == d % 2;
        loop assigns temp_d;
        loop variant temp_d;
    */
    while (temp_d >= 2)
    {
        temp_d -= 2;
    }

    if (temp_d == 0)
    {
        is_divisible = true;
    }

    //@ assert is_divisible == ((a * 3 + b) % 2 == 0);
    return is_divisible;
}
