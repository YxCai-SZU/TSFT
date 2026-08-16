#include <stdbool.h>

/*@
    requires ((1 <= (a) <= 10000)) && ((1 <= (b) <= 10000));
    ensures \result == (a % 2 == 0 || b % 2 == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool is_a_even = false;
    bool is_b_even = false;
    int temp_a = a;
    int temp_b = b;

    // Check if `a` is even
    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant (a - temp_a) % 2 == 0;
        loop assigns temp_a;
        loop variant temp_a;
    */
    while (temp_a >= 2)
    {
        temp_a -= 2;
    }
    if (temp_a == 0)
    {
        is_a_even = true;
    }

    // Check if `b` is even
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant (b - temp_b) % 2 == 0;
        loop assigns temp_b;
        loop variant temp_b;
    */
    while (temp_b >= 2)
    {
        temp_b -= 2;
    }
    if (temp_b == 0)
    {
        is_b_even = true;
    }

    //@ assert is_a_even == (a % 2 == 0);
    //@ assert is_b_even == (b % 2 == 0);
    return is_a_even || is_b_even;
}
