/*@
    requires (0 <= (x) <= 100) && (0 <= (y) <= 100) && (0 <= (z) <= 100);
    ensures ((\result) >= 0);
    ensures \result <= ((x) * (y)) + z;
*/
int non_linear_arith_example(int x, int y, int z)
{
    //@ assert (0 <= (x) <= 100);
    //@ assert (0 <= (y) <= 100);
    //@ assert (0 <= (z) <= 100);
    
    //@ assert 0 <= x * y <= 100 * 100;
    
    int result;
    result = x * y + z;
    
    //@ assert ((result) >= 0);
    //@ assert result <= ((x) * (y)) + z;
    
    return result;
}
