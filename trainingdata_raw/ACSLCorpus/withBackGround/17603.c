#include <stdbool.h>

/*@ predicate sorted(int a, int b, int c, int d, int e) =
      a < b && b < c && c < d && d < e;
*/

/*@ predicate in_range(int a, int b, int c, int d, int e, int k) =
      0 <= a && a <= 123 && 0 <= b && b <= 123 && 0 <= c && c <= 123 &&
      0 <= d && d <= 123 && 0 <= e && e <= 123 && 0 <= k && k <= 123;
*/

/*@ predicate vector_consistent(int *vec, int a, int b, int c, int d, int e) =
      \forall integer m; 0 <= m < 5 ==>
        (m == 0 ==> vec[m] == a) &&
        (m == 1 ==> vec[m] == b) &&
        (m == 2 ==> vec[m] == c) &&
        (m == 3 ==> vec[m] == d) &&
        (m == 4 ==> vec[m] == e);
*/

/*@ logic integer abs_diff(integer x, integer y) =
      x > y ? x - y : y - x;
*/

/*@ lemma diff_property:
      \forall integer a,b,c,d,e,k;
      (0 <= a <= 123 && 0 <= b <= 123 && 0 <= c <= 123 &&
       0 <= d <= 123 && 0 <= e <= 123 && 0 <= k <= 123) &&
      (a < b && b < c && c < d && d < e) ==>
      (abs_diff(b,a) <= k || abs_diff(c,a) <= k || abs_diff(d,a) <= k ||
       abs_diff(e,a) <= k || abs_diff(b,e) <= k || abs_diff(c,e) <= k ||
       abs_diff(d,e) <= k || abs_diff(e,e) <= k);
*/

/*@
  requires 0 <= a <= 123 && 0 <= b <= 123 && 0 <= c <= 123 &&
           0 <= d <= 123 && 0 <= e <= 123 && 0 <= k <= 123;
  requires a < b && b < c && c < d && d < e;
  ensures \result == 1;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int vec[5];
    int i;
    int j;
    int diff;
    
    vec[0] = a;
    vec[1] = b;
    vec[2] = c;
    vec[3] = d;
    vec[4] = e;
    
    i = 0;
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant vector_consistent(&vec[0], a, b, c, d, e);
      loop assigns i, j, diff;
      loop variant 5 - i;
    */
    while (i < 5)
    {
        j = i + 1;
        /*@
          loop invariant i < j <= 5;
          loop invariant vector_consistent(&vec[0], a, b, c, d, e);
          loop assigns j, diff;
          loop variant 5 - j;
        */
        while (j < 5)
        {
            diff = vec[i] > vec[j] ? vec[i] - vec[j] : vec[j] - vec[i];
            //@ assert diff == abs_diff(vec[i], vec[j]);
            j = j + 1;
        }
        i = i + 1;
    }
    //@ assert (b - a <= k || c - a <= k || d - a <= k || e - a <= k || b - e <= k || c - e <= k || d - e <= k || e - e <= k) == 1;
    return true;
}
