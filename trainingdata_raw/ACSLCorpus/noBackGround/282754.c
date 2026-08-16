/*@
    requires (1 <= (A) && (A) <= 100) && (1 <= (B) && (B) <= 100);
    ensures \result == (((A) * 3) - (B));
    assigns \nothing;
*/
int func(int A, int B)
{
    int result;
    
    //@ assert A * 3 <= 300;
    //@ assert B <= 100;
    //@ assert (A * 3) - B <= 299;
    
    result = (A * 3) - B;
    
    return result;
}
