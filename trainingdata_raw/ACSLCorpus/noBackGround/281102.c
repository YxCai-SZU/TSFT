#include <stdbool.h>

/*@
  requires (1 <= (n) && (n) <= 100 &&
      1 <= (k) && (k) <= 100);
  ensures (0 <= (\result) && (\result) <= 1);
*/
int func(int n, int k) {
    int res;
    int i;
    int md;
    bool divisible;
    
    res = 0;
    i = 0;
    
    /*@
      loop invariant (0 <= (i) && (i) <= (n) &&
      (1 <= ((n)) && ((n)) <= 100 &&
      1 <= ((k)) && ((k)) <= 100) &&
      (0 <= ((res)) && ((res)) <= 1));
      loop assigns i, res, md, divisible;
      loop variant n - i;
    */
    while (i < n) {
        md = k;
        divisible = false;
        
        /*@
          loop invariant (0 <= (md) && (md) <= (k) &&
      (md) % 2 == (k) % 2);
          loop assigns md;
          loop variant md;
        */
        while (md >= 2) {
            md -= 2;
        }
        
        if (md == 0) {
            divisible = true;
        }
        
        if (divisible) {
            res = 1;
        }
        
        i += 1;
    }
    
    //@ assert (0 <= (res) && (res) <= 1);
    return res;
}
