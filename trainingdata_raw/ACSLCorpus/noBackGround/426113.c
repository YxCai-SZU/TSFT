/*@
requires ((a) < (b));
requires ((a) > 1);
requires ((b) > 1);
ensures ((a) - 1 < (b) - 1);
ensures ((a) - 1 > 0);
ensures ((b) - 1 > 0);
*/
void example_usage(int a, int b) {
    //@ assert ((a) - 1 < (b) - 1);
    //@ assert ((a) - 1 > 0);
    //@ assert ((b) - 1 > 0);
}

int main() {
    return 0;
}
