#include <stdbool.h>

/*@
    requires len > 0;
    ensures \forall integer j; 0 <= j < len ==> \result <= arr[j];
*/
int find_min(int* arr, int len) {
    int min;
    int i;
    
    min = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (min) <= (arr)[j]);
        loop assigns min, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert (\forall integer j; 0 <= j < (i) ==> (min) <= (arr)[j]);
        if (arr[i] < min) {
            min = arr[i];
        }
        i = i + 1;
        //@ assert (\forall integer j; 0 <= j < (i) ==> (min) <= (arr)[j]);
    }
    return min;
}
