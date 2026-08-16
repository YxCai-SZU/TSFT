#include <stdbool.h>

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    ensures \result == true ==> (\exists integer i, j; 0 <= i < j < (len) && (arr)[i] == (arr)[j]);
*/
bool test_duplicate(int *arr, int len) {
    int i = 0;
    int j = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant len > 0;
        loop assigns i, j;
        loop variant len - i;
    */
    while (i < len) {
        j = i + 1;
        
        /*@ loop invariant 0 <= i < j <= len;
            loop invariant len > 0;
            loop assigns j;
            loop variant len - j;
        */
        while (j < len) {
            //@ assert 0 <= i < j < len;
            if (arr[i] == arr[j]) {
                //@ assert (\exists integer i, j; 0 <= i < j < (len) && (arr)[i] == (arr)[j]);
                return true;
            }
            j++;
        }
        i++;
    }
    return false;
}
