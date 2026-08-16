/*@
    requires 1 <= a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int func(int a)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= a * a && a * a <= 100;
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    
    int result;
    result = a + a * a + a * a * a;
    return result;
}

int main(void)
{
    return 0;
}
