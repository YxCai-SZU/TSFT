#include <stdbool.h>

/*@
    requires ((a) >= 1 && (a) <= 100);
    requires ((b) >= 0 && (b) <= (a) * (a));
    ensures \result >= 0;
    ensures \result <= a * a;
    ensures \result == a * a - b;
*/
int func(int a, int b)
{
    //@ assert a * a <= 10000;
    //@ assert a * a >= 1;
    //@ assert a * a - b >= 0;
    
    return a * a - b;
}
