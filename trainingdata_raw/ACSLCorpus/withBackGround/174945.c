/*@
predicate positive(integer v) = v > 0;

lemma non_linear_arith_example1:
    \forall integer x, y; positive(x) && positive(y) ==> x * y == y * x;

lemma non_linear_arith_example2:
    \forall integer x, y, z; positive(x) && positive(y) && positive(z) ==> 
        x * y == y * x && x * (y * z) == (x * y) * z;

lemma non_linear_arith_example3:
    \forall integer x, y; positive(x) && positive(y) ==> 
        x * y == y * x && (0 <= x && x <= y && 0 <= 1 && 1 <= 2 ==> x * 1 <= y * 2);
*/

int main() {
    return 0;
}
