/*@
    requires 1 <= r <= 9;
    requires 1 <= g <= 9;
    requires 1 <= b <= 9;
    ensures \result == (((r) * 100 + (g) * 10 + (b)) % 4 == 0);
*/
int func(int r, int g, int b) {
    int n;
    //@ assert (1 <= (r) <= 9);
    //@ assert (1 <= (g) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert 1 <= ((r) * 100 + (g) * 10 + (b)) <= 999;
    
    n = r * 100 + g * 10 + b;
    
    /*@
        loop invariant 0 <= n <= ((r) * 100 + (g) * 10 + (b));
        loop invariant n % 4 == ((r) * 100 + (g) * 10 + (b)) % 4;
        loop assigns n;
    */
    while (n >= 4) {
        n -= 4;
    }
    
    //@ assert n == ((r) * 100 + (g) * 10 + (b)) % 4;
    return n == 0;
}

int main() {
    return 0;
}
