/*@
    requires n >= 3;
    ensures \result == ((n) <= 3 ? 180 * (n) : 180 * (n) - 360);
    ensures \result >= 0;
*/
int compute_sum_interior_angles(int n) {
    int result;
    
    //@ assert n >= 3;
    
    if (n <= 3) {
        result = 180 * n;
        //@ assert result == ((n) <= 3 ? 180 * (n) : 180 * (n) - 360);
    } else {
        result = 180 * n - 360;
        //@ assert result == ((n) <= 3 ? 180 * (n) : 180 * (n) - 360);
    }
    
    //@ assert result >= 0;
    return result;
}

int main() {
    int n = 5;
    int sum = compute_sum_interior_angles(n);
    return 0;
}
