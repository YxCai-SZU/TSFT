/*@
    logic integer volume_cube(integer edge_length) = edge_length * edge_length * edge_length;
    
    predicate volume_cube_positive(integer edge_length) =
        edge_length >= 0 && edge_length < 1290 ==> volume_cube(edge_length) >= 0;
    
    predicate volume_cube_bound(integer edge_length) =
        edge_length >= 0 && edge_length < 1290 ==> 
        volume_cube(edge_length) <= edge_length * edge_length * edge_length;
    
    lemma volume_cube_property:
        \forall integer edge_length;
        edge_length >= 0 && edge_length < 1290 ==>
        volume_cube(edge_length) >= 0 && volume_cube(edge_length) <= edge_length * edge_length * edge_length;
*/

/*@
    requires edge_length >= 0 && edge_length < 1290;
    ensures \result == volume_cube(edge_length);
    ensures \result >= 0;
    ensures \result <= edge_length * edge_length * edge_length;
*/
int compute_volume_cube(int edge_length) {
    int result;
    
    //@ assert edge_length >= 0 && edge_length < 1290;
    result = edge_length * edge_length * edge_length;
    
    //@ assert result == volume_cube(edge_length);
    //@ assert result >= 0;
    //@ assert result <= edge_length * edge_length * edge_length;
    
    return result;
}

int main() {
    int volume;
    
    volume = compute_volume_cube(5);
    
    //@ assert volume >= 0;
    //@ assert volume <= 5 * 5 * 5;
    
    return 0;
}
