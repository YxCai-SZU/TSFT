/*@
    predicate le(integer a, integer b) = a <= b;

    lemma transitivity:
        \forall integer a, b, c;
            le(a, b) && le(b, c) ==> le(a, c);

    lemma additivity:
        \forall integer a, b;
            (1 <= a && a <= 100 && 1 <= b && b <= 100) ==>
            (1 <= a + b && a + b <= 200);
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    ensures 1 <= \result && \result <= 200;
*/
int add_bounded(int a, int b)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    
    int sum = a + b;
    
    //@ assert 1 <= sum;
    //@ assert sum <= 200;
    
    return sum;
}

int main()
{
    int x = 50;
    int y = 60;
    
    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    
    int result = add_bounded(x, y);
    
    //@ assert 1 <= result && result <= 200;
    
    return 0;
}
