/*@
    requires 0 <= l <= 100;
    requires 0 <= w <= 100;
    requires 0 <= h <= 100;
    ensures \result == l * w * h;
    assigns \nothing;
*/
int volume_rectangular_prism(int l, int w, int h)
{
    //@ assert 0 <= l && l <= 100;
    //@ assert 0 <= w && w <= 100;
    //@ assert 0 <= h && h <= 100;
    //@ assert l * w <= 10000;
    //@ assert l * w * h <= 1000000;
    
    return l * w * h;
}

int main()
{
    return 0;
}
