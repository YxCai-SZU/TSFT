/*@
    requires \true;
    ensures \result >= x;
    assigns \nothing;
*/
unsigned int func(unsigned int x)
{
    unsigned int ans;
    //@ ghost unsigned int original_x = x;

    if (x != 0)
    {
        ans = x;
        //@ assert ans == original_x;
    }
    else
    {
        ans = 1;
        //@ assert ans == 1;
    }

    //@ assert ans >= original_x;
    return ans;
}
