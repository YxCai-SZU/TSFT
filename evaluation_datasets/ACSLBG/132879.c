/*@
    logic integer volume_cube(integer l) = l * l * l;

    lemma volume_cube_nonnegative:
        \forall integer l; l >= 0 && l <= 1 ==> volume_cube(l) >= 0;

    lemma volume_cube_upper_bound:
        \forall integer l; l >= 0 && l <= 1 ==> volume_cube(l) <= l * l * l;

    lemma volume_cube_equality:
        \forall integer l; l >= 0 && l <= 1 ==> volume_cube(l) == l * l * l;
*/


int compute_volume_cube(int l) {
    //@ assert l >= 0 && l <= 1;
    
    int result;
    result = l * l * l;
    
    //@ assert result == volume_cube(l);
    //@ assert result >= 0;
    //@ assert result <= l * l * l;
    //@ assert result == l * l * l;
    
    return result;
}

void test() {
    int volume;
    volume = compute_volume_cube(1);
    
    //@ assert volume == 1;
}
