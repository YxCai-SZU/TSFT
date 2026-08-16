/*@
    requires 0 <= side <= 0x10000;
    ensures \result == ((((side)) * ((side)) * ((side))));
    ensures \result >= 0;
    assigns \nothing;
*/
int compute_cube_volume(int side)
{
    int result;
    //@ assert side >= 0 && side <= 0x10000;
    result = side * side * side;
    //@ assert result == ((((side)) * ((side)) * ((side))));
    //@ assert result >= 0;
    return result;
}

int main()
{
    return 0;
}
