#include <stdbool.h>

/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  requires 0 <= c <= 100;
  ensures \result == true <==> (a + b + c == 180);
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int d;
    bool ret;

    d = a + b + c;
    ret = true;

    if (d != 180) {
        ret = false;
    }

    //@ assert ret == true <==> (a + b + c == 180);
    return ret;
}
