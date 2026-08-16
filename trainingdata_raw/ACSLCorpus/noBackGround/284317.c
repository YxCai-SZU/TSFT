#include <stdbool.h>

/*@
  requires 1 <= x <= 9;
  ensures \result == (x == 3 || x == 5 || x == 7);
  assigns \nothing;
*/
bool func(int x) {
    int v[3];
    int i;
    int len;
    
    v[0] = 3;
    v[1] = 5;
    v[2] = 7;
    len = 3;
    i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant len == 3;
      loop invariant v[0] == 3 && v[1] == 5 && v[2] == 7;
      loop invariant \forall integer k; 0 <= k < i ==> v[k] != x;
      loop invariant 1 <= x <= 9;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < 3;
        if (v[i] == x) {
            return true;
        }
        i = i + 1;
    }
    
    return false;
}
