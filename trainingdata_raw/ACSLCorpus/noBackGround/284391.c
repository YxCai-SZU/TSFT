#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(list1 + (0 .. len-1));
    assigns \nothing;
    ensures \result <= len;
    ensures (\exists integer i; 0 <= i < len && list1[i] > threshold) ==> \result >= 1;
*/
size_t count_greater_than(const int *list1, size_t len, int threshold) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i <= len;
        loop invariant \forall integer j; 0 <= j < i && list1[j] > threshold ==> count >= 1;
        loop invariant \forall integer k; 0 <= k < len ==> list1[k] == \at(list1[k], Pre);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert count <= len;
        if (list1[i] > threshold) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
