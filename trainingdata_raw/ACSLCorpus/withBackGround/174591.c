#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */

/*@
  requires \valid_read(v + (0 .. len-1));
  requires \forall integer i; 0 <= i < len ==> is_even(v[i]);
  ensures \result <= len;
*/
size_t count_evens(const unsigned int* v, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= count <= i;
      loop assigns i, count;
    */
    while (i < len) {
        //@ assert is_even(v[i]);
        if (v[i] % 2 == 0) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

int main() {
    return 0;
}
