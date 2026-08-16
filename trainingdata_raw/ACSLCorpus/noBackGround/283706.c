#include <stdbool.h>

/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  requires 0 <= c <= 100;
  requires a != b && a != c && b != c;
  ensures \result == true <==> (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
*/
bool func(int a, int b, int c) {
    bool result;
    //@ assert a != b && a != c && b != c;
    
    if (a < c && c < b) {
        result = true;
        //@ assert (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
        return result;
    } else if (a > c && c > b) {
        result = true;
        //@ assert (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
        return result;
    } else {
        //@ assert !(a < c && c < b) && !(a > c && c > b);
        result = false;
        //@ assert !(((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
        return result;
    }
}
