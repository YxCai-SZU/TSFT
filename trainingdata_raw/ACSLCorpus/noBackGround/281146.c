/*@
requires a < b;
requires b < c;
ensures a < c;
*/
void func(int a, int b, int c) {
    //@ assert a < b;
    //@ assert b < c;
    //@ assert a < c;
}

int main() {
    return 0;
}
