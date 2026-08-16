#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_x(integer a, integer b) = a - b;
    logic integer compute_y(integer x, integer c) = x + c;
    logic integer compute_z(integer y) = y > 0 ? y : 0;

    lemma z_nonnegative: \forall integer y; compute_z(y) >= 0;
    lemma z_bound: \forall integer a, b, c; 
        valid_input(a, b, c) ==> 
        compute_z(compute_y(compute_x(a, b), c)) <= a - b + c;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= a - b + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int x;
    int y;
    int z;

    //@ assert 1 <= b && b <= a && a <= 20;
    //@ assert 1 <= c && c <= 20;
    
    x = a - b;
    //@ assert x == compute_x(a, b);
    
    y = x + c;
    //@ assert y == compute_y(x, c);
    
    if (y > 0) {
        z = y;
        //@ assert z == y;
    } else {
        z = 0;
        //@ assert z == 0;
    }
    
    //@ assert z == compute_z(y);
    //@ assert z >= 0;
    //@ assert z <= a - b + c;
    
    return z;
}
