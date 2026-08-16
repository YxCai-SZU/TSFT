#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    ensures 0 <= \result <= len;
    ensures \forall integer i; 0 <= i < len ==> 
            (((arr[i]) & 1) != 0) ==> (\exists integer j; 0 <= j < (len) && ((((arr)[j]) & 1) != 0));
    assigns \nothing;
*/
size_t count_odd(int* arr, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant \forall integer k; 0 <= k < i ==> 
                      (((arr[k]) & 1) != 0) ==> (\exists integer j; 0 <= j < (len) && ((((arr)[j]) & 1) != 0));
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((arr[i] & 1) != 0) {
            //@ assert (((arr[i]) & 1) != 0);
            //@ assert (\exists integer j; 0 <= j < (len) && ((((arr)[j]) & 1) != 0));
            count++;
        }
        i++;
    }
    return count;
}
