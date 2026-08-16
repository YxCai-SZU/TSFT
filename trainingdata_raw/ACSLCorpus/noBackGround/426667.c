#include <stddef.h>

/*@ requires m < len && n < len && m <= n;
    requires \valid(list + (0 .. len-1));
    assigns \nothing;
    ensures ((m) <= (n) && (m) < (len) && (n) < (len) &&
      (\exists integer i; (m) <= i && i <= (n) && (list)[i] == (\result)) &&
      (\forall integer i; (m) <= i && i <= (n) ==> (list)[i] <= (\result)));
*/
int max_range_list(int *list, size_t len, size_t m, size_t n) {
    int max;
    size_t i;

    //@ assert m < len;
    //@ assert n < len;
    //@ assert m <= n;

    max = list[m];
    i = m + 1;

    /*@ loop invariant m < len && n < len && m <= n;
        loop invariant m < i && i <= n + 1;
        loop invariant \exists integer k; m <= k && k < i && max == list[k];
        loop invariant \forall integer k; m <= k && k < i ==> list[k] <= max;
        loop assigns max, i;
        loop variant n - i + 1;
    */
    while (i <= n) {
        if (list[i] > max) {
            max = list[i];
        }
        i++;
    }
    return max;
}
