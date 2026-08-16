/*@
    predicate commutative_and(integer x, integer y) =
        (x & y) == (y & x);
*/

/*@
    requires 0 <= x <= 0xffff;
    requires 0 <= y <= 0xffff;
    ensures \result == 1;
    assigns \nothing;
*/
_Bool func(unsigned int x, unsigned int y)
{
    unsigned int tmp1;
    unsigned int tmp2;
    
    tmp1 = x & y;
    tmp2 = y & x;
    
    //@ assert tmp1 == tmp2;
    
    return tmp1 == tmp2;
}

int main()
{
    return 0;
}
