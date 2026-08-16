#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_vec(int *v, integer len) =
      len >= 1 && len <= 100000 &&
      \forall integer i; 0 <= i < len ==> v[i] >= 1 && v[i] <= 1000000000;
*/

/*@ lemma p_nonnegative:
      \forall int *v, integer len, i, c, p;
      valid_vec(v, len) && 0 <= i <= len && c >= 0 && c <= i && p >= 0 ==> p >= 0;
*/

/*@ requires valid_vec(v, len);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= 100000;
*/
int func(int *v, size_t len) {
    int c = 0;
    int p = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant c >= 0;
        loop invariant c <= i;
        loop invariant p >= 0;
        loop invariant valid_vec(v, len);
        loop assigns i, c, p;
    */
    while (i < len) {
        int h = v[i];
        if (h >= p) {
            c += 1;
            p = h;
        }
        i += 1;
    }
    
    //@ assert c >= 0;
    //@ assert c <= 100000;
    return c;
}
