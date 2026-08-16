#include <limits.h>

/*@ predicate is_valid_params(integer p, integer q, integer r) =
      1 <= p <= 100 &&
      1 <= q <= 100 &&
      1 <= r <= 100;
*/

/*@ logic integer sum_of_three(integer p, integer q, integer r) =
      p + q + r;
*/

/*@ lemma answer_bound:
      \forall integer p, q, r, answer;
      is_valid_params(p, q, r) &&
      (answer == p + q || answer == q + r || answer == p + r) ==>
      answer <= sum_of_three(p, q, r);
*/

/*@ requires is_valid_params(p, q, r);
    ensures \result <= sum_of_three(p, q, r);
    ensures \result == p + q || \result == q + r || \result == p + r;
    assigns \nothing;
*/
int func(int p, int q, int r)
{
    int answer;
    
    //@ assert is_valid_params(p, q, r);
    
    if (p + q < q + r && p + q < p + r) {
        answer = p + q;
        //@ assert answer == p + q;
    } else if (q + r < p + r) {
        answer = q + r;
        //@ assert answer == q + r;
    } else {
        answer = p + r;
        //@ assert answer == p + r;
    }
    
    //@ assert answer == p + q || answer == q + r || answer == p + r;
    //@ assert answer <= sum_of_three(p, q, r);
    
    return answer;
}
