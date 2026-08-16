/*@
    logic integer cube_volume(integer side) =
        (side == 0) ? 0 : (side * side * side);

    lemma volume_is_nonzero:
        \forall integer side; side > 0 ==> cube_volume(side) > 0;

    lemma volume_is_maximum:
        \forall integer side; side <= 10 ==> cube_volume(side) <= 1000;
*/

/*@
    requires side > 0;
    ensures \result == cube_volume(side);
    ensures \result > 0;
    assigns \nothing;
*/
int compute_cube_volume(int side) {
    int result;
    //@ assert side > 0;
    //@ assert cube_volume(side) > 0;
    
    if (side == 0) {
        result = 0;
    } else {
        result = side * side * side;
    }
    
    //@ assert result == cube_volume(side);
    //@ assert result > 0;
    return result;
}

/*@
    requires side <= 10;
    ensures \result == cube_volume(side);
    ensures \result <= 1000;
    assigns \nothing;
*/
int compute_bounded_volume(int side) {
    int result;
    //@ assert side <= 10;
    //@ assert cube_volume(side) <= 1000;
    
    if (side == 0) {
        result = 0;
    } else {
        result = side * side * side;
    }
    
    //@ assert result == cube_volume(side);
    //@ assert result <= 1000;
    return result;
}

int main() {
    int v1, v5, v10;
    
    // Test case 1
    v1 = compute_cube_volume(1);
    //@ assert v1 == 1;
    //@ assert v1 == cube_volume(1);
    
    // Test case 5
    v5 = compute_cube_volume(5);
    //@ assert v5 == 125;
    //@ assert v5 == cube_volume(5);
    
    // Test case 10
    v10 = compute_bounded_volume(10);
    //@ assert v10 == 1000;
    //@ assert v10 == cube_volume(10);
    
    return 0;
}
