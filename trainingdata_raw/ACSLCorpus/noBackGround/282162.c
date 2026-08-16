#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == \null ==> 
            (\forall integer i; 0 <= i < len ==> arr[i] <= threshold);
    ensures \result != \null ==>
            (0 <= \result - arr < len &&
             arr[\result - arr] > threshold &&
             (\forall integer i; 0 <= i < \result - arr ==> arr[i] <= threshold));
*/
unsigned int *find_first_greater_than(unsigned int *arr, size_t len, unsigned int threshold) {
    size_t index = 0;
    /*@ loop invariant 0 <= index <= len;
        loop invariant (\forall integer i; 0 <= i < (index) ==> (arr)[i] <= (threshold));
        loop assigns index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert (\forall integer i; 0 <= i < (index) ==> (arr)[i] <= (threshold));
        if (arr[index] > threshold) {
            //@ assert arr[index] > threshold;
            //@ assert (\forall integer i; 0 <= i < (index) ==> (arr)[i] <= (threshold));
            return &arr[index];
        }
        //@ assert arr[index] <= threshold;
        index = index + 1;
    }
    //@ assert index == len;
    //@ assert (\forall integer i; 0 <= i < (len) ==> (arr)[i] <= (threshold));
    return NULL;
}
