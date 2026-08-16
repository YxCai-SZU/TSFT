/*@
    logic integer sum(integer x, integer y) = x + y;
    logic integer diff(integer x, integer y) = x - y;
    logic integer product(integer x, integer y) = x * y;
*/

/*@ lemma calc_example_sum:
        \forall integer a, b;
            a >= 0 && b >= 0 ==> sum(a, b) >= a && sum(a, b) >= b;
*/

/*@ lemma calc_example_diff:
        \forall integer a, b;
            a >= b ==> diff(a, b) >= 0;
*/

/*@ lemma calc_example_product:
        \forall integer a, b;
            a >= 0 && b >= 0 && a <= 1 && b <= 1 ==>
                product(a, b) >= 0 &&
                product(a, b) <= a &&
                product(a, b) <= b;
*/

int main() {
    return 0;
}
