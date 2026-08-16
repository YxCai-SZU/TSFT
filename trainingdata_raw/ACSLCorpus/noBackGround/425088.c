#include <stdbool.h>

/*@ requires 
      len > 0 && 
      \valid(list1 + (0 .. len-1)) && 
      \valid(list2 + (0 .. len-1)) && 
      \valid(list3 + (0 .. len-1));
   ensures
      ((\result == true) ==> (\forall integer j; 0 <= j < ((len)) ==> 
           (list1)[j] != (list2)[j] && (list2)[j] != (list3)[j] && (list1)[j] != (list3)[j]));
   ensures
      ((\result == false) ==> (\exists integer j; 0 <= j < ((len)) && 
           ((list1)[j] == (list2)[j] || (list2)[j] == (list3)[j] || (list1)[j] == (list3)[j])));
 */
bool check_distinct_triplets(int *list1, int *list2, int *list3, int len)
{
    int i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> 
           (list1)[j] != (list2)[j] && (list2)[j] != (list3)[j] && (list1)[j] != (list3)[j]);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list1[i] == list2[i] || list2[i] == list3[i] || list1[i] == list3[i]) {
            //@ assert (\exists integer j; 0 <= j < ((len)) &&             ((list1)[j] == (list2)[j] || (list2)[j] == (list3)[j] || (list1)[j] == (list3)[j]));
            return false;
        }
        i++;
        //@ assert (\forall integer j; 0 <= j < (i) ==>             (list1)[j] != (list2)[j] && (list2)[j] != (list3)[j] && (list1)[j] != (list3)[j]);
    }
    //@ assert (\forall integer j; 0 <= j < ((len)) ==>             (list1)[j] != (list2)[j] && (list2)[j] != (list3)[j] && (list1)[j] != (list3)[j]);
    return true;
}
