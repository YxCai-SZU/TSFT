/*@
requires n >= 0;
ensures n + 1 > n;
*/
void monotonicity(int n) {
    //@ assert n >= 0;
    //@ assert n + 1 > n;
}

/*@
requires x >= 0;
ensures x >= 0;
*/
void non_negativity(int x) {
    //@ assert x >= 0;
}

/*@
requires n > 0;
ensures n > 0;
*/
void positive_values(int n) {
    //@ assert n > 0;
}

/*@
requires x >= 0 && y >= 0;
ensures x + y >= x;
*/
void add_monotonicity(int x, int y) {
    //@ assert x >= 0;
    //@ assert y >= 0;
    //@ assert x + y >= x;
}

int main() {
    return 0;
}
