#include <stdbool.h>

/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  requires 0 <= c <= 100;
  ensures \result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
*/
bool func(int a, int b, int c) {
    int ab;
    int ac;
    int bc;
    bool result;

    ab = a + b;
    //@ assert ab == a + b;

    ac = a + c;
    //@ assert ac == a + c;

    bc = b + c;
    //@ assert bc == b + c;

    result = (ab == c) || (ac == b) || (bc == a);
    return result;
}
