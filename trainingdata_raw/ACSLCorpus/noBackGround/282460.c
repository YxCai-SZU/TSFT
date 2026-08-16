#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == true <==> (3 * (x) - 2 * (y) == 0 ||
      (3 * (x) - 2 * (y) > 0 && (y) > 2 * (x) - 2));
    assigns \nothing;
*/
bool func(int x, int y)
{
    bool is_valid = false;
    int diff = 0;

    //@ assert 3 * x <= 300;
    //@ assert 2 * y <= 200;
    //@ assert 2 * x <= 200;

    diff = 3 * x - 2 * y;
    if (diff == 0) {
        is_valid = true;
    } else if (diff > 0 && y > 2 * x - 2) {
        is_valid = true;
    }

    //@ assert is_valid == true <==> (3 * (x) - 2 * (y) == 0 ||       (3 * (x) - 2 * (y) > 0 && (y) > 2 * (x) - 2));
    return is_valid;
}
