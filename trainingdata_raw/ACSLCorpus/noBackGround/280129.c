/*@
    requires 1 <= a && a <= 5;
    ensures \result == a + 3;
    assigns \nothing;
*/
int func(int a)
{
    int x;
    int res;
    
    x = 3;
    
    //@ assert 1 <= a && a <= 5;
    //@ assert 3 <= a + 3 && a + 3 <= 8;
    
    res = a + x;
    
    //@ assert res == a + 3;
    return res;
}

int main()
{
    return 0;
}
