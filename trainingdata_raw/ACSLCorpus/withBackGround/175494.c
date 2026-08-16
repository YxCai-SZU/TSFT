#include <stdbool.h>

/*@ predicate valid_input(integer a, integer b, integer c) =
      1 <= b && b <= a && a <= 20 &&
      1 <= c && c <= 20;
*/

/*@ logic integer compute_ans(integer a, integer b, integer c) =
      c < (a - b) ? 0 : c - (a - b);
*/

/*@ lemma ans_nonnegative:
      \forall integer a, b, c;
        valid_input(a, b, c) ==> compute_ans(a, b, c) >= 0;
*/

/*@ lemma ans_upper_bound:
      \forall integer a, b, c;
        valid_input(a, b, c) ==> compute_ans(a, b, c) <= a - b + c;
*/

/*@ requires valid_input(a, b, c);
    ensures \result >= 0 && \result <= a - b + c;
*/
int func(int a, int b, int c)
{
    int ans;
    //@ assert a - b >= 0;
    
    if (c < (a - b)) {
        ans = 0;
    } else {
        ans = c - (a - b);
    }
    
    //@ assert ans == compute_ans(a, b, c);
    
    return ans;
}
