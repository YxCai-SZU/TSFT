#include <stdbool.h>

/*@
    requires (0 <= (a) <= 123) && (0 <= (b) <= 123) && (0 <= (c) <= 123) && (0 <= (d) <= 123) && (0 <= (e) <= 123) && (0 <= (k) <= 123);
    requires ((a) <= (b)) && ((b) <= (c)) && ((c) <= (d)) && ((d) <= (e));
    ensures \result == (((b) - (a)) <= k || ((c) - (a)) <= k || ((d) - (a)) <= k || ((e) - (a)) <= k || ((c) - (b)) <= k || ((d) - (b)) <= k || ((e) - (b)) <= k || ((d) - (c)) <= k || ((e) - (c)) <= k || ((e) - (d)) <= k);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d, unsigned long long e, unsigned long long k)
{
    bool ans = false;

    //@ assert ((a) <= (b));
    //@ assert ((a) <= (c));
    //@ assert ((a) <= (d));
    //@ assert ((a) <= (e));
    //@ assert ((b) <= (c));
    //@ assert ((b) <= (d));
    //@ assert ((b) <= (e));
    //@ assert ((c) <= (d));
    //@ assert ((c) <= (e));
    //@ assert ((d) <= (e));

    if (b - a <= k)
    {
        ans = true;
    }
    if (c - a <= k)
    {
        ans = true;
    }
    if (d - a <= k)
    {
        ans = true;
    }
    if (e - a <= k)
    {
        ans = true;
    }
    if (c - b <= k)
    {
        ans = true;
    }
    if (d - b <= k)
    {
        ans = true;
    }
    if (e - b <= k)
    {
        ans = true;
    }
    if (d - c <= k)
    {
        ans = true;
    }
    if (e - c <= k)
    {
        ans = true;
    }
    if (e - d <= k)
    {
        ans = true;
    }
    return ans;
}
