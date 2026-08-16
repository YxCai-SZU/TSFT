#include <stdbool.h>

/*@
  requires \valid_read(lst+(0..len-1));
  assigns \nothing;
  ensures \result <= len;
*/
unsigned int count(const bool *lst, unsigned int len) {
    unsigned int cnt = 0;
    unsigned int i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant cnt <= i;
      loop invariant cnt <= len;
      loop invariant \forall integer k; 0 <= k < i ==> (lst[k] ==> cnt == (1 + (cnt - 1)));
      loop assigns i, cnt;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert (0 <= (i) && (i) <= (len) &&       (cnt) <= (i) &&       (cnt) <= (len) &&       \forall integer k; 0 <= k < (i) ==> ((lst)[k] ==> (cnt) == (1 + ((cnt) - 1))));
        if (lst[i]) {
            cnt += 1;
        }
        i += 1;
    }
    //@ assert cnt <= len;
    return cnt;
}
