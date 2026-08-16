#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_vec_size(integer len) =
      len >= 1 && len <= 100000;
*/

/*@ predicate valid_vec_elem(unsigned int *v, integer len) =
      \forall integer i; 0 <= i < len ==> v[i] >= 1 && v[i] <= 1000000000;
*/

/*@ predicate count_bound(integer cnt, integer idx) =
      cnt >= 0 && cnt <= idx;
*/

/*@ lemma index_bound: \forall integer idx, integer len;
      idx >= 0 && idx <= len && valid_vec_size(len) ==> idx >= 0;
*/

/*@ lemma count_non_negative: \forall integer cnt, integer idx;
      count_bound(cnt, idx) ==> cnt >= 0;
*/

/*@ requires
      valid_vec_size(len) &&
      valid_vec_elem(v, len) &&
      \valid(v + (0 .. len-1));
    ensures
      \result >= 0 &&
      \result <= len;
*/
unsigned int func(unsigned int *v, size_t len)
{
    unsigned int count = 0;
    size_t index = 0;

    /*@ loop invariant
          index <= len &&
          count_bound(count, index) &&
          valid_vec_size(len) &&
          valid_vec_elem(v, len);
        loop assigns
          count, index;
        loop variant
          len - index;
    */
    while (index < len)
    {
        bool is_divisible = false;
        size_t j = 0;

        /*@ loop invariant
              j <= index &&
              valid_vec_size(len) &&
              valid_vec_elem(v, len) &&
              index < len;
            loop assigns
              is_divisible, j;
            loop variant
              index - j;
        */
        while (j < index)
        {
            if (v[index] % v[j] == 0)
            {
                is_divisible = true;
            }
            j++;
        }

        if (!is_divisible)
        {
            count++;
        }

        index++;
    }

    return count;
}
