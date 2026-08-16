/*@
    requires (0 <= (r) <= 4500 && 0 <= (g) <= 4500);
    ensures \result == ((g) * 2 - (r));
    assigns \nothing;
*/
int func(int r, int g)
{
    int result;
    
    //@ assert g * 2 - r == g * 2 - r;
    
    result = g * 2 - r;
    return result;
}
