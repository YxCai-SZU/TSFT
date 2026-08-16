#include <stdbool.h>

/*@
    requires 10 <= n && n <= 99;
    ensures \result == (((n) % 10) == 9 || ((((n) / 10)) % 10) == 9);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    unsigned long a;
    unsigned long b;
    bool ans;

    //@ assert n / 10 <= 9;
    //@ assert (n / 10) % 10 <= 9;

    a = n % 10;
    b = (n / 10) % 10;
    ans = (a == 9) || (b == 9);
    return ans;
}
