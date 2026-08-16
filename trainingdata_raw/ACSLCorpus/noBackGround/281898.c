#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(list1 + (0..len-1));
    requires len < 0x80000000;
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len && (((list1[i]) & 1) != 0) ==> 
            (\exists integer k; (0) <= k < (len) && ((((list1)[k]) & 1) != 0));
*/
int count_odd(int *list1, size_t len) {
    int count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i && (((list1[j]) & 1) != 0) ==> 
                      (\exists integer k; (0) <= k < (i) && ((((list1)[k]) & 1) != 0));
        loop assigns i, count;
    */
    while (i < len) {
        //@ assert i < len;
        if ((list1[i] & 1) != 0) {
            //@ assert (((list1[i]) & 1) != 0);
            count += 1;
        }
        i += 1;
    }
    
    //@ assert i == len;
    //@ assert count >= 0;
    //@ assert count <= len;
    //@ assert \forall integer j; 0 <= j < len && (((list1[j]) & 1) != 0) ==> (\exists integer k; (0) <= k < (len) && ((((list1)[k]) & 1) != 0));
    return count;
}
