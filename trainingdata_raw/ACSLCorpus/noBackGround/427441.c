#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 300);
    ensures \result == true <==> (((a) <= (k) && (k) <= (a) + (b)) || ((k) <= (a) && (a) <= (b) && (b) + (a) <= (k)));
    assigns \nothing;
*/
bool func(int a, int b, int c, int k)
{
    int p;
    int q;
    int r;

    //@ assert 1 <= a && a <= 100;
    
    if (a >= k)
    {
        p = k;
    }
    else
    {
        p = a;
    }

    //@ assert p == (a >= k ? k : a);
    
    if (k - p >= b)
    {
        q = b;
    }
    else
    {
        q = k - p;
    }

    //@ assert q == (k - p >= b ? b : k - p);
    
    r = k - p - q;

    //@ assert r >= 0;
    
    if ((a <= k && k <= a + b) || (k <= a && a <= b && b + a <= k))
    {
        return true;
    }
    else
    {
        return false;
    }
}
