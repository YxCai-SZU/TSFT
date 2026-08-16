/*@
    requires x > 0;
    ensures \result > 0;
*/
int compute_t(int x) {
    int result;
    //@ assert x > 0;
    result = x + 3;
    //@ assert result == ((x) + 3);
    //@ assert result > 0;
    return result;
}

int main() {
    return 0;
}
