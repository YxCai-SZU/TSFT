/*@
    requires \true;
    ensures (((\result) == (a) || (\result) == (b) || (\result) == (c)) &&
        ((\result) <= (a) && (\result) <= (b) && (\result) <= (c)));
    assigns \nothing;
*/
int minimum_of_three(int a, int b, int c)
{
    int min_val;
    min_val = a;
    //@ assert min_val == a;
    if (b < min_val)
    {
        min_val = b;
        //@ assert min_val == b;
    }
    //@ assert min_val <= a && min_val <= b;
    if (c < min_val)
    {
        min_val = c;
        //@ assert min_val == c;
    }
    //@ assert min_val <= a && min_val <= b && min_val <= c;
    //@ assert (((min_val) == (a) || (min_val) == (b) || (min_val) == (c)) &&         ((min_val) <= (a) && (min_val) <= (b) && (min_val) <= (c)));
    return min_val;
}
