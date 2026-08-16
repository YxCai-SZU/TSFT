#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= n;
    requires \valid(a + (0 .. n-1));
    assigns \nothing;
    ensures \result == true <==> (\forall size_t j; 0 <= j < (n) ==>
            ((a)[j] % 2 == 1) || ((a)[j] % 3 == 0) || ((a)[j] % 5 == 0));
*/
bool func(size_t n, int *a) {
    bool ans = true;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == true <==> (\forall size_t j; 0 <= j < (i) ==>
            ((a)[j] % 2 == 1) || ((a)[j] % 3 == 0) || ((a)[j] % 5 == 0));
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        int ai = a[i];
        if (!(ai % 2 == 1 || ai % 3 == 0 || ai % 5 == 0)) {
            ans = false;
        }
        i++;
    }
    return ans;
}
