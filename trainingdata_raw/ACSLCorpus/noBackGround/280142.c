#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    //@ assert n - m == 0 || n - m != 0;
    return n == m;
}

/*@
    ensures \result >= -10000 && \result <= 10000;
    assigns \nothing;
*/
int input_number(void)
{
    return 0;
}

/*@
    ensures \result >= -10000 && \result <= 10000;
    assigns \nothing;
*/
int input(void)
{
    return 0;
}
