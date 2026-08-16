#include <stddef.h>
#include <stdint.h>

/*@
  requires ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
  assigns \nothing;
  ensures -1 <= \result <= (int)n;
*/
int32_t func(size_t n, int32_t *a) {
    uint32_t search_number;
    int32_t count;
    size_t index;
    
    search_number = 1;
    count = 0;
    index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 1 <= search_number <= ((index) + 1);
      loop invariant 0 <= count <= (int)index;
      loop invariant index <= n;
      loop invariant ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
      loop assigns search_number, count, index;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (a[index] == search_number) {
            search_number += 1;
        } else {
            count += 1;
        }
        index += 1;
    }
    
    if (search_number == 1) {
        return -1;
    } else {
        return count;
    }
}
