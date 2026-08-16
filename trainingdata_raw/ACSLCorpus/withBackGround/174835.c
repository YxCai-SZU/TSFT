/*@
    logic integer cubic(integer a, integer b, integer c, integer d, integer x) =
        a*x*x*x + b*x*x + c*x + d;

    lemma cubic_example: cubic(1, -2, 1, 1, 1) == 1;

    logic integer max(integer x, integer y) =
        x > y ? x : y;

    lemma max_example: max(1, 2) == 2;

    logic integer min(integer x, integer y) =
        x < y ? x : y;

    lemma min_example: min(1, 2) == 1;

    logic integer abs(integer x) =
        x < 0 ? -x : x;

    lemma abs_example: abs(-1) == 1;
*/

int main()
{
    //@ assert cubic(1, -2, 1, 1, 1) == 1;
    //@ assert max(1, 2) == 2;
    //@ assert min(1, 2) == 1;
    //@ assert abs(-1) == 1;
    
    return 0;
}
