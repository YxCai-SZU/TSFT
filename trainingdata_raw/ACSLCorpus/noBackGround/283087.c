/*@
requires ((a) <= 5) && (5 <= (b) && (b) <= 9);
ensures ((a) <= 9);
*/
void func(int a, int b) {
    //@ assert a <= 5 && 5 <= b && b <= 9;
    //@ assert a <= 9;
}

int main() {
    return 0;
}
