/*@
    predicate bounds_two(integer x, integer y) =
        x <= 10 && y <= 20 ==> x * y <= 200 && x * y >= 0;

    predicate bounds_three(integer x, integer y, integer z) =
        x <= 10 && y <= 20 && z <= 30 ==>
        x * y <= 200 && x * y >= 0 &&
        y * z <= 600 && y * z >= 0;

    lemma verify_upper_bound: \forall integer x, y;
        0 <= x <= 10 && 0 <= y <= 20 ==> x * y <= 200;

    lemma verify_bounds: \forall integer x, y;
        0 <= x <= 10 && 0 <= y <= 20 ==> x * y <= 200 && x * y >= 0;

    lemma verify_bounds_three: \forall integer x, integer y, integer z;
        0 <= x <= 10 && 0 <= y <= 20 && 0 <= z <= 30 ==>
        x * y <= 200 && x * y >= 0 &&
        y * z <= 600 && y * z >= 0;
*/

/*@
    requires \true;
    assigns \nothing;
*/
int main() {
    return 0;
}
