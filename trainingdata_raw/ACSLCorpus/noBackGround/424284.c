/*@
    requires (1 <= (n) <= 100);
    ensures \result == 0;
*/
int func(int n) {
    //@ assert (1 <= (n) <= 100);
    
    //@ assert 2 <= n + 1 <= 101;
    //@ assert 2 <= n + 3 <= 103;
    //@ assert 2 <= n + 5 <= 105;
    //@ assert 3 <= n + 4 <= 104;
    
    return 0;
}

int main() {
    return 0;
}
