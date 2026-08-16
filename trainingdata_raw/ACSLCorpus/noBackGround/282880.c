/*@
requires x < y;
ensures x < y + 1;
*/
void func(int x, int y) {
    //@ assert x < y;
}

/*@
requires a <= b;
ensures a + 1 <= b + 1;
*/
void func1(int a, int b) {
    //@ assert a <= b;
}

/*@
requires c == d;
ensures c + 1 == d + 1;
*/
void func2(int c, int d) {
    //@ assert c == d;
}

int main() {
    return 0;
}
