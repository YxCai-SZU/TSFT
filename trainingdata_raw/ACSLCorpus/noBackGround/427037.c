/*@
    requires (0 <= (side) <= 1290);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int volume_cube(int side)
{
    //@ assert (0 <= (side) <= 1290);
    
    //@ assert side * side <= 1290 * 1290;
    //@ assert side * side * side <= 1290 * 1290 * 1290;
    
    return side * side * side;
}

int main()
{
    return 0;
}
