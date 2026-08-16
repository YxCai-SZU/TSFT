/*@
    requires (1 <= (n) && (n) <= 100) && (1 <= (x) && (x) <= 100000);
    ensures \result == (x >= ((n) * 500) - 1 && x <= ((n) * 500));
    assigns \nothing;
*/
_Bool func(int n, int x)
{
    int en;
    en = n * 500;
    //@ assert en == ((n) * 500);
    return x >= en - 1 && x <= en;
}
