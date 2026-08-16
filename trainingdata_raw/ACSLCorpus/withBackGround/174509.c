/*@
    predicate example_5_pre(integer x, integer y) =
        0 <= x && x < y && y < 10;

    predicate example_5_post(integer x, integer y) =
        x < y + 1 && y * 2 < 20;

    lemma example_5_lemma:
        \forall integer x, y;
        example_5_pre(x, y) ==> example_5_post(x, y);
*/

/*@
    requires example_5_pre(x, y);
    ensures example_5_post(x, y);
*/
void example_5(int x, int y) {
    // Variable declarations at top of scope
    int tmp;

    // Proof that x < y + 1
    //@ assert x <= x + 1;
    //@ assert x + 1 <= y + 1;
    //@ assert x < y + 1;

    // Proof that y * 2 < 20
    //@ assert 0 <= y * 2 && y * 2 <= 18;
    //@ assert y * 2 < 20;
}

int main() {
    return 0;
}
