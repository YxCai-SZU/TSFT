#include <limits.h>

/*@ predicate has_profit_cond(integer actual_cost, integer sale_amount) =
      actual_cost >= 0 && sale_amount >= 0;
*/

/*@ predicate has_profit_ensures(integer actual_cost, integer sale_amount, integer result) =
      result == (sale_amount > actual_cost);
*/

/*@
  requires has_profit_cond(actual_cost, sale_amount);
  ensures has_profit_ensures(actual_cost, sale_amount, \result);
*/
int has_profit(long long actual_cost, long long sale_amount) {
    //@ assert actual_cost >= 0 && sale_amount >= 0;
    return sale_amount > actual_cost;
}

/*@ predicate min_of_three_cond(integer a, integer b, integer c) =
      a >= LLONG_MIN && a <= LLONG_MAX &&
      b >= LLONG_MIN && b <= LLONG_MAX &&
      c >= LLONG_MIN && c <= LLONG_MAX;
*/

/*@ predicate min_of_three_ensures(integer a, integer b, integer c, integer result) =
      result <= a && result <= b && result <= c &&
      (result == a || result == b || result == c);
*/

/*@
  requires min_of_three_cond(a, b, c);
  ensures min_of_three_ensures(a, b, c, \result);
*/
long long min_of_three(long long a, long long b, long long c) {
    long long min_ab;
    long long result;
    
    //@ assert a >= LLONG_MIN && a <= LLONG_MAX;
    //@ assert b >= LLONG_MIN && b <= LLONG_MAX;
    //@ assert c >= LLONG_MIN && c <= LLONG_MAX;
    
    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    
    //@ assert min_ab <= a && min_ab <= b;
    //@ assert min_ab == a || min_ab == b;
    
    if (min_ab < c) {
        result = min_ab;
    } else {
        result = c;
    }
    
    //@ assert result <= a && result <= b && result <= c;
    //@ assert result == a || result == b || result == c;
    return result;
}

/*@ predicate func_cond(integer r) = 1 <= r && r <= 100; */

/*@ predicate func_ensures(integer r, integer result) = result == 3 * r * r; */

/*@ lemma func_lemma: \forall integer r; 1 <= r && r <= 100 ==> 3 * r * r <= 300 * 100; */

/*@
  requires func_cond(r);
  ensures func_ensures(r, \result);
*/
long long func(long long r) {
    long long result;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 300 * 100;
    
    result = 3 * r * r;
    
    //@ assert result == 3 * r * r;
    return result;
}
