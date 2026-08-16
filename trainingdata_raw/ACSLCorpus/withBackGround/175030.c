#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */

/*@ predicate array_valid(int *a, integer n) =
      n > 0 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> a[i] > 0 && a[i] <= 1000000; */

/*@ lemma count_bounds:
      \forall integer n, integer count, integer i;
      n > 0 && n <= 200000 &&
      0 <= i <= n &&
      0 <= count <= i ==>
      count >= 0 && count <= n; */

/*@ requires n > 0 && n <= 200000;
    requires \valid(a + (0 .. n-1));
    requires array_valid(a, n);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
 */
int func(size_t n, int *a)
{
    int count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant array_valid(a, n);
        loop assigns i, count;
        loop variant n - i;
     */
    while (i < n)
    {
        //@ assert 0 <= i < n;
        if (i % 2 == 0 && (a[i] & 1) == 1)
        {
            //@ assert count >= 0 && count <= i;
            count += 1;
            //@ assert count >= 1 && count <= i + 1;
        }
        i += 1;
    }
    //@ assert i == n;
    //@ assert count >= 0 && count <= n;
    return count;
}
