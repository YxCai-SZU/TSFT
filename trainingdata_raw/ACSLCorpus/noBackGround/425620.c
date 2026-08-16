/*@
requires a + b >= 5;
ensures b + a >= 5;
*/
void calc_geq_example_func(int a, int b) {
    //@ assert a + b >= 5;
    //@ assert b + a >= 5;
}

/*@
requires a >= 1 && b >= 5;
ensures b * a >= 5;
*/
void ensure_b_times_a_geq_5_func(int a, int b) {
    //@ assert a >= 1 && b >= 5;
    //@ assert b * a >= 5;
}

int main() {
    return 0;
}
