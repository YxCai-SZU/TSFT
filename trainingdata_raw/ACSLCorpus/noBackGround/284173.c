/*@
requires a > b && b >= c;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_4_impl(char a, char b, char c) {
    //@ assert a > b;
    //@ assert b >= c;
    //@ assert a >= c;
    return 0;
}

/*@
requires a < b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_5_impl(signed char a, signed char b, signed char c) {
    //@ assert a < b;
    //@ assert b <= c;
    //@ assert a < c;
    return 0;
}

/*@
requires a == b && b == c;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_6_impl(signed char a, signed char b, signed char c) {
    //@ assert a == b;
    //@ assert b == c;
    //@ assert a == c;
    return 0;
}

int main() {
    return 0;
}
