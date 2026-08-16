#include <limits.h>

/*@
    predicate in_range(integer v, integer low, integer high) =
        low <= v && v <= high;
*/

/*@
    logic integer square_val(integer x) = x * x;
*/

/*@
    logic integer cube_val(integer x) = x * x * x;
*/

/*@
    lemma square_bounds:
        \forall integer x;
            in_range(x, -46340, 46340) ==>
            in_range(square_val(x), -46340*46340, 46340*46340);
*/

/*@
    lemma cube_bounds:
        \forall integer x;
            in_range(x, -1290, 1290) ==>
            in_range(cube_val(x), -1290*1290*1290, 1290*1290*1290);
*/

/*@
    requires in_range(x, -46340, 46340);
    ensures \result == square_val(x);
    assigns \nothing;
*/
int square(int x)
{
    //@ assert in_range(x, -46340, 46340);
    //@ assert in_range(square_val(x), -46340*46340, 46340*46340);
    return x * x;
}

/*@
    requires in_range(x, -1290, 1290);
    ensures \result == cube_val(x);
    assigns \nothing;
*/
int cubed(int x)
{
    //@ assert in_range(x, -1290, 1290);
    //@ assert in_range(square_val(x), -1290*1290, 1290*1290);
    //@ assert in_range(cube_val(x), -1290*1290*1290, 1290*1290*1290);
    return x * x * x;
}

/*@
    requires in_range(a, -1000, 1000);
    ensures \result == cube_val(a);
    assigns \nothing;
*/
int func(int a)
{
    return cubed(a);
}

int main(void)
{
    return 0;
}
