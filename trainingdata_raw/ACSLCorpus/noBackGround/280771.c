#include <stdbool.h>

/*@
  requires ((a) > (b) && (b) > (c));
  ensures \result == true;
*/
bool example_15(int a, int b, int c) {
    //@ assert a > b;
    //@ assert b > c;
    //@ assert a > c;
    return true;
}

/*@
  requires ((x) >= (y) && (y) >= (z));
  ensures \result == true;
*/
bool example_16(int x, int y, int z) {
    //@ assert x >= y;
    //@ assert y >= z;
    //@ assert x >= z;
    return true;
}

/*@
  requires ((p) <= (q) && (q) <= (r));
  ensures \result == true;
*/
bool example_17(int p, int q, int r) {
    //@ assert p <= q;
    //@ assert q <= r;
    //@ assert p <= r;
    return true;
}

/*@
  requires ((m) == (n) && (n) == (o));
  ensures \result == true;
*/
bool example_18(int m, int n, int o) {
    //@ assert m == n;
    //@ assert n == o;
    //@ assert m == o;
    return true;
}

/*@
  requires ((s) > (t) && (t) > (u));
  ensures \result == true;
*/
bool example_19(int s, int t, int u) {
    //@ assert s > t;
    //@ assert t > u;
    //@ assert s > u;
    return true;
}

/*@
  requires ((v) >= (w) && (w) >= (x));
  ensures \result == true;
*/
bool example_20(int v, int w, int x) {
    //@ assert v >= w;
    //@ assert w >= x;
    //@ assert v >= x;
    return true;
}

int main() {
    return 0;
}
