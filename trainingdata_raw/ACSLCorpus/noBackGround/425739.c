/*@
    requires 1 <= a && a <= 10;
    ensures \result == a + (a * a) + (a * a * a);
    assigns \nothing;
*/
int func(int a)
{
    int a_pow_2;
    int a_pow_3;
    int result;
    
    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= a * a && a * a <= 100;
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    
    a_pow_2 = a * a;
    a_pow_3 = a * a * a;
    result = a + a_pow_2 + a_pow_3;
    
    //@ assert result == a + (a * a) + (a * a * a);
    return result;
}
