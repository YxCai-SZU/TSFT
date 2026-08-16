/*@
    requires n >= 0;
    ensures \result == ((n) <= 0 ? 0 : (n) * (n));
    ensures \result >= 0;
*/
int compute_square(int n) {
    int result;
    
    //@ assert n >= 0;
    
    if (n <= 0) {
        result = 0;
    } else {
        result = n * n;
    }
    
    //@ assert result == ((n) <= 0 ? 0 : (n) * (n));
    //@ assert result >= 0;
    
    return result;
}

int main() {
    return 0;
}
