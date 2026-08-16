/*@
    logic integer min_int(integer x, integer y) =
        x <= y ? x : y;

    lemma min_int_is_monotonic:
        \forall integer x, y, z;
            x <= y && y <= z ==> min_int(x, z) <= min_int(y, z);
*/

int main() {
    // Variable declarations
    int x = 0;
    int y = 0;
    int z = 0;
    
    // Verification of monotonic property
    //@ assert x <= y && y <= z ==> min_int(x, z) <= min_int(y, z);
    
    return 0;
}
