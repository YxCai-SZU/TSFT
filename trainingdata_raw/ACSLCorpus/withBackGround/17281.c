/*@
    logic integer add(integer x, integer y) = x + y;

    lemma calc_example_add:
        \forall integer a, b; a > 0 && b > 0 ==> add(a, b) >= 2;

    lemma add_example_add:
        \forall integer c, d; c > 0 && d > 0 ==> add(c, d) >= 2;

    lemma add_equality_add:
        \forall integer e, f; e > 0 && f > 0 ==> add(e, f) == e + f;
*/

int main() {
    //@ assert \true;
    return 0;
}
