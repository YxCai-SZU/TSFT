/*@
    requires ((x) % 2 == 0);
    ensures \result % 2 == 0;
*/
int three_times_even_is_even(int x) {
    //@ assert ((x) % 2 == 0);
    int result;
    result = 3 * x;
    //@ assert result % 2 == 0;
    return result;
}

int main() {
    return 0;
}
