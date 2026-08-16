/*@
    predicate valid_a(integer a) = 1 <= a && a <= 100000;
    
    logic integer division_by_3(integer a) = a / 3;
    
    lemma division_property:
        \forall integer a; valid_a(a) ==> division_by_3(a) >= 0;
*/


int func(int a)
{
    int result;
    int temp_a;
    int count;
    
    result = 0;
    temp_a = a;
    count = 0;
    
    
    while (temp_a >= 3)
    {
        //@ assert temp_a >= 3;
        temp_a = temp_a - 3;
        count = count + 1;
        //@ assert temp_a == a - 3 * count;
    }
    
    result = count;
    //@ assert result == division_by_3(a);
    return result;
}
