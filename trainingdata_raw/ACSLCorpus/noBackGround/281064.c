#include <stdbool.h>

/*@
    requires 1 <= d <= 10000;
    requires 1 <= t <= 10000;
    requires 1 <= s <= 10000;
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    unsigned int product;
    bool ret_val;

    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    product = t * s;
    if (d <= product) {
        ret_val = true;
    } else {
        ret_val = false;
    }
    return ret_val;
}

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result <==> ((a + b + c) % 2 == 0);
    assigns \nothing;
*/
bool is_sum_even(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    bool result;

    sum = a + b + c;
    //@ assert (sum % 2 == 0) <==> ((sum) % 2 == 0);
    result = (sum % 2 == 0);
    return result;
}
