/*@
    requires x >= 0 && y >= 0;
    ensures \result >= x && \result >= y;
    assigns \nothing;
*/
int add(int x, int y) {
    //@ assert x >= 0 && y >= 0;
    int result = x + y;
    //@ assert result >= x;
    //@ assert result >= y;
    return result;
}

int main() {
    int a = 10;
    int b = 20;
    int s = add(a, b);
    //@ assert s >= a;
    //@ assert s >= b;
    return 0;
}
