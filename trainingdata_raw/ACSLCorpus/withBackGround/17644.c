#include <stdbool.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r && r <= 100;
    logic integer square(integer r) = r * r;
    lemma square_bound: \forall integer r; is_valid_range(r) ==> square(r) <= 10000;
*/

/*@
    requires is_valid_range(r);
    ensures \result == square(r);
    assigns \nothing;
*/
unsigned int func(unsigned int r)
{
    unsigned int res;
    
    //@ assert is_valid_range(r);
    //@ assert square(r) <= 10000;
    
    res = r * r;
    
    //@ assert res == square(r);
    return res;
}

/*@
    assigns \nothing;
    ensures \result == \null;
*/
int* input_number(void)
{
    int* vec;
    vec = 0;
    return vec;
}

/*@
    assigns \nothing;
    ensures \result.c == ' ' && \result.n == 0;
*/
struct pair
{
    char c;
    unsigned int n;
} input(void)
{
    struct pair p;
    p.c = ' ';
    p.n = 0;
    return p;
}
