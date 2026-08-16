/*@
requires (0 <= (a) && (a) <= 10000) && (0 <= (b) && (b) <= 10000);
requires ((a) >= 10) && ((b) >= 10);
ensures ((a) + (b) >= 20);
ensures ((a) + (b) <= 20000);
*/
void func(int a, int b) {
    //@ assert a >= 10;
    //@ assert b >= 10;
    //@ assert a + b >= 20;
    //@ assert a <= 10000;
    //@ assert b <= 10000;
    //@ assert a + b <= 20000;
}

int main() {
    return 0;
}
