/*@
    predicate is_in_range(integer a) = -1000 <= a && a <= 1000;
    
    logic integer func_spec(integer a) = a * a * a + a * a + a;
    
    lemma a_square_range:
        \forall integer a; is_in_range(a) ==> -1000000 <= a * a && a * a <= 1000000;
    
    lemma a_cube_range:
        \forall integer a; is_in_range(a) ==> -1000000000 <= a * a * a && a * a * a <= 1000000000;
*/

/*@
    requires is_in_range(a);
    ensures \result == func_spec(a);
    assigns \nothing;
*/
int func(int a)
{
    //@ assert -1000 <= a && a <= 1000;
    
    //@ assert -1000000 <= a * a && a * a <= 1000000;
    
    //@ assert -1000000000 <= a * a * a && a * a * a <= 1000000000;
    
    return a * a * a + a * a + a;
}

int main()
{
    return 0;
}
