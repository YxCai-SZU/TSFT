#include <stdbool.h>

/*@
  requires 1 <= x <= 16;
  requires 1 <= y <= 16;
  requires x + y <= 16;
  ensures \result == true <==> ((x) <= 8 && (y) <= 8);
*/
bool func(unsigned int x, unsigned int y) {
    bool x_is_transparent;
    bool y_is_transparent;
    bool result;

    x_is_transparent = (x <= 8);
    y_is_transparent = (y <= 8);

    if (x_is_transparent && y_is_transparent) {
        //@ assert ((x) <= 8 && (y) <= 8);
        result = true;
    } else {
        //@ assert !((x) <= 8 && (y) <= 8);
        result = false;
    }
    return result;
}
