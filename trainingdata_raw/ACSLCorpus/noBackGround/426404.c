/*@
    requires (1 <= (a) <= 100);
    ensures ((\result) == (a) * (1 + (a) * (1 + (a))));
    assigns \nothing;
*/
int func(int a)
{
    int a1;
    int result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= 1 + a && 1 + a <= 101;
    //@ assert 1 <= a * (1 + a) && a * (1 + a) <= 100 * 101;
    
    a1 = a * (1 + a);
    
    //@ assert 1 <= 1 + a1 && 1 + a1 <= 101 + 100 * 101;
    //@ assert 1 <= a * (1 + a1) && a * (1 + a1) <= 100 * (101 + 100 * 101);
    
    result = a * (1 + a1);
    return result;
}
