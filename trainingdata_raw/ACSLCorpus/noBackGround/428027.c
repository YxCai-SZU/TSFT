#include <limits.h>

/*@
    requires 100 <= n && n <= 999;
    ensures \result <= 9;
    ensures \result >= 1;
    ensures \result >= n % 10;
    ensures \result >= (n / 10) % 10;
    ensures \result >= n / 100;
    assigns \nothing;
*/
unsigned int max_digit(unsigned int n)
{
    unsigned int n1;
    unsigned int n2;
    unsigned int n3;
    unsigned int max_val;

    n1 = n / 100;
    n2 = (n / 10) % 10;
    n3 = n % 10;

    max_val = n1;

    //@ assert max_val == n / 100;

    if (n2 > max_val)
    {
        max_val = n2;
    }

    //@ assert max_val >= n / 100 && max_val >= (n / 10) % 10;

    if (n3 > max_val)
    {
        max_val = n3;
    }

    //@ assert max_val >= n % 10;

    //@ assert max_val <= 9;
    //@ assert max_val >= 1;

    return max_val;
}
