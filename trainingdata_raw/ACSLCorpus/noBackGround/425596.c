#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    int res;
    long long prod_ab;
    long long prod_cd;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    
    // Use long long to avoid overflow during intermediate calculation
    prod_ab = (long long)a * (long long)b;
    prod_cd = (long long)c * (long long)d;
    
    //@ assert prod_ab <= 100000000 && prod_cd <= 100000000;
    
    if (prod_ab > prod_cd) {
        res = (int)prod_ab;
        //@ assert res == ((a) * (b));
    } else {
        res = (int)prod_cd;
        //@ assert res == ((c) * (d));
    }
    
    //@ assert res >= ((a) * (b)) && res >= ((c) * (d));
    return res;
}
