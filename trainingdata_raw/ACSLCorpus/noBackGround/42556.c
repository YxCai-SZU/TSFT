#include <stdbool.h>

/*@
  requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
  ensures \result == (c - b == b - a);
  assigns \nothing;
*/
bool func(int a, int b, int c) {
    int diff1;
    int diff2;
    bool ans;

    //@ assert b - a >= -99 && b - a <= 99;
    //@ assert c - b >= -99 && c - b <= 99;

    diff1 = b - a;
    diff2 = c - b;
    ans = (diff1 == diff2);

    //@ assert ans == (c - b == b - a);
    return ans;
}
