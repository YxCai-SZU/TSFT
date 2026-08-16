#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires (\forall integer i; 0 <= i < (len) ==> 0 <= (arr)[i] <= 100);
  ensures \result == (len == 0 || len > 0);
*/
bool test(int* arr, size_t len) {
    // Variable declarations at top of scope
    size_t i = 0;
    bool result = false;
    
    if (len == 0) {
        result = true;
        return result;
    }
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer k; 0 <= k < i ==> 0 <= arr[k] <= 100;
      loop invariant (\forall integer i; 0 <= i < (len) ==> 0 <= (arr)[i] <= 100);
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= arr[i] <= 100;
        i++;
    }
    
    result = true;
    return result;
}
