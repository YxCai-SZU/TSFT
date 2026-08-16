/*@
predicate valid_range(integer a) = 0 <= a && a <= 10;

lemma func_lemma:
    \forall integer a; valid_range(a) ==> a + 1 <= 11;
*/

/*@
    requires valid_range(a);
    ensures \result == a + 1;
    ensures \result <= 11;
*/
int func(int a)
{
    //@ assert valid_range(a);
    
    int result = a + 1;
    
    //@ assert 0 <= a + 1;
    //@ assert a + 1 <= 11;
    //@ assert result <= 11;
    
    return result;
}

int main()
{
    return 0;
}
