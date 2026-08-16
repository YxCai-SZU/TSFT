#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(arr + (0..len-1));
    assigns \nothing;
    ensures \result == 1 <==> (\exists integer i, j; 0 <= i < (len) && 0 <= j < (len) && i != j && (arr)[i] == (arr)[j]);
*/
bool test_duplicate(int *arr, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer a, b; 0 <= a < i && 0 <= b < len && a != b ==> arr[a] != arr[b];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        size_t j = i + 1;
        
        /*@
            loop invariant i < j <= len;
            loop invariant \forall integer b; i < b < j ==> arr[i] != arr[b];
            loop invariant \forall integer a, b; 0 <= a < i && 0 <= b < len && a != b ==> arr[a] != arr[b];
            loop assigns j;
            loop variant len - j;
        */
        while (j < len) {
            //@ assert \valid(arr + i) && \valid(arr + j);
            if (arr[i] == arr[j]) {
                //@ assert (\exists integer i, j; 0 <= i < (len) && 0 <= j < (len) && i != j && (arr)[i] == (arr)[j]);
                return true;
            }
            j++;
        }
        i++;
    }
    //@ assert !(\exists integer i, j; 0 <= i < (len) && 0 <= j < (len) && i != j && (arr)[i] == (arr)[j]);
    return false;
}
