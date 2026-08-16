#include <stdbool.h>
#include <stdint.h>

/*@
  requires ((len) >= 0 && (len) < 0x80000000 &&
      \valid((list1) + (0 .. (len)-1)) &&
      \valid((list2) + (0 .. (len)-1)) &&
      \valid((list3) + (0 .. (len)-1)));
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= len;
  ensures \forall integer i; 0 <= i < len ==> 
          ((list1[i]) != (list2[i]) && (list2[i]) != (list3[i]) && (list1[i]) != (list3[i])) ==> \result > 0;
*/
int32_t count_distinct_triplets(int32_t *list1, int32_t *list2, int32_t *list3, int32_t len) {
    int32_t count;
    int32_t i;
    
    count = 0;
    i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= count <= i;
      loop invariant \forall integer j; 0 <= j < i ==>
                    ((list1[j]) != (list2[j]) && (list2[j]) != (list3[j]) && (list1[j]) != (list3[j])) ==> count > 0;
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        
        if (list1[i] != list2[i] && list2[i] != list3[i] && list1[i] != list3[i]) {
            //@ assert ((list1[i]) != (list2[i]) && (list2[i]) != (list3[i]) && (list1[i]) != (list3[i]));
            count = count + 1;
        }
        
        i = i + 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= len;
    return count;
}
