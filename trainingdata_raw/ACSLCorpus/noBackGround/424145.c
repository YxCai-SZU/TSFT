#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures 1 <= \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int m;
    int l;
    int res;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a > b) {
        m = a;
    } else {
        m = b;
    }
    
    //@ assert m == (a > b ? a : b);
    
    if (m < c) {
        m = c;
    }
    
    //@ assert m >= a && m >= b && m >= c;
    //@ assert m <= 100;
    
    l = 3 * m - (a + b + c);
    
    //@ assert l == 3 * m - (a + b + c);
    
    if (l == 0) {
        //@ assert l == 0;
        res = 1;
    } else if (l == 1 || l == 2) {
        //@ assert l == 1 || l == 2;
        res = 2;
    } else {
        //@ assert l > 2;
        res = 3;
    }
    
    //@ assert 1 <= res <= 3;
    return res;
}
