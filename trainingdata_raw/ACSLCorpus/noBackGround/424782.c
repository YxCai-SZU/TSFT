#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> (a)[j] >= 1 && (a)[j] <= 1000000000);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int32_t func(size_t n, const int64_t *a) {
    int32_t count = 0;
    int64_t b = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant b >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] <= b;
        loop assigns i, count, b;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] > b) {
            //@ assert a[i] > b;
            count++;
            b = a[i];
            //@ assert \forall integer k; 0 <= k < i ==> a[k] <= b;
        }
        i++;
    }
    return count;
}
