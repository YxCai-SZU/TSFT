#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a && \result >= b && \result >= c && \result >= d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int res;
    
    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    
    if (a > b) {
        res = a;
    } else {
        res = b;
    }
    
    //@ assert res == ((a) > (b) ? (a) : (b));
    //@ assert res >= a && res >= b;
    
    if (res > c) {
        // res unchanged
    } else {
        res = c;
    }
    
    //@ assert res == ((((a) > (b) ? (a) : (b))) > (c) ? (((a) > (b) ? (a) : (b))) : (c));
    //@ assert res >= a && res >= b && res >= c;
    
    if (res > d) {
        // res unchanged
    } else {
        res = d;
    }
    
    //@ assert res == ((((((a) > (b) ? (a) : (b))) > (c) ? (((a) > (b) ? (a) : (b))) : (c))) > (d) ? (((((a) > (b) ? (a) : (b))) > (c) ? (((a) > (b) ? (a) : (b))) : (c))) : (d));
    //@ assert res >= a && res >= b && res >= c && res >= d;
    
    // Final verification using the lemma
    //@ assert \forall integer a, b, c, d, m; (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100) && m == ((((((a) > (b) ? (a) : (b))) > (c) ? (((a) > (b) ? (a) : (b))) : (c))) > (d) ? (((((a) > (b) ? (a) : (b))) > (c) ? (((a) > (b) ? (a) : (b))) : (c))) : (d)) ==> (m == a || m == b || m == c || m == d);
    
    return res;
}
