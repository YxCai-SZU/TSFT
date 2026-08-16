/*@
predicate le_100(integer a) = a <= 100;

lemma multiply_by_zero: \forall integer x; x * 0 == 0;

lemma add_and_multiply: \forall integer a, b; le_100(a) && le_100(b) ==> (a + b) * 2 <= 400;
*/

/*@
requires le_100(a) && le_100(b);
ensures \result == (a + b) * 2;
assigns \nothing;
*/
int add_and_multiply_func(int a, int b)
{
    //@ assert a + b <= 200;
    //@ assert (a + b) * 2 <= 400;
    return (a + b) * 2;
}

int main()
{
    return 0;
}
