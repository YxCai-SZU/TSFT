#include <stdbool.h>

/*@
  requires \valid(a + (0 .. len-1));
  requires (\forall integer i, j; 0 <= i < j < (len) ==> (a)[i] != (a)[j]);
  ensures \result == true;
  assigns \nothing;
*/
bool test_duplicate(int *a, int len) {
    //@ assert !(\exists integer i, j; 0 <= i < j < (len) && (a)[i] == (a)[j]);
    return true;
}
