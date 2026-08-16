/*@
    requires 1 <= r <= 100;
    ensures \result == r * r;
    ensures \result <= 10000;
*/
int func(int r)
{
    int result;
    
    //@ assert 1 <= r <= 100;
    //@ assert r * r <= 10000;
    
    result = r * r;
    return result;
}

int main()
{
    return 0;
}
