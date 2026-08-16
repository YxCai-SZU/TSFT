/*@
predicate subtraction_condition(integer a, integer b) = a == b + 1;
predicate addition_condition(integer a, integer b) = a + b == 3;

lemma subtraction_lemma: \forall integer a, b; subtraction_condition(a, b) ==> a - 1 == b;
lemma addition_lemma: \forall integer a, b; addition_condition(a, b) ==> a == 3 - b;
lemma calc_example_5_lemma: \forall integer a, b; subtraction_condition(a, b) && addition_condition(a, b) ==> b == 1;
*/

/*@
requires subtraction_condition(a, b) && addition_condition(a, b);
ensures \result == 1;
*/
int calc_example_5(int a, int b)
{
    int result;
    
    //@ assert subtraction_condition(a, b);
    //@ assert a - 1 == b;
    
    //@ assert addition_condition(a, b);
    //@ assert a == 3 - b;
    
    //@ assert b == 1;
    result = b;
    
    return result;
}

int main()
{
    return 0;
}
