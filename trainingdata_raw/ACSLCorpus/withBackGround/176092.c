#include <stdint.h>

/*@ predicate valid_params(integer a, integer b, integer c, integer k) =
      0 <= a && a <= 100000000000000000 &&
      0 <= b && b <= 100000000000000000 &&
      0 <= c && c <= 100000000000000000 &&
      1 <= k && k <= 100000000000000000 &&
      a + b + c >= k;
*/

/*@ logic integer compute_cnt(integer a, integer k) =
      (a >= k) ? k : a;
*/

/*@ logic integer compute_rst(integer k, integer a, integer b) =
      (k - a > b) ? (k - a - b) : 0;
*/

/*@ lemma ans_lower_bound:
      \forall integer a, b, c, k, cnt, rst, ans;
      valid_params(a, b, c, k) ==>
      cnt == compute_cnt(a, k) ==>
      rst == compute_rst(k, a, b) ==>
      ans == cnt - rst ==>
      ans >= -c;
*/

/*@ lemma ans_upper_bound:
      \forall integer a, b, c, k, cnt, rst, ans;
      valid_params(a, b, c, k) ==>
      cnt == compute_cnt(a, k) ==>
      rst == compute_rst(k, a, b) ==>
      ans == cnt - rst ==>
      ans <= a;
*/

/*@ requires valid_params(a, b, c, k);
    ensures \result >= -c && \result <= a;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t cnt;
    int64_t rst;
    int64_t ans;

    //@ assert valid_params(a, b, c, k);
    
    if (a >= k) {
        cnt = k;
    } else {
        cnt = a;
    }
    //@ assert cnt == compute_cnt(a, k);
    
    rst = k - a;
    if (rst > b) {
        rst = rst - b;
    } else {
        rst = 0;
    }
    //@ assert rst == compute_rst(k, a, b);
    
    ans = cnt;
    ans = ans - rst;
    //@ assert ans == cnt - rst;
    
    //@ assert ans >= -c;
    //@ assert ans <= a;
    
    return ans;
}
