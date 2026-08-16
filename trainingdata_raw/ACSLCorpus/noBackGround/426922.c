/*@
requires ((a) <= (b));
ensures ((a + 1) <= (b + 1));
assigns \nothing;
*/
void calc_example_i(int a, int b) {
    //@ assert ((a) <= (b));
}

/*@
requires ((a) <= (b));
ensures ((a + 1) <= (b + 1));
assigns \nothing;
*/
void example_i_inequality(int a, int b) {
    //@ assert ((a) <= (b));
}

/*@
requires ((a) == (a));
ensures ((a) == (a));
assigns \nothing;
*/
void example_i_identity(int a) {
    //@ assert ((a) == (a));
}

/*@
requires 0 <= n;
requires ((n) % 2 == 0 || (n) % 2 == 1);
ensures ((n) % 2 == 0 || (n) % 2 == 1);
assigns \nothing;
*/
void example_i_even_odd(int n) {
    //@ assert ((n) % 2 == 0 || (n) % 2 == 1);
}

/*@
requires ((a) > 0);
ensures ((a) > 0);
assigns \nothing;
*/
void example_i_strictly_greater_than_zero(int a) {
    //@ assert ((a) > 0);
}

/*@
requires ((a) < 0);
ensures ((a) < 0);
assigns \nothing;
*/
void example_i_strictly_less_than_zero(int a) {
    //@ assert ((a) < 0);
}

/*@
requires (0 <= (a) && (a) <= 1);
ensures (0 <= (a) && (a) <= 1);
assigns \nothing;
*/
void example_i_range(int a) {
    //@ assert (0 <= (a) && (a) <= 1);
}

/*@
assigns \nothing;
*/
int main() {
    return 0;
}
