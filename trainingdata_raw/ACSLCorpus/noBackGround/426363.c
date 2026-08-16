#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 10 &&
        0 <= (b) && (b) <= 10 &&
        0 <= (c) && (c) <= 10 &&
        0 <= (d) && (d) <= 10);
    ensures \result == (a * b <= c * d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    //@ assert 0 <= a && a <= 10;
    //@ assert 0 <= b && b <= 10;
    //@ assert 0 <= c && c <= 10;
    //@ assert 0 <= d && d <= 10;
    
    //@ assert a >= 0 && a <= 10 && b >= 0 && b <= 10 && c >= 0 && c <= 10 && d >= 0 && d <= 10;
    
    //@ assert c * d <= 100;
    //@ assert a * b <= 100;
    
    //@ assert a * b <= c * d || !(a * b <= c * d);
    
    return a * b <= c * d;
}
