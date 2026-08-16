#include <limits.h>

/*@
    requires (1 <= (a) <= 1000);
    requires (1 <= (b) <= 1000);
    requires (1 <= (c) <= 1000);
    requires (1 <= (d) <= 1000);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    ensures \result == (a < b ? a : b) + (c < d ? c : d);
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int ans;
    
    //@ assert (1 <= (a) <= 1000);
    //@ assert (1 <= (b) <= 1000);
    //@ assert (1 <= (c) <= 1000);
    //@ assert (1 <= (d) <= 1000);
    
    min_ab = a < b ? a : b;
    min_cd = c < d ? c : d;
    
    //@ assert 1 <= min_ab <= 1000;
    //@ assert 1 <= min_cd <= 1000;
    
    ans = min_ab + min_cd;
    
    //@ assert 2 <= ans <= 2000;
    //@ assert ans <= a + b + c + d;
    
    return ans;
}
