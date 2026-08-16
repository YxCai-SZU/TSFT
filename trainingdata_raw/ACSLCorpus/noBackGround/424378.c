#include <limits.h>

/*@
    requires 2 <= a && a <= 100;
    requires 2 <= b && b <= 100;
    ensures \result == a * b - (a + b) + 1;
    ensures \result > 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 2 <= a && a <= 100;
    //@ assert 2 <= b && b <= 100;
    
    //@ assert a * b <= 10000;
    //@ assert a + b <= 200;
    //@ assert a * b >= 4;
    //@ assert a * b - (a + b) + 1 >= 4 - 200 + 1;
    //@ assert a * b - (a + b) + 1 > 0;

    result = a * b - (a + b) + 1;
    return result;
}
