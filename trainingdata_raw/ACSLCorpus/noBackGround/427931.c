#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(A + (0..len-1));
  requires len > 0;
  ensures \result == true ==> (\forall integer i; 0 <= i < len ==> ((A[i]) % 2 == 0));
  ensures \result == false ==> (\exists integer i; 0 <= i < len && !((A[i]) % 2 == 0));
*/
bool all_even(const unsigned int* A, size_t len) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> ((A[j]) % 2 == 0);
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (A[i] % 2 != 0) {
            return false;
        }
        i++;
    }
    return true;
}

/*@
  requires \valid_read(A + (0..len-1));
  requires len > 0;
  ensures \result == true ==> (\exists integer i; 0 <= i < len && ((A[i]) % 2 != 0));
  ensures \result == false ==> (\forall integer i; 0 <= i < len ==> !((A[i]) % 2 != 0));
*/
bool at_least_one_odd(const unsigned int* A, size_t len) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> !((A[j]) % 2 != 0);
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (A[i] % 2 != 0) {
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    return 0;
}
