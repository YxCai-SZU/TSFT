#include <stdbool.h>

/*@ requires \valid_read(a+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \forall integer k; 0 <= k < len ==> \result >= a[k];
    ensures \exists integer k; 0 <= k < len && \result == a[k];
*/
int find_max(int* a, int len) {
    int max_element;
    int i;
    
    max_element = a[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (max_element) >= (a)[k]);
        loop invariant (\exists integer k; 0 <= k < (i) && (max_element) == (a)[k]);
        loop assigns max_element, i;
        loop variant len - i;
    */
    while (i < len) {
        if (a[i] > max_element) {
            max_element = a[i];
        }
        i = i + 1;
        //@ assert (\exists integer k; 0 <= k < (i) && (max_element) == (a)[k]);
    }
    
    //@ assert (\forall integer k; 0 <= k < (len) ==> (max_element) >= (a)[k]);
    //@ assert (\exists integer k; 0 <= k < (len) && (max_element) == (a)[k]);
    
    return max_element;
}
