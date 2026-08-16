#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_min(int *list, integer len, integer idx, integer val) =
       0 <= idx < len && list[idx] == val &&
       \forall integer j; 0 <= j < len ==> list[j] >= val;
*/

/*@ lemma min_exists: 
      \forall int *list, integer len, integer val;
      len > 0 && is_min(list, len, 0, val) ==>
      (\exists integer i; 0 <= i < len && list[i] == val);
*/

/*@ lemma min_smallest:
      \forall int *list, integer len, integer val, integer i;
      is_min(list, len, i, val) ==>
      (\forall integer j; 0 <= j < len ==> list[j] >= val);
*/

/*@ requires len > 0;
    requires \valid_read(list + (0 .. len-1));
    ensures \exists integer i; 0 <= i < len && list[i] == \result;
    ensures \forall integer i; 0 <= i < len ==> list[i] >= \result;
*/
int min_num_in_list(int *list, size_t len)
{
    int min_num = list[0];
    size_t i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> list[j] >= min_num;
        loop invariant \exists integer j; 0 <= j < i && list[j] == min_num;
        loop assigns min_num, i;
        loop variant len - i;
    */
    while (i < len) {
        if (list[i] < min_num) {
            min_num = list[i];
        }
        i++;
    }
    return min_num;
}
