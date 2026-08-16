#include <stddef.h>
#include <stdbool.h>

/*@
    requires 0 <= len < 0x80000000;
    requires \valid_read(arr + (0 .. len-1));
    ensures \result <= len;
    ensures (\forall integer i; (0) <= i < (len) ==> 
            ((((\at((arr)[i], Here)) & 1) == 1) ==> 
                (\exists integer j; (0) <= j < (len) && (((\at((arr)[j], Here)) & 1) == 1))));
*/
size_t filter_even(const int *arr, size_t len) {
    size_t count = 0;
    size_t index = 0;
    
    /*@
        loop invariant index <= len;
        loop invariant count <= index;
        loop invariant (\forall integer i; (0) <= i < (index) ==> 
            ((((\at((arr)[i], Here)) & 1) == 1) ==> 
                (\exists integer j; (0) <= j < (index) && (((\at((arr)[j], Here)) & 1) == 1))));
        loop assigns index, count;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert index < len;
        if ((arr[index] & 1) == 1) {
            count = count + 1;
        }
        index = index + 1;
    }
    return count;
}

int main() {
    return 0;
}
