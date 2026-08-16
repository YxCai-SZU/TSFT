/*@
    predicate side_in_range(integer s) = 0 <= s && s <= 100;
    
    logic integer cube_volume(integer s) = s * s * s;
    
    lemma no_overflow1: \forall integer s; side_in_range(s) ==> s * s <= 100 * 100;
    lemma no_overflow2: \forall integer s; side_in_range(s) ==> s * s * s <= 100 * 100 * 100;
*/

/*@
    requires side_in_range(side);
    ensures \result == cube_volume(side);
    assigns \nothing;
*/
unsigned int volume_cube(unsigned int side)
{
    // Variable declarations at top
    unsigned int volume;
    
    //@ assert side_in_range(side);
    
    //@ assert side * side <= 100 * 100;
    
    //@ assert side * side * side <= 100 * 100 * 100;
    
    volume = side * side * side;
    
    //@ assert volume == cube_volume(side);
    
    return volume;
}

int main()
{
    return 0;
}
