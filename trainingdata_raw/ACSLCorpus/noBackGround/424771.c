#include <stdbool.h>

/*@
  requires 0 <= a < b < c < d < e <= 123;
  requires k >= 0 && k <= 123;
  ensures \result == true <==> (e - a <= k || k == 0);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k) {
    unsigned int dist;
    
    if (a > e) {
        dist = a - e;
    } else {
        dist = e - a;
    }
    
    //@ assert dist == (a > e ? a - e : e - a);
    
    if (dist <= k || k == 0) {
        //@ assert (((e) >= (a) ==> (e) - (a) <= (k)) || ((a) > (e) ==> (a) - (e) <= (k)) || (k) == 0);
        return true;
    } else {
        //@ assert !(dist <= k || k == 0);
        return false;
    }
}
