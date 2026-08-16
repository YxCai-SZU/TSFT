/*@
predicate le(integer x, integer y) = x <= y;
predicate ge(integer x, integer y) = x >= y;

lemma calc_example_7: \forall integer a, b; a - 2 == b ==> a == b + 2;
lemma less_or_equal: \forall integer x, y; x <= y ==> x <= y;
lemma greater_or_equal: \forall integer x, y; x >= y ==> x >= y;
lemma testcalc: \forall integer a, b, c; a <= b && b <= c ==> a <= c;
*/

/*@
requires a - 2 == b;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_7_impl(int a, int b) {
    //@ assert a == b + 2;
    return 0;
}

/*@
requires x <= y;
ensures \result == 0;
assigns \nothing;
*/
int less_or_equal_impl(int x, int y) {
    //@ assert x <= y;
    return 0;
}

/*@
requires x >= y;
ensures \result == 0;
assigns \nothing;
*/
int greater_or_equal_impl(int x, int y) {
    //@ assert x >= y;
    return 0;
}

/*@
requires a <= b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int testcalc_impl(int a, int b, int c) {
    //@ assert a <= c;
    return 0;
}

int main() {
    return 0;
}
