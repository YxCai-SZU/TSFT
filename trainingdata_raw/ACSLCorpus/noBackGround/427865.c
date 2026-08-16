#include <stdbool.h>
#include <limits.h>

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures (a < 10 && b < 10) ==> \result == a * b;
    ensures (a >= 10 || b >= 10) ==> \result == -1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    if (a < 10 && b < 10)
    {
        //@ assert a * b <= 100;
        result = a * b;
    }
    else
    {
        //@ assert a * b <= 400;
        result = -1;
    }
    
    return result;
}
