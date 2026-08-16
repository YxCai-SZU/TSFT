/*@
    predicate is_valid_range(integer a) = 1 <= a && a <= 9;
    
    logic integer cube(integer a) = a * a * a;
    
    lemma custom_relation: 1 * 2 == 2;
    lemma custom_relation_2: 2 * 3 == 6;
*/

/*@
    requires is_valid_range(a);
    ensures \result == cube(a);
    assigns \nothing;
*/
int func(int a)
{
    //@ assert 1 <= a && a <= 9;
    
    int result;
    result = a * a * a;
    
    //@ assert result == cube(a);
    return result;
}

int main()
{
    return 0;
}
