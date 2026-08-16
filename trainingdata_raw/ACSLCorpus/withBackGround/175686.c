/*@
    logic integer min(integer x, integer y) = (x <= y) ? x : y;

    lemma min_is_monotonic:
        \forall integer a, b, c;
            a <= b ==> min(a, c) <= min(b, c);
*/

/*@
    requires \true;
    ensures \true;
*/
void test_min_monotonic(void) {
    //@ assert min(3, 5) <= min(5, 5);
    //@ assert min(2, 4) <= min(4, 4);
    //@ assert min(1, 3) <= min(3, 3);
}

int main() {
    test_min_monotonic();
    return 0;
}
