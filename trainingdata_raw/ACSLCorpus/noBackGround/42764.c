#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires ((len) < 0x80000000);
  assigns \nothing;
  ensures \result >= -1;
  ensures \result < (int)len;
  behavior found:
    assumes \exists size_t i; 0 <= i < len && arr[i] == target;
    ensures \result != -1;
    ensures arr[\result] == target;
  behavior not_found:
    assumes \forall size_t i; 0 <= i < len ==> arr[i] != target;
    ensures \result == -1;
  complete behaviors;
  disjoint behaviors;
*/
int find_index(int *arr, size_t len, int target) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant (\forall size_t j; 0 <= j < (i) ==> (arr)[j] != (target));
      loop invariant ((len) < 0x80000000);
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert (\forall size_t j; 0 <= j < (i) ==> (arr)[j] != (target));
        
        if (arr[i] == target) {
            //@ assert arr[i] == target;
            //@ assert (\forall size_t j; 0 <= j < (i) ==> (arr)[j] != (target));
            return (int)i;
        }
        i++;
    }
    
    //@ assert (\forall size_t j; 0 <= j < (len) ==> (arr)[j] != (target));
    //@ assert (\forall size_t i; 0 <= i < (len) ==> (arr)[i] != (target));
    return -1;
}
