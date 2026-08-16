#include <stdbool.h>

/*@ predicate all_pairs_in_range(int *a, integer len, integer k) =
      \forall integer i, j; 0 <= i < j < len ==>
        (a[j] - a[i] <= k || a[i] - a[j] <= k);
*/

/*@ predicate array_bounds(int *a, integer len) =
      \forall integer i; 0 <= i < len ==> (0 <= a[i] <= 123);
*/

/*@
  requires \valid(a+(0..4));
  requires array_bounds(a, 5);
  requires 0 <= k <= 123;
  ensures \result == true <==> all_pairs_in_range(a, 5, k);
*/
bool func(int *a, int k)
{
    int i = 0;
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant \forall integer x, y; 0 <= x < y < i ==>
        (a[y] - a[x] <= k || a[x] - a[y] <= k);
      loop invariant array_bounds(a, 5);
      loop invariant 0 <= k <= 123;
      loop assigns i;
      loop variant 5 - i;
    */
    while (i < 5)
    {
        int j = i + 1;
        /*@
          loop invariant i < j <= 5;
          loop invariant \forall integer x, y; 0 <= x < y < i ==>
            (a[y] - a[x] <= k || a[x] - a[y] <= k);
          loop invariant \forall integer x, y; 0 <= x < i && i < y < j ==>
            (a[y] - a[x] <= k || a[x] - a[y] <= k);
          loop invariant array_bounds(a, 5);
          loop invariant 0 <= k <= 123;
          loop assigns j;
          loop variant 5 - j;
        */
        while (j < 5)
        {
            int diff = (a[i] > a[j]) ? (a[i] - a[j]) : (a[j] - a[i]);
            //@ assert diff >= 0;
            j++;
        }
        i++;
    }
    return true;
}
