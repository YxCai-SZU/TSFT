#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == true <==> (((a + b + c) % 3 == 0) &&
        ((a + b + c) / 3 >= (a)) &&
        ((a + b + c) / 3 >= (b)) &&
        ((a + b + c) / 3 >= (c)));
    assigns \nothing;
*/
bool can_distribute_evenly(unsigned long a, unsigned long b, unsigned long c)
{
    unsigned long sum;
    unsigned long base_length;

    sum = a + b + c;

    if (sum % 3 != 0)
    {
        return false;
    }

    base_length = sum / 3;

    //@ assert base_length == (a + b + c) / 3;

    if (base_length < a || base_length < b || base_length < c)
    {
        return false;
    }

    return true;
}
