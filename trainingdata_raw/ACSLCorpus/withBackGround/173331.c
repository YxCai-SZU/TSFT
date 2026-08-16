#include <stdbool.h>

/*@
    predicate min_cond(integer x, integer y, integer result) =
        result == ((x < y) ? x : y);

    predicate max_cond(integer x, integer y, integer result) =
        result == ((x > y) ? x : y);
*/

/*@
    requires \true;
    ensures min_cond(x, y, \result);
    assigns \nothing;
*/
int min(int x, int y)
{
    int min_value;
    if (x < y) {
        min_value = x;
    } else {
        min_value = y;
    }
    //@ assert min_cond(x, y, min_value);
    return min_value;
}

/*@
    requires \true;
    ensures max_cond(x, y, \result);
    assigns \nothing;
*/
int max(int x, int y)
{
    int max_value;
    if (x > y) {
        max_value = x;
    } else {
        max_value = y;
    }
    //@ assert max_cond(x, y, max_value);
    return max_value;
}

/*@
    assigns \nothing;
*/
void print_difference(int i)
{
    // External function - minimal ACSL specification
}

/*@
    requires \true;
    ensures \true;
    assigns \nothing;
*/
int main()
{
    int n1;
    int n2;
    int diff;

    n1 = min(100, 200);
    n2 = max(100, 200);
    
    //@ assert n1 == 100;
    //@ assert n2 == 200;
    //@ assert n2 - n1 == 100;
    
    diff = n2 - n1;
    print_difference(diff);
    
    return 0;
}
