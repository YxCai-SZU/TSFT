/*@
    requires (0 <= (side_length) <= 1000);
    ensures \result == ((side_length) * (side_length));
    assigns \nothing;
*/
unsigned int square_area(unsigned int side_length)
{
    unsigned int res;
    
    //@ assert side_length * side_length <= 1000 * 1000;
    
    res = side_length * side_length;
    
    return res;
}

int main()
{
    return 0;
}
