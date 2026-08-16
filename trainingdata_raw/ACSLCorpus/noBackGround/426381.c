#include <limits.h>

/*@
    requires (3 <= (n) && (n) <= 2000 &&
        1 <= (x) && (x) <= (n) &&
        1 <= (y) && (y) <= (n) &&
        (x) + 1 < (y));
    ensures \result >= 0;
    ensures \result <= n * n;
    assigns \nothing;
*/
int func(int n, int x, int y)
{
    int x_local;
    int y_local;
    int ans;
    int abs_diff;
    int tmp;

    //@ assert (3 <= (n) && (n) <= 2000 &&         1 <= (x) && (x) <= (n) &&         1 <= (y) && (y) <= (n) &&         (x) + 1 < (y));
    
    x_local = x - 1;
    y_local = y - 1;
    
    //@ assert 0 <= x_local && x_local < n;
    //@ assert 0 <= y_local && y_local < n;
    //@ assert x_local + 1 < y_local;
    
    //@ assert n * n <= 2000 * 2000;
    
    ans = n * n;
    
    if (y_local - x_local < 0)
    {
        abs_diff = -(y_local - x_local);
    }
    else
    {
        abs_diff = y_local - x_local;
    }
    
    //@ assert abs_diff == ((y_local) < (x_local) ? (x_local) - (y_local) : (y_local) - (x_local));
    
    if (ans < abs_diff)
    {
        tmp = ans;
    }
    else
    {
        tmp = abs_diff;
    }
    
    ans = tmp;
    
    //@ assert ans >= 0;
    //@ assert ans <= n * n;
    
    return ans;
}
