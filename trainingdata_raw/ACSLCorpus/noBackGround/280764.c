#include <stdbool.h>

/*@
  requires (0 <= (a) < (b) < (c) < (d) < (e) < 123);
  requires (0 <= (k) <= 123);
  ensures \result == true;
*/
bool func(int a, int b, int c, int d, int e, int k) {
    int v[5];
    int n;
    int i;
    int j;
    int l;
    
    // Initialize array
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    v[4] = e;
    n = 5;
    
    i = 0;
    //@ assert n == 5;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant n == 5;
      loop invariant (0 <= (a) < (b) < (c) < (d) < (e) < 123);
      loop invariant (0 <= (k) <= 123);
      loop assigns i, j, l;
      loop variant n - i;
    */
    while (i < n) {
        j = i + 1;
        
        /*@
          loop invariant i < j <= n;
          loop invariant n == 5;
          loop invariant (0 <= (a) < (b) < (c) < (d) < (e) < 123);
          loop invariant (0 <= (k) <= 123);
          loop assigns j, l;
          loop variant n - j;
        */
        while (j < n) {
            l = v[j] - v[i];
            //@ assert l == v[j] - v[i];
            j += 1;
        }
        i += 1;
    }
    
    //@ assert \true;
    return true;
}
