#include <stdbool.h>

/*@
    requires (0 <= (a) <= 123 && 0 <= (b) <= 123 && 0 <= (c) <= 123 &&
        0 <= (d) <= 123 && 0 <= (e) <= 123 && 0 <= (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> (e - a) <= k;
    ensures \result == false <==> (e - a) > k;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int dist;
    int max_dist;
    bool result;

    //@ assert 0 <= a <= 123 && 0 <= b <= 123 && 0 <= c <= 123;
    //@ assert 0 <= d <= 123 && 0 <= e <= 123 && 0 <= k <= 123;
    //@ assert a < b && b < c && c < d && d < e;

    dist = e - a;
    //@ assert 0 <= dist <= 123;

    if (dist > k) {
        max_dist = dist;
    } else {
        max_dist = k;
    }
    //@ assert 0 <= max_dist <= 123;

    if (max_dist <= k) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == ((e - a) <= k);
    return result;
}
