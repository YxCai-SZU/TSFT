#include <stdbool.h>

/*@ predicate valid_vec(int *v) =
      \valid(v) && v[0] >= 1 && v[0] <= 20 &&
      v[1] >= 1 && v[1] <= 20 &&
      v[2] >= 1 && v[2] <= 20;
*/

/*@ logic integer vec_sum(integer a, integer b, integer c) = a + b + c; */

/*@ lemma ans_non_negative:
      \forall integer a,b,c,sum,max_abc,ans;
      a >= 1 && a <= 20 && b >= 1 && b <= 20 && c >= 1 && c <= 20 &&
      sum == a + b + c &&
      max_abc == (a >= b ? (a >= c ? a : c) : (b >= c ? b : c)) &&
      ans == (sum - max_abc == max_abc ? sum - max_abc : sum - max_abc - 1) ==>
      ans >= 0;
*/

/*@ lemma ans_bounded_by_sum:
      \forall integer a,b,c,sum,max_abc,ans;
      a >= 1 && a <= 20 && b >= 1 && b <= 20 && c >= 1 && c <= 20 &&
      sum == a + b + c &&
      max_abc == (a >= b ? (a >= c ? a : c) : (b >= c ? b : c)) &&
      ans == (sum - max_abc == max_abc ? sum - max_abc : sum - max_abc - 1) ==>
      ans <= a + b + c;
*/

/*@
  requires valid_vec(v);
  ensures \result >= 0;
  ensures \result <= v[0] + v[1] + v[2];
*/
int func(int *v) {
    int a;
    int b;
    int c;
    int min_ab;
    int min_abc;
    int max_ab;
    int max_abc;
    int sum;
    int ans;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert a >= 1 && a <= 20;
    //@ assert b >= 1 && b <= 20;
    //@ assert c >= 1 && c <= 20;

    min_ab = a;
    if (b < min_ab) {
        min_ab = b;
    }
    //@ assert min_ab == (a <= b ? a : b);

    min_abc = c < min_ab ? c : min_ab;
    //@ assert min_abc == (c <= min_ab ? c : min_ab);

    max_ab = a;
    if (b > max_ab) {
        max_ab = b;
    }
    //@ assert max_ab == (a >= b ? a : b);

    max_abc = c > max_ab ? c : max_ab;
    //@ assert max_abc == (c >= max_ab ? c : max_ab);

    sum = a + b + c;
    //@ assert sum == vec_sum(a, b, c);

    if (sum - max_abc == max_abc) {
        ans = sum - max_abc;
    } else {
        ans = sum - max_abc - 1;
    }
    //@ assert ans == (sum - max_abc == max_abc ? sum - max_abc : sum - max_abc - 1);

    //@ assert ans >= 0;
    //@ assert ans <= v[0] + v[1] + v[2];

    return ans;
}
