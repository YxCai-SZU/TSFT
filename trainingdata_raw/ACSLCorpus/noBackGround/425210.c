#include <stdbool.h>

/*@
  requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
  requires ((a) <= (b)) && ((c) <= (d));
  ensures \result == true <==> ((c) <= (b) && (d) >= (a));
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    bool result;

    // Precondition assertions
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);
    //@ assert ((a) <= (b));
    //@ assert ((c) <= (d));

    if (c <= b && d >= a) {
        result = true;
    } else {
        result = false;
    }

    // Postcondition verification
    //@ assert result == true <==> ((c) <= (b) && (d) >= (a));
    return result;
}
