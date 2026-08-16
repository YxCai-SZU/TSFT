#include <stddef.h>
#include <stdint.h>

/*@
  requires \valid_read(s + (0 .. len-1));
  requires \valid_read(t + (0 .. len-1));
  requires len <= 0x80000000;
  requires (\forall integer i; 0 <= i < (len) ==>
        ((\at((s)[i], Here)) == (\at((t)[i], Here)) ||
      (\at((s)[i], Here)) + 1 == (\at((t)[i], Here)) ||
      (\at((s)[i], Here)) - 1 == (\at((t)[i], Here))));
  assigns \nothing;
  ensures \result <= len;
*/
size_t min_operations(const uint32_t *s, const uint32_t *t, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= count <= i;
      loop invariant (\forall integer i; 0 <= i < (len) ==>
        ((\at((s)[i], Here)) == (\at((t)[i], Here)) ||
      (\at((s)[i], Here)) + 1 == (\at((t)[i], Here)) ||
      (\at((s)[i], Here)) - 1 == (\at((t)[i], Here))));
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        if (s[i] != t[i]) {
            //@ assert ((s[i]) == (t[i]) ||       (s[i]) + 1 == (t[i]) ||       (s[i]) - 1 == (t[i]));
            count++;
        }
        i++;
    }
    return count;
}
