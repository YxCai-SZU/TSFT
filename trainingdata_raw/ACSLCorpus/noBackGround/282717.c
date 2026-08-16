/*@
    requires (1 <= (r) && (r) <= 100);
    ensures ((\result) == 3 * (r) * (r));
    ensures ((\result) >= 0);
*/
int func(int r) {
    int result;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 1 <= 3 * r && 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;
    
    result = 3 * r * r;
    return result;
}

int main() {
    return 0;
}
