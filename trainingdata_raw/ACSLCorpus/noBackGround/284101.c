#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a * b <= c);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    //@ assert a * b <= 10000;
    //@ assert a * b >= 1;
    
    //@ assert a * b <= c || a * b >= c;

    result = (a * b <= c);
    return result;
}
