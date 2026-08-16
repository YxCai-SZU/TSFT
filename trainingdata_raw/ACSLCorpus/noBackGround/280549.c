#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == true <==> (\exists integer i; 0 <= i < (len) && (arr)[i] == (elem));
    ensures \result == false <==> !(\exists integer i; 0 <= i < (len) && (arr)[i] == (elem));
*/
bool contains_element(int *arr, size_t len, int elem) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] != elem;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] == elem) {
            //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == (elem));
            return true;
        }
        i = i + 1;
    }
    
    //@ assert \forall integer j; 0 <= j < len ==> arr[j] != elem;
    return false;
}
