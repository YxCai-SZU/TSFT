/*@
    requires x >= 0;
    ensures \result >= 0;
*/
int compute_v_pos(int x) {
    int result;
    /*@ assert x >= 0; */
    result = 2 * x + 3;
    /*@ assert result == (2 * (x) + 3); */
    /*@ assert result >= 0; */
    return result;
}

/*@
    requires x <= 0;
    ensures \result <= 3;
*/
int compute_v_neg(int x) {
    int result;
    /*@ assert x <= 0; */
    result = 2 * x + 3;
    /*@ assert result == (2 * (x) + 3); */
    /*@ assert result <= 3; */
    return result;
}

int main() {
    return 0;
}
