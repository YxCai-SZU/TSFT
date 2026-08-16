/*@
    logic integer cube_volume(integer s) =
        s <= 0 ? 0 : s * s * s;

    lemma cube_volume_nonnegative:
        \forall integer s; s >= 0 ==> cube_volume(s) >= 0;
*/

/*@
    requires s >= 0;
    ensures \result == cube_volume(s);
    ensures \result >= 0;
*/
int compute_cube_volume(int s) {
    int volume;
    int temp_s;

    //@ assert s >= 0;
    
    if (s <= 0) {
        volume = 0;
    } else {
        temp_s = s - 1;
        //@ assert temp_s >= 0;
        //@ assert cube_volume(temp_s) >= 0;
        volume = s * s * s;
    }
    
    //@ assert volume >= 0;
    return volume;
}

int main() {
    int result;
    
    result = compute_cube_volume(3);
    //@ assert result == 27;
    
    result = compute_cube_volume(0);
    //@ assert result == 0;
    
    result = compute_cube_volume(5);
    //@ assert result == 125;
    
    return 0;
}
