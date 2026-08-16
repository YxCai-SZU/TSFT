#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(arr + (0 .. len-1));
    ensures \result == true ==> (\exists size_t i; 0 <= i < (len) && (arr)[i] < 0);
    ensures \result == false ==> (\forall size_t i; 0 <= i < (len) ==> (arr)[i] >= 0);
*/
bool find_negative(int *arr, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i ==> arr[j] >= 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] < 0) {
            //@ assert (\exists size_t i; 0 <= i < (len) && (arr)[i] < 0);
            return true;
        }
        i++;
    }
    //@ assert (\forall size_t i; 0 <= i < (len) ==> (arr)[i] >= 0);
    return false;
}
