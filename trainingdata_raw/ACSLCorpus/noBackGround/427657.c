#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= d <= 20;
    ensures \result == true <==> (((n) > 9 && (d) > 1) || ((n) >= 3 && (d) >= 2) || ((n) >= 1 && (d) >= 3));
    assigns \nothing;
*/
bool func(int n, int d)
{
    // Declare all variables at the top
    bool result;
    int n_int = n;
    int d_int = d;

    //@ assert 1 <= n_int <= 20 && 1 <= d_int <= 20;

    if (n_int > 9 && d_int > 1) {
        //@ assert (((n_int) > 9 && (d_int) > 1) || ((n_int) >= 3 && (d_int) >= 2) || ((n_int) >= 1 && (d_int) >= 3));
        result = true;
    } else if (n_int >= 3 && d_int >= 2) {
        //@ assert (((n_int) > 9 && (d_int) > 1) || ((n_int) >= 3 && (d_int) >= 2) || ((n_int) >= 1 && (d_int) >= 3));
        result = true;
    } else if (n_int >= 1 && d_int >= 3) {
        //@ assert (((n_int) > 9 && (d_int) > 1) || ((n_int) >= 3 && (d_int) >= 2) || ((n_int) >= 1 && (d_int) >= 3));
        result = true;
    } else {
        //@ assert !(((n_int) > 9 && (d_int) > 1) || ((n_int) >= 3 && (d_int) >= 2) || ((n_int) >= 1 && (d_int) >= 3));
        result = false;
    }

    return result;
}
