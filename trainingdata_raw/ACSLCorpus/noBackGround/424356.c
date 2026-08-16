/*@
    requires ((x) > 0) && ((y) > 0) && ((z) > 0);
    requires (0 <= (x) <= 100) && (0 <= (y) <= 100) && (0 <= (z) <= 100);
    ensures \result == 0;
    ensures x * y <= 10000;
    ensures x * z <= 10000;
    ensures x * (y + z) <= 20000;
*/
int example_8(int x, int y, int z)
{
    //@ assert (0 <= (x) <= 100) && (0 <= (y) <= 100);
    //@ assert x * y <= 10000;
    
    //@ assert (0 <= (x) <= 100) && (0 <= (z) <= 100);
    //@ assert x * z <= 10000;
    
    //@ assert (0 <= (x) <= 100) && (0 <= (y) <= 100) && (0 <= (z) <= 100);
    //@ assert x * (y + z) <= 20000;
    
    //@ assert ((x) > 0) && ((y) > 0) && ((z) > 0);
    //@ assert 0 <= x * (y + z);
    
    return 0;
}
