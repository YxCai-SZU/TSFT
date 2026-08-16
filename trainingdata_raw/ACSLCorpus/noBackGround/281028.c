/*@
    requires side_length < 1000;
    ensures \result == side_length * side_length * side_length;
    ensures \result < 1000000000;
    assigns \nothing;
*/
unsigned int volume_cube(unsigned int side_length)
{
    // Variable declarations at top of scope
    unsigned int intermediate;
    unsigned int result;
    
    //@ assert side_length < 1000;
    
    intermediate = side_length * side_length;
    //@ assert intermediate < 1000000;
    
    result = intermediate * side_length;
    //@ assert result < 1000000000;
    
    return result;
}

int main()
{
    // Variable declarations at top of scope
    unsigned int side_length;
    unsigned int volume;
    
    side_length = 10;
    volume = volume_cube(side_length);
    
    return 0;
}
