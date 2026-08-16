#include <stddef.h>
#include <stdbool.h>

/*@ predicate valid_range(integer k) = 1 <= k <= 100000; */

/*@ predicate result_constraints(integer result, integer k) =
      result >= 0 || result == -1;
*/

/*@ predicate result_upper_bound(integer result, integer k) =
      result >= 0 ==> result <= k / 2 + 1;
*/

/*@ lemma result_property:
      \forall integer result, integer k;
      valid_range(k) && result_constraints(result, k) && result_upper_bound(result, k) ==>
      (result >= 0 || result == -1) && (result >= 0 ==> result <= k / 2 + 1);
*/

/*@
  requires valid_range(k);
  ensures result_constraints(\result, k);
  ensures result_upper_bound(\result, k);
*/
int func(size_t k) {
    int a[7];
    size_t i;
    size_t m;
    int result;
    
    a[0] = 7;
    a[1] = 5;
    a[2] = 2;
    a[3] = 3;
    a[4] = 7;
    a[5] = 8;
    a[6] = 6;
    
    m = 0;
    i = 0;
    
    /*@
      loop invariant 0 <= i <= k;
      loop invariant m <= 8 * i;
      loop invariant \forall integer j; 0 <= j < i ==> a[j] >= 2 && a[j] <= 8;
      loop assigns i, m;
      loop variant k - i;
    */
    while (i < 7 && i < k) {
        //@ assert 0 <= i < 7;
        //@ assert a[i] >= 2 && a[i] <= 8;
        m += (size_t)a[i];
        i++;
    }
    
    result = -1;
    if (m >= k) {
        result = (int)(m - k);
    }
    
    if (result >= 0) {
        size_t half_k = k / 2;
        if (result > (int)half_k) {
            result = -1;
        }
    }
    
    //@ assert result_constraints(result, k);
    //@ assert result_upper_bound(result, k);
    return result;
}
