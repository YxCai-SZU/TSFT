#include <stdbool.h>

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    requires 1 <= c <= 20;
    requires 1 <= d <= 20;
    requires 1 <= e <= 20;
    ensures \result <==> ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
 */
bool func(int a, int b, int c, int d, int e)
{
    bool ok;
    ok = true;
    //@ assert ok == true;
    
    ok = ok && a < b;
    //@ assert ok == (a < b);
    
    ok = ok && b < c;
    //@ assert ok == (a < b && b < c);
    
    ok = ok && c < d;
    //@ assert ok == (a < b && b < c && c < d);
    
    ok = ok && d < e;
    //@ assert ok == (a < b && b < c && c < d && d < e);
    
    return ok;
}
