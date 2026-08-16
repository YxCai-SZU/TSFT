#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && 
             (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == true <==> (a < c || (a == c && b < d));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d) {
    int a_abs = a;
    int b_abs = b;
    int c_abs = c;
    int d_abs = d;

    // Implementing absolute value
    if (a_abs < 0) {
        a_abs = -a_abs;
    }
    if (b_abs < 0) {
        b_abs = -b_abs;
    }
    if (c_abs < 0) {
        c_abs = -c_abs;
    }
    if (d_abs < 0) {
        d_abs = -d_abs;
    }

    //@ assert ((a_abs) >= 0 && (b_abs) >= 0 && (c_abs) >= 0 && (d_abs) >= 0);

    if (a_abs < c_abs) {
        return true;
    } else if (a_abs == c_abs) {
        return b_abs < d_abs;
    } else {
        return false;
    }
}
