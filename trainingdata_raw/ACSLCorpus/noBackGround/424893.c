#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(a + (0 .. len-1));
  requires 1 <= len <= 200000;
  requires \forall integer i; 0 <= i < len ==> 1 <= a[i] <= 1000000000;
  assigns \nothing;
  ensures 0 <= \result <= len;
*/
int count_even_numbers(const unsigned long* a, size_t len) {
    int count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= count <= (int)i;
      loop invariant \forall integer j; 0 <= j < len ==> 1 <= a[j] <= 1000000000;
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((a[i] & 1) == 0) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
