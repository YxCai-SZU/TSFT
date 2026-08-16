#include <stdbool.h>

/*@
    requires 0 <= x <= 1000000000000000000;
    requires 0 <= y <= 1000000000000000000;
    ensures \result == true <==> ((x) == (y) || (x) == (y) + 1 || (y) == (x) + 1);
    assigns \nothing;
*/
bool func(long long x, long long y)
{
    long long d;
    
    //@ assert 0 <= x <= 1000000000000000000;
    //@ assert 0 <= y <= 1000000000000000000;
    
    if (x > y) {
        d = x - y;
        //@ assert d == x - y;
    } else {
        d = y - x;
        //@ assert d == y - x;
    }
    
    //@ assert d >= 0;
    //@ assert d <= 1000000000000000000;
    
    if (d == 0 || d == 1) {
        //@ assert d == 0 || d == 1;
        return true;
    } else {
        //@ assert d != 0 && d != 1;
        return false;
    }
}
