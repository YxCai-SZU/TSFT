/*@
    predicate is_valid_range(integer a) = 0 <= a <= 50;
    
    logic integer double_val(integer a) = 2 * a;
*/

/*@
    requires is_valid_range(a);
    ensures \result == double_val(a);
    assigns \nothing;
*/
unsigned char func(unsigned char a)
{
    //@ assert 0 <= a < 51;
    return 2 * a;
}

int main()
{
    return 0;
}
