/*@
predicate is_in_range(integer a) = 1 <= a && a <= 100;

lemma range_lemma:
    \forall integer a; is_in_range(a) ==> a >= 1 && a <= 100;
*/

/*@
requires 1 <= a && a <= 100;
ensures \result == a;
assigns \nothing;
*/
int func(int a)
{
    //@ assert 1 <= a;
    //@ assert a <= 100;
    return a;
}

int main()
{
    int a;
    
    a = 50;
    //@ assert is_in_range(a);
    int result = func(a);
    
    return 0;
}
