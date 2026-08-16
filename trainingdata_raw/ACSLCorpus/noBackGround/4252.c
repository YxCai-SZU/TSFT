/*@
    requires \true;
    ensures (0 <= (\result) && (\result) <= 360);
    assigns \nothing;
*/
int angle_complex(int a, int b)
{
    int ret;
    //@ assert \true;
    ret = 0;
    //@ assert (0 <= (ret) && (ret) <= 360);
    return ret;
}
