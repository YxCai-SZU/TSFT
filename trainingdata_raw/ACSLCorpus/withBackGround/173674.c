#include <stdbool.h>

/*@ predicate is_sorted(int *s, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> s[i] <= s[j];
*/

/*@ predicate has_no_duplicates(int *s, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> s[i] != s[j];
*/

/*@ predicate has_all_even(int *s, integer len) =
      \forall integer i; 0 <= i < len ==> s[i] % 2 == 0;
*/

/*@ predicate is_increasing(int *s, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> s[i] < s[j];
*/

/*@ predicate is_strictly_decreasing(int *s, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> s[i] > s[j];
*/

/*@ lemma product_bound: 
      \forall integer n, m; 
      1 <= n <= 10000 && 1 <= m <= 10000 ==> n * m <= 10000 * 10000;
*/

/*@
  requires 1 <= n <= 10000;
  requires 1 <= m <= 10000;
  ensures \result == (n * m % 2 == 0);
*/
bool func(unsigned int n, unsigned int m)
{
    //@ assert n * m <= 10000 * 10000;
    return (n * m) % 2 == 0;
}
