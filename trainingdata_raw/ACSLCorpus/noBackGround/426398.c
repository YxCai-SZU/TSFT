#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= len <= 200000;
  requires \valid_read(v + (0 .. len-1));
  requires \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 1000000000;
  ensures \result == true <==> (\forall integer i; 0 <= i < (len) ==> (v)[i] % 2 == 0);
  assigns \nothing;
*/
bool func(const unsigned long *v, size_t len) {
    bool res = true;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant res == true <==> \forall integer j; 0 <= j < i ==> v[j] % 2 == 0;
      loop assigns i, res;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (v[i] % 2 != 0) {
            res = false;
        }
        i++;
    }
    return res;
}
