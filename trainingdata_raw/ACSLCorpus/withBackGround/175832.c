/*@
    predicate nonlin_helper_precond(integer x, integer y, integer z) =
        x <= 100 && y <= 100 && z <= 100 &&
        0 <= x * y && x * y <= 10000 &&
        0 <= x * z && x * z <= 10000;

    predicate nonlin_helper_postcond(integer x, integer y, integer z) =
        0 <= x * (y + z) && x * (y + z) <= 20000;

    lemma nonlinear_arith_helper:
        \forall integer x, y, z;
            nonlin_helper_precond(x, y, z) ==> nonlin_helper_postcond(x, y, z);
*/

/*@
    lemma nonlinear_arith_example21:
        \forall integer a, b; b >= 0 ==> a * b <= a * b + b;
*/

/*@
    lemma nonlinear_arith_example22:
        \forall integer x, y; 0 <= x && x <= 8 && 0 <= y && y <= 8 ==> x * y <= 64;
*/

/*@
    lemma nonlinear_arith_example23:
        \forall integer x, y, z;
            nonlin_helper_precond(x, y, z) ==> nonlin_helper_postcond(x, y, z);
*/

/*@
    lemma nonlinear_arith_example24:
        \forall integer x, y, z;
            nonlin_helper_precond(x, y, z) ==> nonlin_helper_postcond(x, y, z);
*/

/*@
    lemma nonlinear_arith_example25:
        \forall integer x, y, z;
            nonlin_helper_precond(x, y, z) ==> nonlin_helper_postcond(x, y, z);
*/

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
