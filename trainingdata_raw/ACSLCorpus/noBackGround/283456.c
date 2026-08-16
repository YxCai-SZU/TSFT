#include <stdbool.h>

/*@
  requires (0 <= (a) <= 123) && (0 <= (b) <= 123) && (0 <= (c) <= 123) && (0 <= (d) <= 123) && (0 <= (e) <= 123) && (0 <= (k) <= 123);
  requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
  ensures \result == true || \result == false;
*/
bool func(int a, int b, int c, int d, int e, int k) {
    int t;
    int n;
    int x;
    
    t = 0;
    n = 0;
    x = 5;
    
    /*@
      loop invariant 0 <= n <= x;
      loop invariant 0 <= t <= 123;
      loop invariant (0 <= (a) <= 123) && (0 <= (b) <= 123) && (0 <= (c) <= 123) && (0 <= (d) <= 123) && (0 <= (e) <= 123) && (0 <= (k) <= 123);
      loop invariant ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
      loop assigns t, n;
    */
    while (n < x) {
        //@ assert 0 <= n <= x;
        
        if (t >= a && t <= b) {
            return true;
        }
        if (t >= b && t <= c) {
            return true;
        }
        if (t >= c && t <= d) {
            return true;
        }
        if (t >= d && t <= e) {
            return true;
        }
        if (t > e) {
            break;
        }
        
        t = t + 1;
        n = n + 1;
    }
    
    return false;
}

int main() {
    return 0;
}
