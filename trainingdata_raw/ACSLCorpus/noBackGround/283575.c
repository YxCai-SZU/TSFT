/*@
    requires ((s) > 0 && (l) > 0);
    requires ((s) * (l) <= 2147483647);
    ensures \result == ((s) * (l));
    assigns \nothing;
*/
int perimeter_polygon(int s, int l)
{
    //@ assert ((s) > 0 && (l) > 0);
    //@ assert ((s) * (l) <= 2147483647);
    
    int ret;
    ret = s * l;
    
    //@ assert ret == ((s) * (l));
    return ret;
}
