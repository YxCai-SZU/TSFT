/*@
    logic integer max(integer a, integer b) = (a > b) ? a : b;

    lemma max_monotonic:
        \forall integer x, y, z;
            x <= y ==> max(x, z) <= max(y, z);
*/

/*@
    requires \true;
    ensures max(5, 3) <= max(8, 3);
*/
void test_max_monotonic(void) {
    //@ assert max(5, 3) <= max(8, 3);
}

int main(void) {
    test_max_monotonic();
    return 0;
}
