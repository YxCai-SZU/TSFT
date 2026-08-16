/*@
requires ((side) >= 0);
ensures \result == ((side) < 0 ? 0 :
    (side) == 0 ? 0 :
    (side) * (side) * (side));
ensures \result >= 0;
*/
int compute_volume_cube(int side) {
    int result;
    
    //@ assert ((side) >= 0);
    
    if (side < 0) {
        result = 0;
    } else if (side == 0) {
        result = 0;
    } else {
        result = side * side * side;
    }
    
    //@ assert result == ((side) < 0 ? 0 :     (side) == 0 ? 0 :     (side) * (side) * (side));
    //@ assert result >= 0;
    
    return result;
}

int main() {
    return 0;
}
