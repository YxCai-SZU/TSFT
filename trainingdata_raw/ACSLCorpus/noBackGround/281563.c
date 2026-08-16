#include <stdbool.h>

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires a < b;
    requires b < c;
    requires c < d;
    requires d < e;
    ensures \result == true <==> (
        ((a) - (b) <= (k) || (b) - (a) <= (k)) ||
        ((a) - (c) <= (k) || (c) - (a) <= (k)) ||
        ((a) - (d) <= (k) || (d) - (a) <= (k)) ||
        ((a) - (e) <= (k) || (e) - (a) <= (k)) ||
        ((e) - (a) <= (k) || (a) - (e) <= (k)) ||
        ((e) - (b) <= (k) || (b) - (e) <= (k)) ||
        ((e) - (c) <= (k) || (c) - (e) <= (k)) ||
        ((e) - (d) <= (k) || (d) - (e) <= (k))
    );
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    //@ assert a < b && b < c && c < d && d < e;
    
    if (b - a <= k || c - a <= k || d - a <= k || e - a <= k || 
        a - e <= k || b - e <= k || c - e <= k || d - e <= k) 
    {
        //@ assert b - a <= k || c - a <= k || d - a <= k || e - a <= k || a - e <= k || b - e <= k || c - e <= k || d - e <= k;
        return true;
    } 
    else 
    {
        //@ assert !(b - a <= k || c - a <= k || d - a <= k || e - a <= k || a - e <= k || b - e <= k || c - e <= k || d - e <= k);
        return false;
    }
}
