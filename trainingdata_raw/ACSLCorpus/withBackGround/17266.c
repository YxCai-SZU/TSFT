#include <stdbool.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r && r <= 100;
    logic integer square(integer r) = r * r;
    lemma square_in_range: \forall integer r; is_valid_range(r) ==> 1 <= square(r) && square(r) <= 10000;
*/

/*@
    requires is_valid_range(r);
    ensures \result == square(r);
    assigns \nothing;
*/
int func(int r)
{
    //@ assert is_valid_range(r);
    //@ assert 1 <= square(r) && square(r) <= 10000;
    return r * r;
}

/*@
    requires is_valid_range(r);
    ensures \result == square(r);
    assigns \nothing;
*/
int main_func(int r)
{
    //@ assert is_valid_range(r);
    //@ assert 1 <= square(r) && square(r) <= 10000;
    int result = func(r);
    return result;
}

int main()
{
    return 0;
}
