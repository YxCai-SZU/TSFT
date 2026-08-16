#include <stdbool.h>
#include <stddef.h>

/*@ predicate has_common_element(int *list1, integer len1,
                                 int *list2, integer len2) =
    \exists integer i, j; 0 <= i < len1 && 0 <= j < len2 &&
    list1[i] == list2[j];
*/

/*@ predicate no_common_element(int *list1, integer len1,
                                int *list2, integer len2) =
    \forall integer i, j; 0 <= i < len1 && 0 <= j < len2 ==>
    list1[i] != list2[j];
*/

/*@
  requires \valid(list1 + (0..len1-1));
  requires \valid(list2 + (0..len2-1));
  requires 0 <= len1 < 0x80000000;
  requires 0 <= len2 < 0x80000000;
  ensures \result == true ==> has_common_element(list1, len1, list2, len2);
  ensures \result == false ==> no_common_element(list1, len1, list2, len2);
*/
bool has_common_element(int *list1, size_t len1, int *list2, size_t len2) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len1;
      loop invariant \forall integer ii, j; 0 <= ii < i && 0 <= j < len2 ==> 
                    list1[ii] != list2[j];
      loop assigns i;
      loop variant len1 - i;
    */
    while (i < len1) {
        size_t j = 0;
        
        /*@
          loop invariant 0 <= j <= len2;
          loop invariant \forall integer jj; 0 <= jj < j ==> 
                        list1[i] != list2[jj];
          loop assigns j;
          loop variant len2 - j;
        */
        while (j < len2) {
            if (list1[i] == list2[j]) {
                //@ assert has_common_element(list1, len1, list2, len2);
                return true;
            }
            j++;
        }
        i++;
    }
    //@ assert no_common_element(list1, len1, list2, len2);
    return false;
}
