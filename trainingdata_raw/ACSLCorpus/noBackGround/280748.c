/*@
    requires (1 <= (x) && (x) <= 179);
    assigns \nothing;
    ensures ((\result) == 360 - (180 - (x)) * 2);
*/
int func(int x)
{
    int result;
    //@ assert 1 <= x && x <= 179;
    //@ assert 0 <= 180 - x && 180 - x <= 179;
    //@ assert 0 <= (180 - x) * 2 && (180 - x) * 2 <= 358;
    result = 360 - (180 - x) * 2;
    return result;
}
