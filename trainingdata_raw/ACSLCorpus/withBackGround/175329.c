#include <limits.h>

/*@
    predicate is_non_negative(integer x) = x >= 0;
    predicate is_small_for_cube(integer x) = x >= 0 && x <= 1290;
    predicate is_small_for_surface(integer x) = x >= 0 && x <= 410;
*/

/*@
    logic integer cube_volume(integer l) = l * l * l;
    logic integer cube_surface(integer l) = 6 * l * l;
*/

/*@
    lemma cube_bound_lemma:
        \forall integer l; is_small_for_cube(l) ==> l * l <= 1290 * 1290;
    lemma cube_volume_bound_lemma:
        \forall integer l; is_small_for_cube(l) ==> l * l * l <= 1290 * 1290 * 1290;
    lemma surface_bound_lemma:
        \forall integer l; is_small_for_surface(l) ==> 6 * l * l <= 6 * 410 * 410;
*/

/*@
    requires is_small_for_cube(l);
    ensures \result == cube_volume(l);
    assigns \nothing;
*/
int volume_cube(int l) {
    //@ assert is_small_for_cube(l);
    //@ assert l * l <= 1290 * 1290;
    //@ assert l * l * l <= 1290 * 1290 * 1290;
    return l * l * l;
}

/*@
    requires is_small_for_surface(l);
    ensures \result == cube_surface(l);
    assigns \nothing;
*/
int surface_area_cube(int l) {
    //@ assert is_small_for_surface(l);
    //@ assert 6 * l * l <= 6 * 410 * 410;
    return 6 * l * l;
}

int main() {
    return 0;
}
