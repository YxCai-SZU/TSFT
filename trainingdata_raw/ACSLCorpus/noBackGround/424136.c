#include <stdbool.h>

/*@
  requires \valid_read(x + (0..2));
  requires (1 <= (x[0]) <= 13);
  requires (1 <= (x[1]) <= 13);
  requires (1 <= (x[2]) <= 13);
  assigns \nothing;
  ensures \result == true <==> (((x[1]) == (x[0]) + 1 && (x[2]) == (x[0]) + 2) ||
      ((x[0]) == (x[1]) + 1 && (x[2]) == (x[1]) + 2) ||
      ((x[0]) == (x[2]) + 1 && (x[1]) == (x[2]) + 2));
*/
bool func(int* x) {
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (x[0]) <= 13);
    //@ assert (1 <= (x[1]) <= 13);
    //@ assert (1 <= (x[2]) <= 13);

    result = (x[1] == x[0] + 1 && x[2] == x[0] + 2) ||
             (x[0] == x[1] + 1 && x[2] == x[1] + 2) ||
             (x[0] == x[2] + 1 && x[1] == x[2] + 2);

    //@ assert result == true <==> (((x[1]) == (x[0]) + 1 && (x[2]) == (x[0]) + 2) ||       ((x[0]) == (x[1]) + 1 && (x[2]) == (x[1]) + 2) ||       ((x[0]) == (x[2]) + 1 && (x[1]) == (x[2]) + 2));
    return result;
}
