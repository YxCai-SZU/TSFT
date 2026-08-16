#include <stdbool.h>
#include <limits.h>

/*@ requires \valid(a+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == a[0] || \exists integer k; 0 <= k < len && a[k] == \result;
*/
int min_element(int *a, int len) {
    int min;
    int i;
    
    min = a[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant len > 0;
        loop invariant ((min) == (a)[0] || \exists integer k; 0 <= k < (i) && (a)[k] == (min));
        loop assigns min, i;
        loop variant len - i;
    */
    while (i < len) {
        if (a[i] < min) {
            min = a[i];
        }
        i = i + 1;
    }
    return min;
}

/*@ requires \valid(a+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == a[0] || \exists integer k; 0 <= k < len && a[k] == \result;
*/
int max_element(int *a, int len) {
    int max;
    int i;
    
    max = a[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant len > 0;
        loop invariant ((max) == (a)[0] || \exists integer k; 0 <= k < (i) && (a)[k] == (max));
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        if (a[i] > max) {
            max = a[i];
        }
        i = i + 1;
    }
    return max;
}

/*@ requires \valid(a+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == a[0] || \exists integer k; 0 <= k < len && a[k] == \result;
*/
int min_element_abs(int *a, int len) {
    int min;
    int i;
    
    min = a[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant len > 0;
        loop invariant ((min) == (a)[0] || \exists integer k; 0 <= k < (i) && (a)[k] == (min));
        loop assigns min, i;
        loop variant len - i;
    */
    while (i < len) {
        if (a[i] < min) {
            min = a[i];
        }
        i = i + 1;
    }
    return min;
}

/*@ requires \valid(a+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == a[0] || \exists integer k; 0 <= k < len && a[k] == \result;
*/
int max_element_abs(int *a, int len) {
    int max;
    int i;
    
    max = a[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant len > 0;
        loop invariant ((max) == (a)[0] || \exists integer k; 0 <= k < (i) && (a)[k] == (max));
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        if (a[i] > max) {
            max = a[i];
        }
        i = i + 1;
    }
    return max;
}
