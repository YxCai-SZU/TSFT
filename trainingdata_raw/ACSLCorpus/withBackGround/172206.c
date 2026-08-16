#include <stddef.h>
#include <stdbool.h>

/*@ predicate element_occurs_at{L}(int *list, integer len, integer i, int element) =
       (0 <= i < len) && (list[i] == element);
*/

/*@ predicate element_not_at{L}(int *list, integer len, integer i, int element) =
       (0 <= i < len) && (list[i] != element);
*/

/*@ lemma count_property:
      \forall int *list, integer len, int element, integer i, integer count;
      (0 <= i <= len) &&
      (0 <= count <= i) &&
      (\forall integer k; 0 <= k < i ==> 
         (element_occurs_at(list, len, k, element) ==> count > 0) &&
         (element_not_at(list, len, k, element) ==> count >= 0))
      ==>
      count <= len;
*/

/*@
  requires \valid(list1 + (0 .. len-1));
  requires len < 0x80000000;
  assigns \nothing;
  ensures \result <= len;
  ensures \forall integer i; 0 <= i < len ==> 
            (list1[i] == element ==> \result > 0) &&
            (list1[i] != element ==> \result >= 0);
*/
size_t count_occurrences(const int *list1, size_t len, int element)
{
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= count <= i;
      loop invariant \forall integer k; 0 <= k < i ==> 
                      (list1[k] == element ==> count > 0) &&
                      (list1[k] != element ==> count >= 0);
      loop invariant len < 0x80000000;
      loop invariant count <= i;
      loop assigns count, i;
      loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (list1[i] == element)
        {
            //@ assert element_occurs_at(list1, len, i, element);
            count++;
        }
        else
        {
            //@ assert element_not_at(list1, len, i, element);
        }
        i++;
    }
    return count;
}
