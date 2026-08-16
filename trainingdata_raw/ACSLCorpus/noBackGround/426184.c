#include <limits.h>

/*@
    requires (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000) && (1 <= (d) <= 5000);
    ensures \result >= 0;
    ensures \result <= (a + b) * (c + d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int p;
    int q;
    int result;
    
    //@ assert (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000) && (1 <= (d) <= 5000);
    
    p = a < b ? a : b;
    q = c < d ? c : d;
    
    //@ assert p == ((a) < (b) ? (a) : (b));
    //@ assert q == ((c) < (d) ? (c) : (d));
    //@ assert (1 <= (p) <= 5000) && (1 <= (q) <= 5000);
    
    //@ assert p * q <= 5000 * 5000;
    //@ assert p * q <= (a + b) * (c + d);
    //@ assert p * q >= 0;
    
    result = p * q;
    
    //@ assert result >= 0;
    //@ assert result <= (a + b) * (c + d);
    
    return result;
}
