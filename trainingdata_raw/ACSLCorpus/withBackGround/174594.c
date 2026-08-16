/*@
    predicate range(integer a, integer b, integer c) =
        0 <= a && a <= b && b <= 100 && 0 <= c && c <= 100;

    lemma multiply_range_true:
        \forall integer a, b, c;
            range(a, b, c) ==> 0 <= a * c && a * c <= b * c;
*/

int main() {
    //@ assert \true;
    return 0;
}
