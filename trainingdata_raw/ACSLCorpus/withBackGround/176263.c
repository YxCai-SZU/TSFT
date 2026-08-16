#include <stdbool.h>

/*@
    predicate is_pythagorean_triplet(integer a, integer b, integer c) =
        (a * a + b * b == c * c) ||
        (a * a + c * c == b * b) ||
        (b * b + c * c == a * a);
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == true <==> is_pythagorean_triplet(a, b, c);
*/
bool is_pythagorean_triplet(int a, int b, int c)
{
    // Variable declarations at top of scope
    int a_square;
    int b_square;
    int c_square;
    int ab_square;
    int bc_square;
    int ca_square;
    bool ret_val;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;

    a_square = a * a;
    b_square = b * b;
    c_square = c * c;

    ab_square = a_square + b_square;
    bc_square = b_square + c_square;
    ca_square = c_square + a_square;

    //@ assert ab_square == a_square + b_square;
    //@ assert bc_square == b_square + c_square;
    //@ assert ca_square == c_square + a_square;

    if (ab_square == c_square || bc_square == a_square || ca_square == b_square) {
        ret_val = true;
    } else {
        ret_val = false;
    }

    return ret_val;
}
