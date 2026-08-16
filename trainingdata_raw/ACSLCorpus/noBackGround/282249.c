/*@
    requires (0 <= (side) <= 1290);
    ensures \result >= 0;
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int volume_cube(int side)
{
    // Variable declarations at scope top
    int result;
    
    //@ assert 0 <= side;
    //@ assert side <= 1290;
    //@ assert side * side <= 1290 * 1290;
    //@ assert side * side * side <= 1290 * 1290 * 1290;
    
    result = side * side * side;
    
    //@ assert result >= 0;
    //@ assert result == ((side) * (side) * (side));
    
    return result;
}

int main()
{
    return 0;
}
