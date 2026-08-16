/*@
    requires ((n) < 10);
    ensures ((n) <= 9);
*/
void check_less_or_equal(int n) {
    //@ assert n <= 9;
}

int main() {
    return 0;
}
