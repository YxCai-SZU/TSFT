#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_params(integer k, integer n) =
      k >= 1 && k <= 300000 &&
      n >= 1 && n <= 300000;
*/

/*@ predicate is_valid_array(unsigned int *h, integer n) =
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@ lemma index_bound:
      \forall integer index, integer n;
      0 <= index <= n ==> index <= n;
*/

/*@ lemma cnt_bound:
      \forall integer cnt, integer index;
      cnt >= 0 && cnt <= index ==> cnt <= index;
*/

/*@ requires 
      is_valid_params(k, n) &&
      n >= 1 && n <= 300000 &&
      \valid(h + (0 .. n-1)) &&
      is_valid_array(h, n);
    ensures
      \result >= 0 && \result <= n;
    assigns \nothing;
*/
unsigned int func(unsigned int k, size_t n, unsigned int *h)
{
    unsigned int cnt = 0;
    size_t index = 0;
    
    /*@ loop invariant 
          0 <= index <= n;
        loop invariant 
          cnt >= 0;
        loop invariant 
          cnt <= index;
        loop assigns 
          cnt, index;
    */
    while (index < n)
    {
        unsigned int hi = h[index];
        
        //@ assert hi >= 1 && hi <= 500;
        
        if (hi >= k)
        {
            cnt = cnt + 1;
        }
        
        index = index + 1;
    }
    
    //@ assert cnt <= n;
    return cnt;
}
