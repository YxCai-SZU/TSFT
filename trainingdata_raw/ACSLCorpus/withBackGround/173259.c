#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(int *a, integer N) =
      N >= 1 && N <= 100 &&
      \forall integer i; 0 <= i < N ==> a[i] >= 1 && a[i] <= 100;
*/

/*@ predicate ans_bounds(integer ans, integer i, integer N) =
      ans >= 0 && ans <= i && i <= N;
*/

/*@ lemma loop_invariant_maintained:
      \forall integer i, integer N, int *a, integer ans;
      is_valid_array(a, N) && ans_bounds(ans, i, N) && i < N ==>
      (i % 2 == 0 && a[i] % 2 == 1 ? ans_bounds(ans + 1, i + 1, N) : ans_bounds(ans, i + 1, N));
*/

/*@ requires N >= 1 && N <= 100;
    requires \valid(a + (0 .. N-1));
    requires is_valid_array(a, N);
    ensures \result >= 0 && \result <= N;
    assigns \nothing;
*/
int func(int N, int *a) {
    int ans = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= N;
        loop invariant is_valid_array(a, N);
        loop invariant ans_bounds(ans, i, N);
        loop assigns ans, i;
        loop variant N - i;
    */
    while (i < (size_t)N) {
        int value = a[i];
        //@ assert value >= 1 && value <= 100;
        
        if ((i & 1) == 0 && (value & 1) == 1) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
