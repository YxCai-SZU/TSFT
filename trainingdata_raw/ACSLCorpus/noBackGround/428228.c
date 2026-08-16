/*@
    requires n > 0;
    ensures \result == 1;
    assigns \nothing;
*/
int func(int n) {
    int result;
    
    //@ assert n + 1 <= n + 2;
    //@ assert n + 2 <= n + 3;
    //@ assert n + 1 <= n + 3;
    
    result = 1;
    return result;
}

int main() {
    int x;
    int r;
    
    x = 5;
    r = func(x);
    return 0;
}
