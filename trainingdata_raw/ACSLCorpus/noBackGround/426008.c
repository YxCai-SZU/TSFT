/*@
requires x == y;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_16_impl(int x, int y) {
    //@ assert ((x) == (y));
    //@ assert ((x) == (y + 1 - 1));
    return 0;
}

/*@
requires a <= b;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_17_impl(int a, int b) {
    //@ assert ((a) <= (b));
    //@ assert ((a) <= (b + 3 - 3));
    return 0;
}

/*@
requires x == y;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_18_impl(int x, int y) {
    //@ assert ((x) == (y));
    //@ assert ((x + 2) == (y + 2));
    return 0;
}

/*@
requires a <= b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int assert_is_transitive_impl(int a, int b, int c) {
    //@ assert ((a) <= (c));
    return 0;
}

/*@
requires a <= b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int non_transitive_example_impl(int a, int b, int c) {
    //@ assert ((a) <= (c));
    return 0;
}

/*@
requires a <= b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int multi_step_non_transitive_impl(int a, int b, int c) {
    //@ assert ((a) <= (b));
    //@ assert (((c)) <= (c));
    //@ assert ((a) <= (c));
    return 0;
}

int main() {
    return 0;
}
