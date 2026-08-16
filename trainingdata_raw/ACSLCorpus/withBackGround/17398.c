#include <stdbool.h>
#include <stdint.h>

/*@ predicate has_no_common_elements{L}(int *v, integer v_len, int *w, integer w_len) =
      \forall integer i, j; 0 <= i < v_len && 0 <= j < w_len ==> v[i] != w[j];
*/

/*@
  requires 0 <= n <= 1000000000000000000;
  requires 1 <= k <= 1000000000000000000;
  ensures \result >= 0;
  ensures \result <= n;
  ensures \result == 0 || k > 0;
  assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t res;
    //@ assert 0 <= n <= 1000000000000000000;
    //@ assert 1 <= k <= 1000000000000000000;
    
    if (n - k < 0) {
        res = 0;
    } else {
        res = n - k;
    }
    
    //@ assert res >= 0;
    //@ assert res <= n;
    //@ assert res == 0 || k > 0;
    return res;
}

/*@
  requires \valid_read(v + (0..v_len-1));
  requires \valid_read(w + (0..w_len-1));
  requires v_len >= 0;
  requires w_len >= 0;
  requires v_len < 0x80000000;
  requires w_len < 0x80000000;
  ensures \result == 1 <==> has_no_common_elements(v, v_len, w, w_len);
  assigns \nothing;
*/
bool func2(int *v, int64_t v_len, int *w, int64_t w_len)
{
    int64_t i = 0;
    bool result;
    
    /*@
      loop invariant 0 <= i <= v_len;
      loop invariant \forall integer ii, jj; 0 <= ii < i && 0 <= jj < w_len ==> v[ii] != w[jj];
      loop assigns i;
      loop variant v_len - i;
    */
    while (i < v_len) {
        int64_t j = 0;
        
        /*@
          loop invariant 0 <= j <= w_len;
          loop invariant \forall integer jj; 0 <= jj < j ==> v[i] != w[jj];
          loop assigns j;
          loop variant w_len - j;
        */
        while (j < w_len) {
            if (v[i] == w[j]) {
                return false;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    
    result = true;
    //@ assert has_no_common_elements(v, v_len, w, w_len);
    return result;
}
