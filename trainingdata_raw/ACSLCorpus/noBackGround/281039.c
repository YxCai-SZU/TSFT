#include <stdbool.h>

/*@
    requires 0 <= len < 0x80000000;
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result <==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] < (arr)[i + 1]);
*/
bool is_strictly_increasing(int *arr, int len) {
    int i;
    
    if (len == 0 || len == 1) {
        return true;
    }
    
    i = 0;
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] < arr[j + 1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (arr[i] >= arr[i + 1]) {
            return false;
        }
        i++;
    }
    
    return true;
}
