#include <limits.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == (a * b * c) + (a * b * c * c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert ((a) >= 0 && (a) <= 100 &&         (b) >= 0 && (b) <= 100 &&         (c) >= 0 && (c) <= 100);
    //@ assert a * b <= 100 * 100;
    //@ assert ((a) * (b) * (c)) <= 100 * 100 * 100;
    //@ assert ((a) * (b) * (c)) * c <= 100 * 100 * 100 * 100;
    //@ assert ((a) * (b) * (c)) + ((a) * (b) * (c)) * c <= INT_MAX;
    
    return (a * b * c) + (a * b * c * c);
}
