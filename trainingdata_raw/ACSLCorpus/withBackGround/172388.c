#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_inputs(integer N, int64_t *inputs) =
        N >= 1 && N <= 200000 &&
        \valid_read(inputs + (0 .. N-1)) &&
        \forall integer i; 0 <= i < N ==> inputs[i] >= 1 && inputs[i] <= 200000;

    predicate loop_invariant_ans(integer i, integer ans) =
        ans >= 0 && ans <= i;

    predicate loop_invariant_acc(integer i, integer N, integer acc) =
        acc >= 0 && acc <= 200000 * i && acc <= 200000 * N;

    lemma acc_bound_preserved:
        \forall integer i, integer N, integer acc, integer p;
        i >= 0 && i < N && N >= 1 && N <= 200000 &&
        acc >= 0 && acc <= 200000 * i && acc <= 200000 * N &&
        p >= 1 && p <= 200000 ==>
        (acc + p >= p ? acc + p - p : p) >= 0 &&
        (acc + p >= p ? acc + p - p : p) <= 200000 * (i + 1) &&
        (acc + p >= p ? acc + p - p : p) <= 200000 * N;
*/

/*@
    requires valid_inputs(N, inputs);
    assigns \nothing;
    ensures \result >= 0 && \result <= N;
*/
int64_t func(size_t N, const int64_t *inputs) {
    int64_t ans = 0;
    int64_t acc = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= N;
        loop invariant loop_invariant_ans(i, ans);
        loop invariant loop_invariant_acc(i, N, acc);
        loop invariant valid_inputs(N, inputs);
        loop assigns i, ans, acc;
        loop variant N - i;
    */
    while (i < N) {
        int64_t p = inputs[i];
        
        //@ assert p >= 1 && p <= 200000;
        
        if (acc + p >= p) {
            //@ assert acc + p - p >= 0;
            acc = acc + p - p;
            ans += 1;
        } else {
            //@ assert p >= 0;
            acc = p;
        }
        
        //@ assert loop_invariant_acc(i + 1, N, acc);
        i += 1;
    }
    
    //@ assert ans >= 0 && ans <= N;
    return ans;
}
