/*@
    requires (1 <= (x) <= 8 && 1 <= (y) <= 8 && 1 <= (z) <= 8);
    ensures \result == (((x) * (y)) * (z));
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    // Variable declarations at scope top
    int result;
    
    //@ assert 1 <= x <= 8 && 1 <= y <= 8;
    //@ assert 1 <= z <= 8;
    //@ assert x * y <= 64;
    //@ assert (x * y) * z <= 512;
    
    result = (x * y) * z;
    return result;
}
