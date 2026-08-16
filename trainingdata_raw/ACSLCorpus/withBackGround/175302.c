#include <stdbool.h>

/*@ predicate is_even(integer x) = x % 2 == 0; */
/*@ predicate f(integer i) = i % 2 == 0; */

/*@ lemma lemma_even_f: \forall integer i; is_even(i) ==> f(i); */

/*@ requires \exists integer x; f(x);
    requires n % 2 == 0;
    ensures f(\result);
    assigns \nothing;
 */
int use_exists(int n)
{
    int y;
    int x;

    //@ ghost int tmp_x;
    //@ ghost //@ assert \exists integer x; f(x);
    //@ ghost tmp_x = 0;

    x = 0;
    //@ assert f(x);

    //@ assert n / 2 + n / 2 == n;

    //@ assert is_even(x);
    //@ assert f(x);

    //@ assert is_even(x);
    //@ assert f(x);

    y = x + x;
    //@ assert f(y);
    return y;
}

int main()
{
    return 0;
}
