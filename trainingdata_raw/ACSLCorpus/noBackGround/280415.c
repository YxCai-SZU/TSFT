#include <stdbool.h>

/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  requires 0 <= c <= 100;
  requires a != b && b != c && a != c;
  ensures \result == 1 <==> (((a) < (c) && (c) < (b)) || ((b) < (c) && (c) < (a)));
*/
bool func(int a, int b, int c)
{
    bool tmp;
    tmp = false;

    if ((a < c && c < b) || (b < c && c < a)) {
        tmp = true;
    } else {
        tmp = false;
    }

    //@ assert tmp == 1 <==> (((a) < (c) && (c) < (b)) || ((b) < (c) && (c) < (a)));

    return tmp;
}
