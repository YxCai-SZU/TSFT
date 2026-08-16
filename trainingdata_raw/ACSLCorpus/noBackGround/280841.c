#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    return a * b;
}

/*@
    requires (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func2(int a, int b)
{
    //@ assert (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    //@ assert 1 <= ((a) * (b));
    //@ assert ((a) * (b)) <= 10000;
    return a * b;
}

/*@
    requires (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func3(int a, int b)
{
    //@ assert (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    //@ assert 1 <= ((a) * (b));
    //@ assert ((a) * (b)) <= 10000;
    return a * b;
}
