/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
*/
_Bool func(unsigned int n, unsigned int m) {
    unsigned int sub;
    unsigned int i;
    
    sub = 0;
    i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (m) &&
        0 <= (sub) <= (n) &&
        (sub) == (i));
        loop assigns sub, i;
        loop variant m - i;
    */
    while (i < m) {
        if (sub < n) {
            sub += 1;
        } else {
            break;
        }
        i += 1;
        
        //@ assert sub == i;
    }
    
    //@ assert i == m;
    //@ assert sub == m;
    
    return sub == n;
}

int main() {
    return 0;
}
