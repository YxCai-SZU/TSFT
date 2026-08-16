#include <stdbool.h>

/*@
    requires \valid(list+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result >= list[0];
    ensures \exists integer k; 0 <= k < len && \result == list[k];
*/
int find_max(int *list, int len) {
    int max_value;
    int i;

    max_value = list[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (max_value) >= (list)[k]);
        loop invariant \exists integer k; 0 <= k < i && max_value == list[k];
        loop assigns max_value, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list[i] > max_value) {
            max_value = list[i];
        }
        i = i + 1;
    }
    return max_value;
}
