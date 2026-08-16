/*@
predicate ordered(integer a, integer b, integer c) = a <= b && b <= c;

lemma calc_example_15:
    \forall integer a, b, c;
    ordered(a, b, c) ==> a <= c;
*/

/*@
    requires ordered(a, b, c);
    ensures \result == 0;
    assigns \nothing;
*/
int example(int a, int b, int c)
{
    //@ assert ordered(a, b, c);
    //@ assert a <= c;
    return 0;
}

/*@
    assigns \nothing;
*/
int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int result;
    
    //@ assert ordered(a, b, c);
    result = example(a, b, c);
    return 0;
}
