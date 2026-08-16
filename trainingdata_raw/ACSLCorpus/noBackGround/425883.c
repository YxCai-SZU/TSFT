#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == (a + c) || \result == (a + d) || \result == (b + c) || \result == (b + d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int ans;
    int min_val;
    
    //@ assert (1 <= (a) && (a) <= 10000);
    
    min_ab = a < b ? a : b;
    //@ assert min_ab == ((a) < (b) ? (a) : (b));
    
    min_cd = c < d ? c : d;
    //@ assert min_cd == ((c) < (d) ? (c) : (d));
    
    ans = min_ab + min_cd;
    //@ assert ans == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    
    min_val = min_ab > min_cd ? min_cd : min_ab;
    //@ assert min_val == ((((a) < (b) ? (a) : (b))) < (((c) < (d) ? (c) : (d))) ? (((a) < (b) ? (a) : (b))) : (((c) < (d) ? (c) : (d))));
    
    if (ans < min_val * 2)
    {
        //@ assert min_val <= 10000;
        return min_val * 2;
    }
    else
    {
        return ans;
    }
}
