/*@
    requires (1 <= (k) && (k) <= 100 &&
        1 <= (x) && (x) <= 100000 &&
        (k) * 500 >= (x));
    ensures \result == 0;
    ensures 500 * k - x >= 0;
*/
int func(int k, int x) {
    //@ assert k * 500 >= x;
    //@ assert 500 * k - x >= 0;
    return 0;
}

int main() {
    return 0;
}
