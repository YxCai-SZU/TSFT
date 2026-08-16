#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_binary(int *x, integer len) =
      \forall integer j; 0 <= j < len ==> (x[j] == 0 || x[j] == 1);
*/

/*@ predicate count_condition(int *x, integer len, integer i, integer ans) =
      \forall integer j; 0 <= j < i && x[j] == 1 ==> ans >= 1;
*/

/*@ lemma ans_bounds:
      \forall int *x, integer len, integer i, integer ans;
      is_binary(x, len) && 0 <= i <= len && 0 <= ans <= i ==> 0 <= ans <= len;
*/

/*@
    requires \valid(x + (0 .. 4));
    requires is_binary(x, 5);
    ensures 0 <= \result <= 5;
    ensures \forall integer i; 0 <= i < 5 && x[i] == 1 ==> \result >= 1;
    assigns \nothing;
*/
int func(int *x) {
    int ans = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= 5;
        loop invariant 0 <= ans <= i;
        loop invariant is_binary(x, 5);
        loop invariant count_condition(x, 5, i, ans);
        loop assigns ans, i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 1) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
