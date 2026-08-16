/*@
    requires (0 <= (x) && (x) <= (y) && (y) <= 10 &&
    0 <= (z) && (z) <= 10);
    ensures \result >= 0 && \result <= 100;
*/
int multiply_bounded(int x, int y, int z) {
    // Variable declarations at scope top
    int result;
    
    //@ assert (0 <= (x) && (x) <= (y) && (y) <= 10 &&     0 <= (z) && (z) <= 10);
    
    result = x * z;
    
    //@ assert result >= 0;
    //@ assert result <= 100;
    
    return result;
}

int main() {
    return 0;
}
