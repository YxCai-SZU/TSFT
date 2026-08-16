#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(v + (0 .. vlen-1));
  requires \valid(result_arr + (0 .. vlen-1));
  requires \valid(result_len);
  assigns result_arr[0 .. vlen-1], *result_len;
  ensures \result == true ==> (\forall integer k; 0 <= k < (*result_len) ==> (result_arr)[k] == (e));
*/
bool remove_all_not_equal(int *v, size_t vlen, int e, 
                          int *result_arr, size_t *result_len) {
    size_t i = 0;
    size_t res_len = 0;
    
    /*@
      loop invariant 0 <= i <= vlen;
      loop invariant (\forall integer k; 0 <= k < (res_len) ==> (result_arr)[k] == (e));
      loop invariant res_len <= i;
      loop assigns i, result_arr[0 .. vlen-1], res_len;
      loop variant vlen - i;
    */
    while (i < vlen) {
        if (v[i] == e) {
            //@ ghost int *old_result = result_arr;
            //@ ghost size_t old_len = res_len;
            
            result_arr[res_len] = v[i];
            res_len = res_len + 1;
            
            //@ assert (\forall integer k; 0 <= k < (old_len) ==> (old_result)[k] == (e));
        }
        i = i + 1;
    }
    
    *result_len = res_len;
    return true;
}
