#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int s1;
    int s2;
    int res;
    
    //@ assert a > 0 && b > 0 && c > 0 && d > 0;
    //@ assert a <= 10000 && b <= 10000 && c <= 10000 && d <= 10000;
    
    //@ assert ((a) * (b)) <= 100000000;
    //@ assert ((c) * (d)) <= 100000000;
    
    //@ assert ((a) * (b)) >= 1;
    //@ assert ((c) * (d)) >= 1;
    
    s1 = a * b;
    s2 = c * d;
    
    if (s1 >= s2) {
        res = s1;
    } else {
        res = s2;
    }
    
    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    //@ assert res >= 1;
    
    return res;
}
