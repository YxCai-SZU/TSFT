#include <stddef.h>

/*@
   requires \valid(list + (0..len-1));
   requires 0 <= m < len;
   requires m <= n < len;
   assigns \nothing;
   ensures ((m) >= 0 && (m) < (len) && (m) <= (n) && (n) < (len) &&
      ((\result) == (list)[(m)] || (\exists integer k; (m) <= k && k <= (n) && (\result) == (list)[k])) &&
      (\forall integer j; (m) <= j && j <= (n) ==> (\result) >= (list)[j]));
*/
int max_range_list(int *list, size_t len, size_t m, size_t n) {
    //@ assert m <= n;
    int max = list[m];
    size_t i = m + 1;
    /*@
       loop invariant m <= i;
       loop invariant i <= n + 1;
       loop invariant \forall integer j; m <= j && j < i ==> max >= list[j];
       loop invariant \exists integer j; m <= j && j < i && max == list[j];
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
