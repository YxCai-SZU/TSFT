/*@
    requires r > 0;
    ensures \result > 0;
    assigns \nothing;
*/
int compute_square(int r) {
    int result;
    
    //@ assert r > 0;
    result = r * r;
    //@ assert result > 0;
    
    return result;
}

int main() {
    return 0;
}
