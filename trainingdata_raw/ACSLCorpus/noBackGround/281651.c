#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == ((a % 2 == 1) && (b % 2 == 1));
*/
bool func(unsigned long a, unsigned long b)
{
    bool is_a_odd;
    bool is_b_odd;
    unsigned long temp_a;
    unsigned long temp_b;

    // Calculate a % 2
    temp_a = a;
    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant temp_a % 2 == a % 2;
        loop assigns temp_a;
    */
    while (temp_a >= 2)
    {
        temp_a -= 2;
    }
    is_a_odd = (temp_a == 1);

    // Calculate b % 2
    temp_b = b;
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant temp_b % 2 == b % 2;
        loop assigns temp_b;
    */
    while (temp_b >= 2)
    {
        temp_b -= 2;
    }
    is_b_odd = (temp_b == 1);

    return is_a_odd && is_b_odd;
}
