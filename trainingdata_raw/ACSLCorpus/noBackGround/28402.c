#include <stdbool.h>
/*@
    requires n > 0;
    ensures \result >= arr[0];
*/
int find_max_element(int *arr, int n) {
    int max_element;
    int i;
    
    //@ assert n > 0;
    max_element = arr[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant n > 0;
        loop invariant ((i) >= 0 && (n) > 0 && (max_element) >= (arr)[0] &&
        \forall integer k; 0 <= k < (i) ==> (max_element) >= (arr)[k]);
        loop assigns max_element, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert ((i) >= 0 && (n) > 0 && (max_element) >= (arr)[0] &&         \forall integer k; 0 <= k < (i) ==> (max_element) >= (arr)[k]);
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        i++;
        //@ assert ((i) >= 0 && (n) > 0 && (max_element) >= (arr)[0] &&         \forall integer k; 0 <= k < (i) ==> (max_element) >= (arr)[k]);
    }
    //@ assert ((n) >= 0 && (n) > 0 && (max_element) >= (arr)[0] &&         \forall integer k; 0 <= k < (n) ==> (max_element) >= (arr)[k]);
    //@ assert max_element >= arr[0];
    return max_element;
}
