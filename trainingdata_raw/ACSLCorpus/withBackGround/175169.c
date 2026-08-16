#include <stdbool.h>

/*@
    predicate valid_radius(integer r) = 1 <= r <= 100;
*/

/*@
    logic integer hexagon_perimeter(integer r) = r * 6;
*/

/*@
    lemma perimeter_approx: \forall integer r; valid_radius(r) ==> 2 * r * 3 == hexagon_perimeter(r);
*/

/*@
    requires valid_radius(r);
    ensures \result == hexagon_perimeter(r);
    assigns \nothing;
*/
int func(int r) {
    int pi_approx = 3;
    int result;
    
    //@ assert 2 * r * pi_approx == r * 6;
    
    result = 2 * r * pi_approx;
    return result;
}
