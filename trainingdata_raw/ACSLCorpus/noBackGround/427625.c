/*@
requires ((a) == (b + c));
ensures ((a) <= (b + c + 1));
*/
void example_3(int a, int b, int c) {
    //@ assert ((a) == (b + c));
    //@ assert ((a) <= (b + c + 1));
}

/*@
requires ((d) == (e * f));
ensures ((d) >= (e * f - 1));
*/
void example_4(int d, int e, int f) {
    //@ assert ((d) == (e * f));
    //@ assert ((d) >= (e * f - 1));
}

int main() {
    return 0;
}
