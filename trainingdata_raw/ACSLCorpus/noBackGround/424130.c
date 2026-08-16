/*@
    requires 0 <= x <= 8;
    requires 0 <= y <= 8;
    requires 0 <= z <= 8;
    ensures \result == (x * y) + (x * z);
    assigns \nothing;
*/
int lemma_mul_is_distributive_impl(int x, int y, int z) {
    int xy;
    int xz;
    int yz;
    int result;

    xy = x * y;
    //@ assert 0 <= xy <= 64;

    xz = x * z;
    //@ assert 0 <= xz <= 64;

    yz = y + z;
    //@ assert 0 <= yz <= 16;

    result = x * yz;
    //@ assert 0 <= result <= 128;

    //@ assert result == xy + xz;
    return result;
}
