#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, size_t n) =
      n > 0 && n <= 100 &&
      \forall size_t i; 0 <= i < n ==> a[i] > 0 && a[i] <= 100;
*/

/*@ predicate loop_invariant(int *a, size_t n, size_t i, int ans) =
      i <= n &&
      ans >= 0 &&
      ans <= (int)i &&
      \forall size_t j; 0 <= j < i ==> a[j] > 0 && a[j] <= 100;
*/

/*@ lemma ans_bound_lemma:
      \forall int *a, size_t n, size_t i, int ans;
      valid_array(a, n) && loop_invariant(a, n, i, ans) ==> ans <= (int)n;
*/

/*@ requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires valid_array(a, n);
    ensures \result >= 0 && \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, const int *a) {
    int ans = 0;
    size_t i = 0;
    
    /*@ loop invariant loop_invariant(a, n, i, ans);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        int ai = a[i];
        //@ assert ai > 0 && ai <= 100;
        if ((i & 1) == 0 && (ai & 1) == 1) {
            ans += 1;
        }
        i += 1;
    }
    
    //@ assert ans <= (int)n;
    return ans;
}
