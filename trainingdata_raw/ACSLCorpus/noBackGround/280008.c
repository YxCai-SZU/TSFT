#include <stdbool.h>

/*@
  requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
  ensures \result == (n == m);
*/
bool func(int n, int m) {
    int i = 0;
    int black_balls = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant black_balls == i;
      loop invariant 1 <= n <= 100;
      loop invariant 0 <= m <= n;
      loop invariant black_balls <= n;
      loop assigns i, black_balls;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert black_balls == i;
        black_balls += 1;
        i += 1;
        //@ assert black_balls == i;
    }
    
    //@ assert black_balls == n;
    return m == black_balls;
}
