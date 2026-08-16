#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(int64_t *a, integer len) =
        1 <= len && len <= 100 &&
        \forall integer i; 0 <= i < len ==> 1 <= a[i] && a[i] <= 100;

    predicate ans_property(int64_t *a, integer len, integer i, int64_t ans) =
        ans >= 0 &&
        \exists integer x, y; 0 <= x < i && 0 <= y < i && ans == a[y] - a[x];

    predicate min_property(int64_t *a, integer len, integer i, int64_t min_v) =
        min_v >= 1 && min_v <= 100 &&
        \exists integer j; 0 <= j < i && min_v == a[j];
*/

/*@
    requires valid_array(a, len);
    ensures \result >= 0;
    ensures \exists integer x, y; 0 <= x < len && 0 <= y < len && \result == a[y] - a[x];
*/
int64_t func(int64_t *a, size_t len)
{
    int64_t ans = 0;
    int64_t min_v = a[0];
    size_t i = 1;

    //@ assert valid_array(a, len);
    //@ assert 1 <= i && i <= len;
    //@ assert ans_property(a, len, i, ans);
    //@ assert min_property(a, len, i, min_v);

    /*@
        loop invariant 1 <= i && i <= len;
        loop invariant valid_array(a, len);
        loop invariant ans_property(a, len, i, ans);
        loop invariant min_property(a, len, i, min_v);
        loop assigns i, ans, min_v;
        loop variant len - i;
    */
    while (i < len)
    {
        int64_t v = a[i];
        
        if (ans < v - min_v)
        {
            ans = v - min_v;
        }
        
        if (min_v > v)
        {
            min_v = v;
        }
        
        i += 1;
        
        //@ assert ans_property(a, len, i, ans);
        //@ assert min_property(a, len, i, min_v);
    }
    
    //@ assert ans_property(a, len, len, ans);
    return ans;
}
