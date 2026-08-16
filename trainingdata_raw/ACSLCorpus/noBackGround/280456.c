#include <stddef.h>
#include <stdint.h>

/*@
  requires \valid(v + (0 .. len-1));
  requires ((len) < 0x80000000 &&
      \forall integer i; 0 <= i < (len) ==> 1 <= (v)[i] <= 100);
  requires 1 <= c <= 100;
  ensures \result <= len;
  ensures \forall integer i; 0 <= i < len && v[i] < c ==> \result > 0;
*/
size_t func(int32_t *v, size_t len, int32_t c) {
    size_t count = 0;
    size_t index = 0;
    
    /*@
      loop invariant index <= len;
      loop invariant count <= index;
      loop invariant (\forall integer i; 0 <= i < (index) && (v)[i] < (c) ==> (count) > 0);
      loop invariant ((len) < 0x80000000 &&
      \forall integer i; 0 <= i < (len) ==> 1 <= (v)[i] <= 100);
      loop invariant 1 <= c <= 100;
      loop assigns count, index;
      loop variant len - index;
    */
    while (index < len) {
        //@ assert index < len ==> v[index] >= 1 && v[index] <= 100;
        if (v[index] < c) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
