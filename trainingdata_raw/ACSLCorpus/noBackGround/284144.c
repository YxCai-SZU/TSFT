/*@
    requires ((length) >= 0 && (length) <= 10000);
    requires ((width) >= 0 && (width) <= 10000);
    ensures \result == ((length) * (width));
    ensures ((\result) >= 0);
*/
int rectangle_area(int length, int width)
{
    // Variable declarations at top of scope
    int result;

    //@ assert ((length) >= 0);
    //@ assert ((width) >= 0);
    //@ assert ((length) >= 0 && (length) <= 10000);
    //@ assert ((width) >= 0 && (width) <= 10000);
    //@ assert ((length) * (width)) >= 0;
    //@ assert ((length) * (width)) <= 100000000;

    result = length * width;
    return result;
}
