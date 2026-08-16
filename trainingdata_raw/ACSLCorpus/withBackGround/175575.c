/*@
    predicate multiplication_bounds_check_lemma(integer x, integer y) =
        0 <= x && x <= 10 && 0 <= y && y <= 10 ==>
        0 <= x * y && x * y <= 100;

    predicate division_bounds_check_lemma(integer a, integer b, integer c) =
        0 <= a && a <= 100 && 1 <= b && b <= 10 && 0 <= c && c <= 10 ==>
        a / b <= 100 && a / b >= 0;

    predicate modulus_bounds_check_lemma(integer a, integer b) =
        0 <= a && a <= 100 && 1 <= b && b <= 10 ==>
        a % b <= 10 && a % b >= 0;
*/

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
