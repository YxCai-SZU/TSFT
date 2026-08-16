#include <stdbool.h>
#include <stdint.h>

/*@
  requires \valid_read(a + (0 .. len-1));
  requires len <= 0x80000000;
  assigns \nothing;
  ensures \result <==> (\forall integer i; 0 <= i < (len) - 1 ==> (a)[i] <= (a)[i + 1]);
*/
bool is_sorted(int *a, uint32_t len) {
    bool sorted = true;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant sorted <==> (\forall integer j; 0 <= j < i - 1 ==> a[j] <= a[j + 1]);
      loop assigns i, sorted;
      loop variant len - i;
    */
    while (i < len) {
        if (i > 0) {
            //@ assert 0 <= i - 1 < len;
            if (a[i] < a[i - 1]) {
                sorted = false;
                break;
            }
        }
        i++;
    }
    return sorted;
}
