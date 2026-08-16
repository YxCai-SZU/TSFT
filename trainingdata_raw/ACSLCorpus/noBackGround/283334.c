#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  requires 1 <= d <= 100;
  ensures \result == (b >= a && c >= b && d >= c);
*/
bool func(int a, int b, int c, int d) {
    bool increasing = false;
    int a_to_b = a;
    int b_to_c = b;
    int c_to_d = c;

    // Check if a_to_b is increasing
    if (a <= b) {
        increasing = true;
    } else {
        increasing = false;
    }

    // Check if b_to_c is increasing
    if (increasing) {
        if (b <= c) {
            increasing = true;
        } else {
            increasing = false;
        }
    }

    // Check if c_to_d is increasing
    if (increasing) {
        if (c <= d) {
            increasing = true;
        } else {
            increasing = false;
        }
    }

    //@ assert increasing == (b >= a && c >= b && d >= c);
    return increasing;
}
