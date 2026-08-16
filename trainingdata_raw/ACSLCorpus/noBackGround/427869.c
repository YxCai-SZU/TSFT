#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    assigns \nothing;
*/
bool func(long a, long b)
{
    unsigned long a_unsigned;
    unsigned long b_unsigned;
    unsigned long sum_unsigned;
    unsigned long a_mod_3;
    unsigned long b_mod_3;
    unsigned long sum_mod_3;
    bool result;

    a_unsigned = (a < 0) ? (unsigned long)(-a) : (unsigned long)a;
    b_unsigned = (b < 0) ? (unsigned long)(-b) : (unsigned long)b;
    sum_unsigned = (a + b < 0) ? (unsigned long)(-(a + b)) : (unsigned long)(a + b);

    //@ assert sum_unsigned <= 200;

    a_mod_3 = a_unsigned % 3;
    b_mod_3 = b_unsigned % 3;
    sum_mod_3 = sum_unsigned % 3;

    if (a_mod_3 == 0 || b_mod_3 == 0 || sum_mod_3 == 0)
    {
        result = true;
    }
    else
    {
        //@ assert a_mod_3 != 0 && b_mod_3 != 0 && sum_mod_3 != 0;
        result = false;
    }

    return result;
}
