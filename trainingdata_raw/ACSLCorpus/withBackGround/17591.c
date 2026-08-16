#include <stdbool.h>

/*@ predicate is_valid_range(integer n) = 1 <= n <= 1000000; */

/*@ predicate vector_bounds(int *v_a, integer n) = 
      \forall integer i; 0 <= i < n ==> 1 <= v_a[i] <= 1000000; */

/*@ lemma count_bounds: 
      \forall integer n, integer count; 
      is_valid_range(n) && 0 <= count <= n ==> 0 <= count <= n; */

/*@
  requires is_valid_range(n);
  requires \valid(v_a + (0 .. n-1));
  requires vector_bounds(v_a, n);
  ensures 0 <= \result <= n;
*/
int func(int n, int *v_a)
{
    int count = 0;
    int i = 0;
    int a = 0;
    
    /*@
      loop invariant 0 <= a <= n;
      loop invariant 0 <= i <= a;
      loop invariant count <= i;
      loop invariant vector_bounds(v_a, n);
      loop invariant is_valid_range(n);
      loop invariant 0 <= count <= n;
      loop assigns a, i, count;
    */
    while (a < n)
    {
        int index = a;
        int value = v_a[index];
        
        //@ assert 0 <= index < n;
        //@ assert 1 <= value <= 1000000;
        
        if (value == i + 1)
        {
            i = i + 1;
            count = count + 1;
        }
        a = a + 1;
    }
    return count;
}
