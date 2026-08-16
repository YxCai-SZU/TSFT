#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_vector(int *v, size_t len) =
        len >= 1 && len <= 200000 &&
        \forall integer i; 0 <= i < len ==> v[i] >= 1 && v[i] <= 1000000000;

    logic integer vector_len{L}(int *v, size_t len) = len;

    lemma ans_bounds:
        \forall int *v, size_t len, integer ans, integer idx;
        valid_vector(v, len) && 0 <= ans && ans <= idx && idx <= len ==>
        ans >= 0 && ans <= len;
*/

/*@
    requires valid_vector(v, len);
    ensures \result >= 0 && \result <= len;
    assigns \nothing;
*/
int func(int *v, size_t len) {
    int ans = 0;
    int p = 0;
    size_t index = 0;

    //@ ghost size_t old_len = len;

    /*@
        loop invariant 0 <= index <= len;
        loop invariant 0 <= ans <= index;
        loop invariant valid_vector(v, old_len);
        loop assigns ans, p, index;
        loop variant len - index;
    */
    while (index < len) {
        int i = v[index];
        if (i == p) {
            ans += 1;
        } else {
            p = i;
        }
        index += 1;
    }

    //@ assert ans >= 0 && ans <= len;
    return ans;
}
