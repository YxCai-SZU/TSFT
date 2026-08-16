#include <stdint.h>

/*@ predicate valid_range(integer n, integer k) = 
      1 <= k <= n <= 50; */

/*@ predicate func_post(integer n, integer k, integer result) = 
      result == n - k + 1; */

/*@ requires valid_range(n, k);
    ensures func_post(n, k, \result);
    assigns \nothing; */
int64_t func(int64_t n, int64_t k)
{
    int64_t result;
    //@ assert valid_range(n, k);
    result = n - k + 1;
    //@ assert func_post(n, k, result);
    return result;
}

/*@ predicate valid_range2(integer n, integer a, integer b) = 
      1 <= n <= 20 && 1 <= a <= 50 && 1 <= b <= 50; */

/*@ logic integer min(integer x, integer y) = 
      x < y ? x : y; */

/*@ predicate func2_post(integer n, integer a, integer b, integer result) = 
      result == min(n * a, b) && result <= n * a && result <= b; */

/*@ lemma product_bound: 
      \forall integer n, integer a; 
      1 <= n <= 20 && 1 <= a <= 50 ==> 1 <= n * a <= 1000; */

/*@ requires valid_range2(n, a, b);
    ensures func2_post(n, a, b, \result);
    assigns \nothing; */
int64_t func2(int64_t n, int64_t a, int64_t b)
{
    int64_t na;
    int64_t result;
    
    //@ assert valid_range2(n, a, b);
    //@ assert 1 <= n * a <= 1000;
    na = n * a;
    
    if (na < b) {
        result = na;
    } else {
        result = b;
    }
    
    //@ assert func2_post(n, a, b, result);
    return result;
}
