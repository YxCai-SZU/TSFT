/*@
    predicate non_overflowing_mult(integer x) =
        x >= 0 && x <= 0x1000000 && x * x <= x * 0x1000000;

    logic integer volume_cube(integer edge_length) =
        edge_length * edge_length * edge_length;

    lemma volume_cube_lemma:
        \forall integer x; non_overflowing_mult(x) ==> volume_cube(x) == x * x * x;
*/

/*@
    requires x >= 0 && x <= 0x1000000;
    ensures \result == x * x * x;
    assigns \nothing;
*/
int compute_volume_cube(int x) {
    //@ assert non_overflowing_mult(x);
    //@ assert volume_cube(x) == x * x * x;
    return x * x * x;
}

int main() {
    int result1 = compute_volume_cube(2);
    //@ assert result1 == 8;
    
    int result2 = compute_volume_cube(10);
    //@ assert result2 == 1000;
    
    return 0;
}
