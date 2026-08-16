/*@
requires a <= b;
ensures \result == 1;
assigns \nothing;
*/
int test_calc(int a, int b) {
    //@ assert a <= b;
    //@ assert a <= b + 2;
    return 1;
}

int main() {
    return 0;
}
