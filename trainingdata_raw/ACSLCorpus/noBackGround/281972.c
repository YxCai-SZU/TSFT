/*@
    requires 0 <= y < 32;
    ensures \result == 0;
    assigns \nothing;
*/
int test_left_shift(int y) {
    //@ assert ((1 << (y)) == (1LL << (y)));
    return 0;
}

/*@
    requires 0 <= y < 32;
    requires 0 <= x < 2147483648;
    ensures \result == 0;
    assigns \nothing;
*/
int test_right_shift(int x, int y) {
    //@ assert (((long long)(x) >> (y)) == ((x) >> (y)));
    return 0;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
