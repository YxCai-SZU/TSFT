#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result == (a % 3 == 0 && b % 3 == 0);
*/
bool func(unsigned int a, unsigned int b)
{
    bool is_a_divisible = false;
    bool is_b_divisible = false;
    unsigned int temp_a = a;
    unsigned int temp_b = b;

    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant a % 3 == temp_a % 3;
        loop assigns temp_a;
    */
    while (temp_a >= 3)
    {
        //@ assert temp_a % 3 == (temp_a - 3) % 3;
        temp_a -= 3;
    }
    if (temp_a == 0)
    {
        is_a_divisible = true;
    }

    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant b % 3 == temp_b % 3;
        loop assigns temp_b;
    */
    while (temp_b >= 3)
    {
        //@ assert temp_b % 3 == (temp_b - 3) % 3;
        temp_b -= 3;
    }
    if (temp_b == 0)
    {
        is_b_divisible = true;
    }

    return is_a_divisible && is_b_divisible;
}
