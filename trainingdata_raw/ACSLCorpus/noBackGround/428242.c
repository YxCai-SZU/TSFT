#include <stdbool.h>
#include <stddef.h>

/*@
    requires 0 <= len < 0x80000000;
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == true <==> (\exists integer i; 0 <= i < (len) && (arr)[i] == 0);
*/
bool contains_zero(int* arr, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] != 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] == 0) {
            //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == 0);
            return true;
        }
        //@ assert \forall integer j; 0 <= j < i+1 ==> arr[j] != 0;
        i++;
    }
    //@ assert \forall integer j; 0 <= j < len ==> arr[j] != 0;
    //@ assert !(\exists integer i; 0 <= i < (len) && (arr)[i] == 0);
    return false;
}
