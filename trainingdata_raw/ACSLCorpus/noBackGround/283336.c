/*@
    requires ((a) <= (b) && (b) <= (a) + 3);
    ensures \result == 0;
*/
int calc_example_u(int a, int b) {
    //@ assert b + 3 <= a + 6;
    return 0;
}

int main() {
    return 0;
}
