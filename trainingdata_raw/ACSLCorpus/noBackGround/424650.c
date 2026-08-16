#include <stdbool.h>

/*@
    requires 0 <= a < b < c < d < e <= 123;
    requires 0 <= k <= 123;
    ensures \result == true <==> ((b) - (a) <= (k) && (c) - (a) <= (k) && (d) - (a) <= (k) && (e) - (a) <= (k) &&
        (c) - (b) <= (k) && (d) - (b) <= (k) && (e) - (b) <= (k) &&
        (d) - (c) <= (k) && (e) - (c) <= (k) && (e) - (d) <= (k));
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 0 <= a && a <= 123;
    //@ assert 0 <= b && b <= 123;
    //@ assert 0 <= c && c <= 123;
    //@ assert 0 <= d && d <= 123;
    //@ assert 0 <= e && e <= 123;
    //@ assert 0 <= k && k <= 123;

    if (b - a > k || c - a > k || d - a > k || e - a > k ||
        c - b > k || d - b > k || e - b > k ||
        d - c > k || e - c > k || e - d > k)
    {
        result = false;
    }
    else
    {
        //@ assert ((b) - (a) <= (k) && (c) - (a) <= (k) && (d) - (a) <= (k) && (e) - (a) <= (k) &&         (c) - (b) <= (k) && (d) - (b) <= (k) && (e) - (b) <= (k) &&         (d) - (c) <= (k) && (e) - (c) <= (k) && (e) - (d) <= (k));
        result = true;
    }

    return result;
}
