/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    ensures ((((\result)) == 3 * ((r)) * ((r))));
*/
int func(int r)
{
    int result;
    
    //@ assert 1 <= r && r <= 100;
    
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    result = 3 * r * r;
    
    //@ assert ((result) == 3 * (r) * (r));
    
    return result;
}

int main()
{
    return 0;
}
