#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    assigns \nothing;
*/
bool func(long a, long b)
{
    unsigned long a_unsigned;
    unsigned long b_unsigned;
    unsigned long sum_unsigned;
    long sum;
    bool result;

    sum = a + b;

    //@ assert a >= 1 && a <= 100;
    a_unsigned = a < 0 ? (unsigned long)(a + 3) : (unsigned long)a;

    //@ assert b >= 1 && b <= 100;
    b_unsigned = b < 0 ? (unsigned long)(b + 3) : (unsigned long)b;

    //@ assert sum == a + b;
    sum_unsigned = sum < 0 ? (unsigned long)(sum + 3) : (unsigned long)sum;

    result = (a_unsigned % 3 == 0) || (b_unsigned % 3 == 0) || (sum_unsigned % 3 == 0);
    return result;
}
