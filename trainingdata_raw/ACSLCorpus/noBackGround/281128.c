#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int min_ab;
    unsigned int min_cd;
    unsigned int ans;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    
    min_ab = (a < b) ? a : b;
    //@ assert min_ab == (((a) < (b)) ? (a) : (b));
    
    min_cd = (c < d) ? c : d;
    //@ assert min_cd == (((c) < (d)) ? (c) : (d));
    
    //@ assert 1 <= min_ab <= 10000;
    //@ assert 1 <= min_cd <= 10000;
    
    ans = min_ab + min_cd;
    //@ assert ans == (((a) < (b)) ? (a) : (b)) + (((c) < (d)) ? (c) : (d));
    
    //@ assert 2 <= ans <= 20000;
    
    return ans;
}
