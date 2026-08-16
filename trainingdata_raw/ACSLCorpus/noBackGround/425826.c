#include <stdbool.h>

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result == true <==> (((a) == 5 && (b) == 5 && (c) == 7) ||
      ((a) == 5 && (b) == 7 && (c) == 5) ||
      ((a) == 7 && (b) == 5 && (c) == 5));
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    int x = a;
    int y = b;
    int z = c;
    bool found = false;

    if (x == 5 && y == 5 && z == 7) {
        found = true;
    } else if (x == 5 && y == 7 && z == 5) {
        found = true;
    } else if (x == 7 && y == 5 && z == 5) {
        found = true;
    }

    //@ assert found == true <==> (((x) == 5 && (y) == 5 && (z) == 7) ||       ((x) == 5 && (y) == 7 && (z) == 5) ||       ((x) == 7 && (y) == 5 && (z) == 5));

    return found;
}
