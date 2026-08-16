#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) > 0 && (k) > 0 &&
        (n) <= 100000 && (k) <= 500 &&
        \valid((heights) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (heights)[i] > 0 && (heights)[i] <= 500);
    assigns \nothing;
    ensures 0 <= \result && \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (heights[i] >= k ==> \result >= 1);
    ensures \forall integer i; 0 <= i < n ==> (heights[i] < k ==> \result >= 0);
*/
size_t func(size_t n, size_t k, size_t *heights)
{
    size_t ans = 0;
    size_t i = 0;

    /*@
        loop invariant (0 <= (i) && (i) <= (n) &&
        0 <= (ans) && (ans) <= (i) &&
        \forall integer j; 0 <= j < (i) ==> ((heights)[j] >= (k) ==> (ans) >= 1) &&
        \forall integer j; 0 <= j < (i) ==> ((heights)[j] < (k) ==> (ans) >= 0));
        loop invariant ((n) > 0 && (k) > 0 &&
        (n) <= 100000 && (k) <= 500 &&
        \valid((heights) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (heights)[i] > 0 && (heights)[i] <= 500);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n)
    {
        size_t h = heights[i];
        if (h >= k)
        {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
