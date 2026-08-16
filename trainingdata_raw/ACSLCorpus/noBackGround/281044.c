#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert c <= 100;
    //@ assert a < b && b < c ==> a < c;
    return a < b && b < c;
}
