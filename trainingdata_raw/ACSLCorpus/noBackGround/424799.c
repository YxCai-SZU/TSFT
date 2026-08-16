#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(list1 + (0 .. len-1));
    requires \valid(list2 + (0 .. len-1));
    requires \valid(list3 + (0 .. len-1));
    requires len < 0x80000000;
    requires len >= 0;
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer k; 0 <= k < len ==>
        (((list1)[(k)] != (list2)[(k)] &&
        (list2)[(k)] != (list3)[(k)] &&
        (list1)[(k)] != (list3)[(k)]) ==>
            (\exists integer j; 0 <= j < (len) &&
        ((list1)[j] == (list1)[(k)] || (list2)[j] == (list2)[(k)] || (list3)[j] == (list3)[(k)])));
*/
int count_distinct_triplets(int *list1, int *list2, int *list3, int len) {
    int count = 0;
    int i = 0;
    //@ assert count == 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant (\valid((list1) + (0 .. (len)-1)) &&
        \valid((list2) + (0 .. (len)-1)) &&
        \valid((list3) + (0 .. (len)-1)));
        loop invariant \forall integer k; 0 <= k < i ==>
            (((list1)[(k)] != (list2)[(k)] &&
        (list2)[(k)] != (list3)[(k)] &&
        (list1)[(k)] != (list3)[(k)]) ==>
                (\exists integer j; 0 <= j < (i) &&
        ((list1)[j] == (list1)[(k)] || (list2)[j] == (list2)[(k)] || (list3)[j] == (list3)[(k)])));
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        if (list1[i] != list2[i] && list2[i] != list3[i] && list1[i] != list3[i]) {
            //@ assert ((list1)[(i)] != (list2)[(i)] &&         (list2)[(i)] != (list3)[(i)] &&         (list1)[(i)] != (list3)[(i)]);
            count = count + 1;
            
            bool is_distinct = true;
            int j = 0;
            
            /*@
                loop invariant 0 <= j <= i;
                loop invariant is_distinct == true ==> 
                    (\forall integer k; 0 <= k < j ==> 
                        !(list1[i] == list1[k] && list2[i] == list2[k] && list3[i] == list3[k]));
                loop invariant is_distinct == false ==> 
                    (\exists integer k; 0 <= k < j && 
                        list1[i] == list1[k] && list2[i] == list2[k] && list3[i] == list3[k]);
                loop assigns j, is_distinct;
                loop variant i - j;
            */
            while (j < i) {
                if (list1[i] == list1[j] && list2[i] == list2[j] && list3[i] == list3[j]) {
                    is_distinct = false;
                    break;
                }
                j = j + 1;
            }
            
            if (is_distinct) {
                //@ assert \forall integer k; 0 <= k < i ==> !(list1[i] == list1[k] && list2[i] == list2[k] && list3[i] == list3[k]);
            }
        }
        i = i + 1;
    }
    //@ assert i == len;
    return count;
}
