int main() {
    return 0;
}

/*@
requires n > 3;
ensures \result > 3;
*/
int example_s_usage(int n) {
    //@ assert ((n)) > 3;
    return n;
}
