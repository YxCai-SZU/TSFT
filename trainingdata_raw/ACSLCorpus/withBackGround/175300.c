#include <stdbool.h>
#include <stddef.h>

/*@ predicate a_valid_range(long long *a, size_t n) =
      n >= 1 && n <= 100000 &&
      \forall size_t i; 0 <= i < n ==> a[i] >= 0 && a[i] <= 1000000000;
*/

/*@ predicate b_valid_range(long long *b, size_t m) =
      m >= 1 && m <= 100000 &&
      \forall size_t i; 0 <= i < m ==> b[i] >= 0 && b[i] <= 1000000000;
*/

/*@ logic integer max_possible_sum(integer m) = m * 1000000000; */

/*@ lemma ans_bounds:
      \forall integer ans, integer i, integer m;
      0 <= i <= m && 0 <= ans <= i * 1000000000 ==> 0 <= ans <= max_possible_sum(m);
*/

/*@
  requires a_valid_range((long long*)a, n) && b_valid_range((long long*)b, m);
  requires \valid_read(a + (0 .. n-1)) && \valid_read(b + (0 .. m-1));
  ensures 0 <= \result <= max_possible_sum(m);
*/
long long func(size_t n, size_t m, const long long *a, const long long *b)
{
    long long ans = 0;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= m;
      loop invariant 0 <= ans <= i * 1000000000;
      loop assigns ans, i;
    */
    while (i < m)
    {
        long long b_elem = b[i];
        bool contains = false;
        size_t j = 0;

        /*@
          loop invariant 0 <= j <= n;
          loop invariant contains == \false;
          loop invariant \forall size_t k; 0 <= k < j ==> a[k] != b_elem;
          loop assigns j, contains;
        */
        while (j < n)
        {
            if (a[j] == b_elem)
            {
                contains = true;
                break;
            }
            j++;
        }

        if (contains)
        {
            ans += b_elem;
            //@ assert 0 <= ans <= (i+1) * 1000000000;
        }

        i++;
    }

    //@ assert 0 <= ans <= max_possible_sum(m);
    return ans;
}
