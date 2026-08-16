#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    return a + b >= c;
}

/*@
    requires (1 <= (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int func2(int x)
{
    //@ assert 0 <= x * x <= 10000;
    return x * x;
}
