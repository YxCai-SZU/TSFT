/*@
    requires ((length) >= 0) && ((width) >= 0);
    requires ((length) * (width) <= 2147483647);
    ensures \result == length * width;
    assigns \nothing;
*/
int area_rectangle(int length, int width)
{
    // Variable declarations at the top of the scope
    int result;

    //@ assert ((length) >= 0) && ((width) >= 0);
    //@ assert ((length) * (width) <= 2147483647);
    //@ assert length * width <= 2147483647;

    result = length * width;
    return result;
}
