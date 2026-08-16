/*@
    predicate side_in_range(integer s) = 0 <= s <= 0xffff;
    
    logic integer square_area_logic(integer side) = side * side;
    
    lemma square_area_bounded: 
        \forall integer s; side_in_range(s) ==> square_area_logic(s) <= 0xffff * 0xffff;
*/

/*@
    requires side_in_range(side);
    ensures \result == square_area_logic(side);
    assigns \nothing;
*/
unsigned int square_area(unsigned int side)
{
    // Variable declarations at top of scope
    unsigned int result;
    
    //@ assert side_in_range(side);
    
    //@ assert square_area_logic(side) == side * side;
    
    result = side * side;
    
    //@ assert result == square_area_logic(side);
    
    return result;
}

int main()
{
    // Variable declarations at top of scope
    int __ret = 0;
    
    return __ret;
}
