#include <stdbool.h>
#include <stdint.h>

/*@
  requires (\valid((list1)+(0..(len)-1)) &&
      \valid((list2)+(0..(len)-1)) &&
      \valid((list3)+(0..(len)-1)) &&
      (len) >= 0 && (len) < 0x80000000);
  ensures \result >= 0;
  ensures \result <= len;
  ensures \forall integer k; 0 <= k < len && ((list1)[(k)] != (list2)[(k)] ||
      (list2)[(k)] != (list3)[(k)] ||
      (list1)[(k)] != (list3)[(k)]) ==> \result >= 1;
  assigns \nothing;
*/
int32_t count_distinct_triplets(int32_t *list1, int32_t *list2, int32_t *list3, int32_t len) {
    int32_t count = 0;
    int32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant count >= 0;
      loop invariant count <= i;
      loop invariant \forall integer k; 0 <= k < i && ((list1)[(k)] != (list2)[(k)] ||
      (list2)[(k)] != (list3)[(k)] ||
      (list1)[(k)] != (list3)[(k)]) ==> count >= 1;
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert i >= 0 && i < len;
        if (list1[i] != list2[i] || list2[i] != list3[i] || list1[i] != list3[i]) {
            //@ assert ((list1)[(i)] != (list2)[(i)] ||       (list2)[(i)] != (list3)[(i)] ||       (list1)[(i)] != (list3)[(i)]);
            count++;
            //@ assert count >= 1;
        }
        i++;
    }
    return count;
}
