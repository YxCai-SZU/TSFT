#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_in_range(int *v, integer n, integer i) =
        \forall integer j; 0 <= j < i ==> (v[j] >= 10 && v[j] <= 200);
*/

/*@
    requires 1 <= n;
    requires \valid(v + (0 .. n-1));
    ensures \result == true <==> all_in_range(v, n, n);
    assigns \nothing;
*/
bool func(size_t n, int *v) {
    bool all_good = true;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant all_good == true <==> all_in_range(v, n, i);
        loop assigns i, all_good;
        loop variant n - i;
    */
    while (i < n) {
        int ai = v[i];
        if (!(ai >= 10 && ai <= 200)) {
            all_good = false;
        }
        i++;
    }
    return all_good;
}
