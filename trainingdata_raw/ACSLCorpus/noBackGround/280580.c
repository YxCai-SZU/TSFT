#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(arr + (0 .. len-1));
  requires len > 0;
  assigns \nothing;
  ensures \result == 1 <==> (\exists integer i; 0 <= i < (len) && (arr)[i] == 0);
*/
bool contains_zero(int *arr, size_t len) {
    size_t i;
    i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant (\forall integer j; 0 <= j < (i) ==> (arr)[j] != 0);
      loop assigns i;
    */
    while (i < len) {
        //@ assert i < len;
        if (arr[i] == 0) {
            //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == 0);
            return true;
        }
        //@ assert (\forall integer j; 0 <= j < (i+1) ==> (arr)[j] != 0);
        i = i + 1;
    }
    //@ assert !(\exists integer i; 0 <= i < (len) && (arr)[i] == 0);
    return false;
}
