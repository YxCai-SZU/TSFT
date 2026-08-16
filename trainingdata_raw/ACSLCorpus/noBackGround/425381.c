#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \forall size_t i; 0 <= i < (n) ==> (v)[i] >= 1 && (v)[i] <= 1000000000);
    ensures \result >= 0 && \result <= 100000000000000000;
    assigns \nothing;
*/
int64_t func(const int64_t *v, size_t n) {
    int64_t ans = 0;
    int64_t prev_height = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop invariant prev_height >= 0;
        loop invariant prev_height <= 1000000000;
        loop invariant ans <= 100000000000000000;
        loop invariant ans <= ((i) * 1000000000);
        loop invariant \forall size_t j; 0 <= j < i ==> v[j] >= 1 && v[j] <= 1000000000;
        loop assigns ans, prev_height, i;
        loop variant n - i;
    */
    while (i < n) {
        int64_t a = v[i];
        //@ assert a >= 1 && a <= 1000000000;
        
        if (a - prev_height < 0) {
            //@ assert prev_height - a >= 0;
            ans += prev_height - a;
        } else {
            prev_height = a;
        }
        i++;
    }
    return ans;
}
