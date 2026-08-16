/*@
    requires x <= y && y <= z;
    ensures x <= z;
*/
void calc_combined_example_1(int x, int y, int z) {
    //@ assert x <= y;
    //@ assert y <= z;
    //@ assert x <= z;
}

/*@
    requires a <= b && b <= c && c <= d;
    ensures a <= d;
*/
void calc_combined_example_2(int a, int b, int c, int d) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert c <= d;
    //@ assert a <= d;
}

/*@
    requires x > 10 && x % 2 == 0;
    ensures \true;
*/
void is_even_and_greater_than_10(int x) {
    //@ assert x > 10 && x % 2 == 0;
    //@ assert x % 2 == 0;
    //@ assert \true;
}

int main() {
    return 0;
}
