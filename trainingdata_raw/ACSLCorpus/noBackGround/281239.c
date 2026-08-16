#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int s1;
    int s2;
    int res;
    
    //@ assert ((a) * (b)) <= INT_MAX;
    s1 = a * b;
    
    //@ assert ((c) * (d)) <= INT_MAX;
    s2 = c * d;
    
    //@ assert s1 == ((a) * (b));
    //@ assert s2 == ((c) * (d));
    
    if (s1 >= s2) {
        res = s1;
    } else {
        res = s2;
    }
    
    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    return res;
}
