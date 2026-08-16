/*@
    requires 0 <= x <= 1;
    ensures \result == (1 - (x));
    ensures ((\result) == 0 || (\result) == 1);
*/
int func(int x)
{
    int ret;
    //@ assert 0 <= x <= 1;
    
    if (x == 0) {
        ret = 1;
    } else if (x == 1) {
        ret = 0;
    } else {
        ret = -1;
    }
    
    //@ assert ret == (1 - (x));
    //@ assert ((ret) == 0 || (ret) == 1);
    
    return ret;
}
