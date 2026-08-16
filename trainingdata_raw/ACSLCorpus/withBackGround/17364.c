/*@
    predicate side_nonnegative(integer side) = side >= 0;
    
    logic integer volume_cube(integer side) =
        side == 0 ? 0 : side * side * side;
    
    lemma volume_cube_positive:
        \forall integer side; side_nonnegative(side) ==> volume_cube(side) >= 0;
*/

/*@
    requires side_nonnegative(side);
    ensures \result == volume_cube(side);
    ensures \result >= 0;
*/
int compute_volume_cube(int side) {
    int result;
    
    //@ assert side_nonnegative(side);
    
    if (side == 0) {
        result = 0;
    } else {
        //@ assert side * side >= 0;
        result = side * side * side;
    }
    
    //@ assert result == volume_cube(side);
    //@ assert result >= 0;
    
    return result;
}

int main() {
    int side = 5;
    int volume;
    
    //@ assert side_nonnegative(side);
    volume = compute_volume_cube(side);
    
    return 0;
}
