/*@
    predicate pos_int(integer v) = v > 0;
    predicate bounded_u32(integer v) = 0 <= v && v <= 8;
*/

/*@
    lemma non_linear_arith_example10:
        \forall integer x, y; bounded_u32(x) && bounded_u32(y) ==> x * y <= 64;
*/

/*@
    lemma non_linear_arith_example11:
        \forall integer x, y, z; pos_int(x) && pos_int(y) && pos_int(z) ==> x * (y * z) == (x * y) * z;
*/

/*@
    lemma non_linear_arith_example12:
        \forall integer a, b; pos_int(a) && pos_int(b) ==> a * b == b * a;
*/

int main() {
    return 0;
}
