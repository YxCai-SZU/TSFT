#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(vec + (0 .. len-1));
  assigns \nothing;
  ensures \result == true <==> (\forall integer k; 0 <= k < (len) / 2 ==> (vec)[k] == (vec)[(len) - k - 1]);
*/
bool test_is_palindrome(int *vec, size_t len) {
    size_t i = 0;
    size_t half_len = len / 2;
    
    /*@
      loop invariant 0 <= i <= half_len;
      loop invariant \forall integer k; 0 <= k < i ==> vec[k] == vec[len - k - 1];
      loop assigns i;
      loop variant half_len - i;
    */
    while (i < half_len) {
        //@ assert 0 <= i <= half_len;
        if (vec[i] != vec[len - i - 1]) {
            return false;
        }
        i++;
    }
    return true;
}
