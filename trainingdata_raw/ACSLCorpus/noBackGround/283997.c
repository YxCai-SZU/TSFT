/*@
    requires n >= 0;
    ensures \result == ((n) == 0 ? 0 : (n) * (n) * (n));
    assigns \nothing;
*/
int compute_volume_cube(int n) {
    int result = 0;
    
    //@ ghost int i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant result == ((i) == 0 ? 0 : (i) * (i) * (i));
        loop assigns i, result;
        loop variant n - i;
    */
    for (int i = 0; i < n; ++i) {
        //@ assert i * i * i == ((i) == 0 ? 0 : (i) * (i) * (i));
        result = (i + 1) * (i + 1) * (i + 1);
    }
    
    //@ assert result == ((n) == 0 ? 0 : (n) * (n) * (n));
    return result;
}

int main() {
    return 0;
}
