#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    return a * b;
}

/*@
    requires (1 <= (x) <= 100) && (1 <= (y) <= 100);
    ensures \result == (((x) * (y)) >= 100);
    assigns \nothing;
*/
bool func2(unsigned int x, unsigned int y)
{
    //@ assert (1 <= (x) <= 100);
    //@ assert (1 <= (y) <= 100);
    //@ assert ((x) * (y)) <= 10000;
    return (x * y) >= 100;
}
