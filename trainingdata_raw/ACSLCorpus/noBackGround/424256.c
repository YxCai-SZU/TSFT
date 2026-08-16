#include <stdbool.h>

/*@ requires \valid(arr+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result >= arr[i];
    ensures \forall integer j; 0 <= j < len ==> arr[j] >= \result || arr[j] < \result;
*/
int find_greater(int *arr, int len) {
    int greater;
    int i;
    
    greater = arr[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant (\exists integer j; 0 <= j < (i) && (arr)[j] == (greater));
        loop invariant (\forall integer j; 0 <= j < (i) ==> (arr)[j] >= (greater) || (arr)[j] < (greater));
        loop assigns greater, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert (\exists integer j; 0 <= j < (i) && (arr)[j] == (greater));
        //@ assert (\forall integer j; 0 <= j < (i) ==> (arr)[j] >= (greater) || (arr)[j] < (greater));
        
        if (arr[i] > greater) {
            greater = arr[i];
        }
        i = i + 1;
    }
    
    //@ assert (\exists integer j; 0 <= j < (len) && (arr)[j] == (greater));
    //@ assert (\forall integer j; 0 <= j < (len) ==> (arr)[j] >= (greater) || (arr)[j] < (greater));
    return greater;
}
