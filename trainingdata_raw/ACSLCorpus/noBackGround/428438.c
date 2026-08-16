#include <limits.h>

/*@
    requires a != b;
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    requires 1 <= c <= 20;
    requires 1 <= d <= 20;
    ensures \result >= 0;
    ensures \result <= 40;
*/
int func(int a, int b, int c, int d) {
    int m;
    int n;
    int ans;
    
    //@ assert (1 <= (a) <= 20);
    
    if (a > b) {
        m = a - b;
    } else {
        m = b - a;
    }
    
    //@ assert m == (((a) > (b)) ? ((a) - (b)) : ((b) - (a)));
    
    if (c > d) {
        n = c - d;
    } else {
        n = d - c;
    }
    
    //@ assert n == (((c) > (d)) ? ((c) - (d)) : ((d) - (c)));
    
    if (m > n) {
        ans = m + n;
    } else {
        ans = n + m;
    }
    
    //@ assert ans == (((((a)) > ((b))) ? (((a)) - ((b))) : (((b)) - ((a)))) > ((((c)) > ((d))) ? (((c)) - ((d))) : (((d)) - ((c)))) ?          (((((a)) > ((b))) ? (((a)) - ((b))) : (((b)) - ((a)))) + ((((c)) > ((d))) ? (((c)) - ((d))) : (((d)) - ((c))))) :          (((((c)) > ((d))) ? (((c)) - ((d))) : (((d)) - ((c)))) + ((((a)) > ((b))) ? (((a)) - ((b))) : (((b)) - ((a))))));
    
    return ans;
}
