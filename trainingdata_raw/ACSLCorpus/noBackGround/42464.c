#include <stdbool.h>

/*@
    requires \valid(L+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result == L[i];
    ensures \forall integer i; 0 <= i < len ==> L[i] <= \result;
*/
int max_in_list(int *L, int len) {
    int max = L[0];
    int i = 1;
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && max == L[k];
        loop invariant \forall integer k; 0 <= k < i ==> L[k] <= max;
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        if (L[i] > max) {
            max = L[i];
        }
        //@ assert \forall integer k; 0 <= k < i ==> L[k] <= max;
        i++;
    }
    return max;
}
