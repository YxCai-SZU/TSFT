#include <stdbool.h>

/*@ predicate is_valid_params(integer n, integer k) =
      n >= 1 && n <= 100000 &&
      k >= 1 && k <= 500;

   predicate valid_array(integer n, int *h) =
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;

   logic integer count_condition(integer h_val, integer k) =
      h_val >= k ? 1 : 0;
*/

/*@ lemma count_bounds:
      \forall integer n, integer k, int *h;
      is_valid_params(n, k) && valid_array(n, h) ==>
      (\forall integer i; 0 <= i < n ==> count_condition(h[i], k) >= 0);
*/

/*@ requires is_valid_params(n, k);
    requires \valid(h + (0 .. n-1));
    requires valid_array(n, h);
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result >= 1);
    ensures \forall integer i; 0 <= i < n ==> (h[i] < k ==> \result >= 0);
*/
int func(int n, int k, int *h)
{
    int count = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant index > 0 ==> 
            \forall integer i; 0 <= i < index ==> (h[i] >= k ==> count >= 1);
        loop invariant index > 0 ==> 
            \forall integer i; 0 <= i < index ==> (h[i] < k ==> count >= 0);
        loop invariant is_valid_params(n, k);
        loop invariant valid_array(n, h);
        loop invariant count <= index;
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n)
    {
        //@ assert 0 <= index < n;
        if (h[index] >= k)
        {
            count = count + 1;
        }
        index = index + 1;
        //@ assert count <= index;
    }
    return count;
}
