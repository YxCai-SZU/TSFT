#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    ensures \result >= 0;
    ensures \result == (a * 3) + b;
    ensures \result == (a * 2) + b + a;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert a * 3 >= 0;
    //@ assert a * 3 <= 300;
    //@ assert (a * 3) + b >= 0;
    //@ assert (a * 3) + b <= 400;
    //@ assert (a * 2) + b + a <= 400;
    
    return (a * 3) + b;
}
