#include <limits.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 32;

    predicate result_one(integer i) =
        i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 ||
        i == 7 || i == 8 || i == 9 || i == 10 || i == 11 || i == 12;

    predicate result_two(integer i) =
        i == 13 || i == 14 || i == 15 || i == 16 || i == 17 || i == 18 || i == 19;

    predicate result_three(integer i) =
        i == 20 || i == 21 || i == 22 || i == 23 || i == 24 || i == 25 || i == 26;

    predicate result_four(integer i) =
        i == 27 || i == 28 || i == 29 || i == 30 || i == 31 || i == 32;

    lemma branch_one: \forall integer i; in_range(i) && i <= 12 ==> result_one(i);
    lemma branch_two: \forall integer i; in_range(i) && 13 <= i <= 19 ==> result_two(i);
    lemma branch_three: \forall integer i; in_range(i) && 20 <= i <= 26 ==> result_three(i);
    lemma branch_four: \forall integer i; in_range(i) && 27 <= i <= 32 ==> result_four(i);
*/


int func(int input)
{
    int result;

    //@ assert in_range(input);

    if (input <= 12)
    {
        //@ assert result_one(input);
        result = 1;
    }
    else if (input <= 19)
    {
        //@ assert result_two(input);
        result = 2;
    }
    else if (input <= 26)
    {
        //@ assert result_three(input);
        result = 3;
    }
    else
    {
        //@ assert result_four(input);
        result = 4;
    }

    //@ assert 1 <= result <= 9;
    return result;
}
