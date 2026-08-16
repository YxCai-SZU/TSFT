#include <limits.h>

/*@
    requires \valid_read(lst + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result >= lst[0];
    ensures \exists integer i; 0 <= i < len && \result == lst[i];
*/
int max(int* lst, int len) {
    int max_val;
    int i;
    max_val = lst[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && max_val == lst[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= lst[j];
        loop assigns max_val, i;
    */
    while (i < len) {
        //@ assert \exists integer k; 0 <= k < i && max_val == lst[k];
        if (lst[i] > max_val) {
            max_val = lst[i];
        }
        i++;
        //@ assert \exists integer k; 0 <= k < i && max_val == lst[k];
    }
    return max_val;
}
