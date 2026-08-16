/*@
requires -2147483648 <= a <= 2147483647;
requires -2147483648 <= b <= 2147483647;
ensures \result == a || \result == b;
ensures \result >= a;
ensures \result >= b;
assigns \nothing;
*/
int maximum_int(int a, int b)
{
    int ret;
    
    if (a > b) {
        //@ assert a >= b;
        ret = a;
    } else {
        //@ assert b >= a;
        ret = b;
    }
    
    //@ assert (((ret) == (a) || (ret) == (b)) && (ret) >= (a) && (ret) >= (b));
    return ret;
}
