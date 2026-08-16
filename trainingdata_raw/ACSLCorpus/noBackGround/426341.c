#include <limits.h>

/*@
    requires ((l) >= 0 && (b) >= 0);
    requires ((l) * (l) + (b) * (b) <= INT_MAX);
    ensures \result == l * l + b * b;
    assigns \nothing;
*/
int rectangle_diagonal_squared(int l, int b) {
    int sum_of_squares;
    sum_of_squares = l * l + b * b;
    //@ assert sum_of_squares == l * l + b * b;
    return sum_of_squares;
}
