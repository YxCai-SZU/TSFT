#include <stdbool.h>

/*@ requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a % 2 != 0 && b % 2 != 0);
    assigns \nothing;
 */
bool func(int a, int b)
{
    bool is_a_odd = true;
    int temp_a = a;
    bool is_b_odd = true;
    int temp_b = b;

    /*@ loop invariant 1 <= a <= 10000;
        loop invariant 0 <= temp_a <= a;
        loop invariant temp_a % 2 == a % 2;
        loop assigns temp_a;
        loop variant temp_a;
     */
    while (temp_a >= 2)
    {
        temp_a -= 2;
    }

    if (temp_a != 1)
    {
        is_a_odd = false;
    }

    /*@ loop invariant 1 <= b <= 10000;
        loop invariant 0 <= temp_b <= b;
        loop invariant temp_b % 2 == b % 2;
        loop assigns temp_b;
        loop variant temp_b;
     */
    while (temp_b >= 2)
    {
        temp_b -= 2;
    }

    if (temp_b != 1)
    {
        is_b_odd = false;
    }

    //@ assert is_a_odd == (a % 2 != 0);
    //@ assert is_b_odd == (b % 2 != 0);

    return is_a_odd && is_b_odd;
}
