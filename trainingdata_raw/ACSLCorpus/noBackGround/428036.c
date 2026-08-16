/*@
    requires side >= 0;
    ensures \result == ((side) * (side) * (side));
    ensures \result >= 0;
*/
int compute_volume_cube(int side) {
    int result;
    
    //@ assert side >= 0;
    //@ assert ((side) * (side) * (side)) >= 0;
    
    result = side * side * side;
    
    //@ assert result == ((side) * (side) * (side));
    //@ assert result >= 0;
    
    return result;
}

int main() {
    int volume1;
    int volume2;
    
    volume1 = compute_volume_cube(0);
    //@ assert volume1 >= 0;
    
    volume2 = compute_volume_cube(10);
    //@ assert volume2 >= 0;
    
    return 0;
}
