#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 0 && (len) < 0x80000000 &&
        \valid((arr) + (0 .. (len)-1)));
    ensures \result == true ==> \exists integer i; 0 <= i < len && arr[i] == elem;
    ensures \result == false ==> \forall integer i; 0 <= i < len ==> arr[i] != elem;
*/
bool contains_element(int *arr, size_t len, int elem) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (arr)[j] != (elem));
        loop invariant ((len) >= 0 && (len) < 0x80000000 &&
        \valid((arr) + (0 .. (len)-1)));
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] == elem) {
            //@ assert (0 <= (i) < (len) && (arr)[(i)] == (elem));
            return true;
        }
        i = i + 1;
    }
    
    //@ assert i == len;
    //@ assert (\forall integer j; 0 <= j < (i) ==> (arr)[j] != (elem));
    //@ assert (\forall integer j; 0 <= j < (len) ==> (arr)[j] != (elem));
    
    return false;
}
