#include <stdbool.h>

/*@
  requires 2 <= n <= 100;
  requires 1 <= a <= n;
  requires 1 <= b <= n;
  requires a != b;
  ensures \result == 1 <==> (((b) == (a) + 1) || ((b) == (a) - 1) || ((a) == 1 && (b) == (n)) || ((a) == (n) && (b) == 1));
*/
bool func(int n, int a, int b) {
    bool res = false;
    
    if (a == 1 && b == n) {
        res = true;
    } else if (a == n && b == 1) {
        res = true;
    } else if (b == a + 1) {
        res = true;
    } else if (b == a - 1) {
        res = true;
    }
    
    //@ assert res == 1 <==> (((b) == (a) + 1) || ((b) == (a) - 1) || ((a) == 1 && (b) == (n)) || ((a) == (n) && (b) == 1));
    return res;
}
