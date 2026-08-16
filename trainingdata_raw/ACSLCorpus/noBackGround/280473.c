#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123 &&
        (k) >= 0);
    ensures \result == true <==> (e - a) <= k;
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int dist;
    bool result;

    //@ assert 0 <= a && a < b && b < c && c < d && d < e && e <= 123;
    //@ assert k >= 0;

    dist = e - a;

    //@ assert dist >= 0 && dist <= 123;
    //@ assert dist == ((e) - (a));

    if (dist <= k) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == true <==> dist <= k;
    return result;
}
