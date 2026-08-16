/*@
requires 0 <= a;
requires 0 <= b;
requires 0 <= c;
ensures 0 <= a * b * c;
*/
void func(int a, int b, int c) {
    //@ assert 0 <= a;
    //@ assert 0 <= b;
    //@ assert 0 <= c;
    //@ assert 0 <= a * b * c;
}

int main() {
    return 0;
}
