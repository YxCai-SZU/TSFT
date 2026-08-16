#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
size_t count_greater_than(int *arr, size_t len, int threshold) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count >= 0;
        loop invariant len >= 0;
        loop invariant \forall integer j; 0 <= j < i ==> (arr[j] > threshold ==> count > 0) && (arr[j] <= threshold ==> count >= 0);
        loop invariant count <= i;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert ((i) >= 0 && (i) <= (len) &&         (count) >= 0 &&         (len) >= 0 &&         (\forall integer j; 0 <= j < (i) ==> ((arr)[j] > (threshold) ==> (count) > 0) && ((arr)[j] <= (threshold) ==> (count) >= 0)) &&         (count) <= (i));
        if (arr[i] > threshold) {
            count += 1;
        }
        i += 1;
    }
    //@ assert count >= 0;
    return count;
}
