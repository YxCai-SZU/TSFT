#include <stddef.h>
/*@ predicate is_valid_array(int *arr, size_t len) =
      len <= 100000 &&
      \forall integer j; 0 <= j < len ==> arr[j] <= 500;
*/
/*@ predicate tall_enough_condition(int value, size_t k) =
      value >= 150 + k;
*/
/*@ lemma k_bound: \forall size_t k; k <= 5 ==> 150 + k <= 155; */
/*@
  requires k <= 5;
  requires \valid(a + (0 .. len-1));
  requires is_valid_array(a, len);
  assigns \nothing;
  ensures \result <= len;
*/
size_t count_tallest_enough_friends(int *a, size_t len, size_t k)
{
    size_t tall_enough = 0;
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant tall_enough <= i;
      loop invariant is_valid_array(a, len);
      loop invariant k <= 5;
      loop assigns i, tall_enough;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (a[i] >= 150 + (int)k)
        {
            tall_enough += 1;
        }
        i += 1;
    }
    return tall_enough;
}
