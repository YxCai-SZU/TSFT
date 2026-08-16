#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires len > 0;
  assigns \nothing;
  ensures ((len) > 0 &&
      (\exists size_t i; 0 <= i < (len) && (arr)[i] == (\result)) &&
      (\forall size_t j; 0 <= j < (len) ==> (\result) >= (arr)[j]));
*/
int find_max(int *arr, size_t len) {
    size_t i;
    int max_val;
    
    //@ assert len > 0;
    max_val = arr[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= len;
      loop invariant \exists size_t k; 0 <= k < i && max_val == arr[k];
      loop invariant \forall size_t j; 0 <= j < i ==> max_val >= arr[j];
      loop assigns i, max_val;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        //@ assert \forall size_t j; 0 <= j < i ==> max_val >= arr[j];
        i++;
    }
    //@ assert i == len;
    //@ assert ((len) > 0 &&       (\exists size_t i; 0 <= i < (len) && (arr)[i] == (max_val)) &&       (\forall size_t j; 0 <= j < (len) ==> (max_val) >= (arr)[j]));
    return max_val;
}
