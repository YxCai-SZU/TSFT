#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires 0 <= len < 0x80000000;
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] != (arr)[j]);
*/
bool all_unique(int *arr, size_t len) {
    size_t i = 0;
    size_t j = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer a, b; 0 <= a < i && a < b < len ==> arr[a] != arr[b];
        loop invariant 0 <= len < 0x80000000;
        loop assigns i, j;
        loop variant len - i;
    */
    while (i < len) {
        j = i + 1;
        
        /*@
            loop invariant i < j <= len;
            loop invariant \forall integer a, b; 0 <= a <= i && i < b < j ==> arr[a] != arr[b];
            loop invariant \forall integer a, b; 0 <= a < i && a < b < len ==> arr[a] != arr[b];
            loop invariant 0 <= len < 0x80000000;
            loop assigns j;
            loop variant len - j;
        */
        while (j < len) {
            //@ assert \forall integer a, b; 0 <= a <= i && i < b < j ==> arr[a] != arr[b];
            if (arr[i] == arr[j]) {
                return false;
            }
            j++;
        }
        i++;
    }
    return true;
}
