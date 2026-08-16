#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  requires 1 <= d <= 100;
  ensures \result == true <==> ((a) <= (c) && (d) <= (b));
*/
bool func(int a, int b, int c, int d) {
    bool ans = true;

    //@ assert ans == true;
    if (a > c) {
        ans = false;
        //@ assert ans == false;
    }
    //@ assert ans == true <==> a <= c;
    if (d > b) {
        ans = false;
        //@ assert ans == false;
    }
    //@ assert ans == true <==> (a <= c && d <= b);
    return ans;
}
