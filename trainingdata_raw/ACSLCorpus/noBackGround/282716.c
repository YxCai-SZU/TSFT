/*@
requires x >= 0;
ensures \result == 3 * x - x && \result == x * 2;
assigns \nothing;
*/
int calc_example_5(int x) {
    //@ assert x >= 0;
    //@ assert 3 * x - x == x * 2;
    return 3 * x - x;
}

int main() {
    int x;
    x = 5;
    //@ assert x >= 0;
    int result = calc_example_5(x);
    //@ assert result == x * 2;
    return 0;
}
