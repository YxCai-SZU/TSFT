#include <stddef.h>
#include <stdbool.h>

/*@
  requires \valid(list1 + (0 .. len-1));
  requires len >= 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= len;
  ensures \forall integer i; 0 <= i < len ==>
    ((((list1[i]) & 1) != 0) ==> \result >= 1) ||
    (!(((list1[i]) & 1) != 0) ==> \result >= 0);
*/
size_t count_odd(const int *list1, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant count >= 0;
      loop invariant count <= i;
      loop invariant \forall integer j; 0 <= j < i ==>
        ((((list1[j]) & 1) != 0) ==> count >= 1) ||
        (!(((list1[j]) & 1) != 0) ==> count >= 0);
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        if ((list1[i] & 1) != 0) {
            count++;
        }
        i++;
    }
    return count;
}

int main() {
    return 0;
}
