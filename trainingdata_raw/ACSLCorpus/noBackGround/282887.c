#include <stdint.h>

/*@
  requires (1 <= (l) && (l) <= (r) && (r) <= 100 &&
      1 <= (d) && (d) <= 100);
  ensures 0 <= \result;
  ensures \result <= r - l + 1;
*/
uint64_t func(uint64_t l, uint64_t r, uint64_t d) {
    uint64_t ans;
    uint64_t i;

    ans = 0;
    i = l;

    /*@
      loop invariant ((1 <= ((l)) && ((l)) <= ((r)) && ((r)) <= 100 &&
      1 <= ((d)) && ((d)) <= 100) &&
      (l) <= (i) && (i) <= (r) + 1 &&
      (ans) <= (i) - (l) &&
      0 <= (ans));
      loop assigns ans, i;
      loop variant ((r) - (i) + 1);
    */
    while (i <= r) {
        //@ assert ((1 <= ((l)) && ((l)) <= ((r)) && ((r)) <= 100 &&       1 <= ((d)) && ((d)) <= 100) &&       (l) <= (i) && (i) <= (r) + 1 &&       (ans) <= (i) - (l) &&       0 <= (ans));
        if (i % d == 0) {
            ans += 1;
        }
        i += 1;
    }

    //@ assert 0 <= ans;
    //@ assert ans <= r - l + 1;
    return ans;
}
