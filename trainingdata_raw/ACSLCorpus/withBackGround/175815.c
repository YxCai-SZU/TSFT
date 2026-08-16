/*@
    predicate non_linear_1(integer a, integer b) =
        0 <= a && a <= 10 && 0 <= b && b <= 10 ==> a * b <= 100;

    predicate non_linear_2(integer a, integer b) =
        0 <= a && a <= 5 && 0 <= b && b <= 5 ==> a * b <= 25;

    predicate non_linear_3(integer x, integer y, integer z) =
        0 <= x && x <= 5 && 0 <= y && y <= 5 && 0 <= z && z <= 5 ==> x * y * z <= 125;

    predicate non_linear_4(integer a, integer b, integer c) =
        0 <= a && a <= 5 && 0 <= b && b <= 5 && 0 <= c && c <= 5 ==> a * b * c <= 125;

    predicate non_linear_5(integer d, integer e) =
        0 <= d && d <= 10 && 0 <= e && e <= 10 ==> d * e <= 100;

    lemma nonlinear_example_1: \forall integer a, b; non_linear_1(a, b);
    lemma nonlinear_example_2: \forall integer a, b; non_linear_2(a, b);
    lemma nonlinear_example_3: \forall integer x, y, z; non_linear_3(x, y, z);
    lemma nonlinear_example_4: \forall integer a, b, c; non_linear_4(a, b, c);
    lemma nonlinear_example_5: \forall integer d, e; non_linear_5(d, e);
*/

int main() {
    return 0;
}
