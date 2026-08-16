#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, integer n) =
      n >= 1 && n <= 100 &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
*/

/*@ predicate loop_invariant(int *a, integer n, integer num, integer count) =
      0 <= num <= n &&
      0 <= count <= num &&
      \forall integer k; 0 <= k < num ==> 
        ((a[k] & 1) == 1 && (count & 1) == 0) ==> count >= 1;
*/

/*@ lemma count_non_negative:
      \forall integer count; 0 <= count ==> count >= 0;
*/

/*@ lemma count_bound_by_n:
      \forall integer count, integer n; 
      0 <= count <= n && n <= 100 ==> count <= 100;
*/

/*@ requires 
        n >= 1 && n <= 100 &&
        \valid(a + (0 .. n-1)) &&
        valid_array(a, n);
      ensures
        0 <= \result <= n;
*/
int func(int n, int *a)
{
  int count = 0;
  unsigned int num = 0;

  /*@ loop invariant loop_invariant(a, n, num, count);
      loop assigns count, num;
      loop variant n - num;
  */
  while (num < (unsigned int)n)
  {
    int x = a[num];
    
    //@ assert x >= 1 && x <= 100;
    
    if ((x & 1) == 1 && (count & 1) == 0)
    {
      count += 1;
    }
    
    num += 1;
  }
  
  //@ assert 0 <= count <= n;
  return count;
}
