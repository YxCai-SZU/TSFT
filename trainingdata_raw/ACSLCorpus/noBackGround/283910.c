/*@
requires ((a) == 5);
ensures ((a + 1) == 6);
*/
void calc_example(int a) {
    //@ assert a == 5;
    //@ assert a + 1 == 6;
}

int main() {
    int a;
    a = 5;
    //@ assert ((a) == 5);
    calc_example(a);
    return 0;
}
