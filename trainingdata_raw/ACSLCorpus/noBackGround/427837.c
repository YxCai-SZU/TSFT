/*@
    requires 0 <= x <= 5;
    requires 0 <= y <= 5;
    requires 0 <= z <= 5;
    requires 0 <= w <= 5;
    ensures \result <= 50;
*/
int func_2(int x, int y, int z, int w)
{
    //@ assert 0 <= x && x <= 5;
    //@ assert 0 <= y && y <= 5;
    //@ assert 0 <= z && z <= 5;
    //@ assert 0 <= w && w <= 5;
    
    //@ assert x * z <= 25;
    //@ assert y * w <= 25;
    
    //@ assert x * z + y * w <= 50;
    
    return x * z + y * w;
}

int main()
{
    return 0;
}
