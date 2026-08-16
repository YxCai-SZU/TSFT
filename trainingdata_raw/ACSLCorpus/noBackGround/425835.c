#include <stdbool.h>

/*@
    requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 10000;
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert 1 <= a <= 5000;
    //@ assert 1 <= b <= 5000;
    //@ assert 1 <= c <= 10000;
    //@ assert a + b <= 10000;
    return a + b >= c;
}
