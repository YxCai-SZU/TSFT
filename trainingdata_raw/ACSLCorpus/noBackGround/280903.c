/*@
    requires a <= b;
    ensures \result == 1;
*/
int assert_common_relations(int a, int b) {
    //@ assert a <= b;
    //@ assert a + 0 <= b + 0;
    //@ assert a * 2 <= b * 2;
    return 1;
}

int main() {
    return 0;
}
