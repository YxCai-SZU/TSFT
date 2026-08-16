#include <limits.h>

/*@
predicate f(integer i) = \true;

lemma lemma_even_f:
    \forall integer i; 0 <= i ==> f(i);

lemma test_even_f:
    \forall integer i; 0 <= i ==> f(i);
*/

/*@
requires 0 <= i;
ensures f(i);
assigns \nothing;
*/
void lemma_even_f(int i)
{
    //@ assert f(i);
}

/*@
ensures \forall integer i; 0 <= i ==> f(i);
assigns \nothing;
*/
void test_even_f()
{
    int i = 0;
    
    /*@
    loop invariant 0 <= i;
    loop invariant \forall integer j; 0 <= j < i ==> f(j);
    loop assigns i;
    */
    for (; ; i++)
    {
        lemma_even_f(i);
        //@ assert f(i);
    }
}

/*@
assigns \nothing;
*/
int main()
{
    return 0;
}
