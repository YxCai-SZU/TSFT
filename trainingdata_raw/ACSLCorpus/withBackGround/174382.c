/*@
    predicate valid_input(integer a, integer b, integer c, integer d, integer e) =
        1 <= a <= 123 &&
        1 <= b <= 123 &&
        1 <= c <= 123 &&
        1 <= d <= 123 &&
        1 <= e <= 123;

    logic integer total_sum(integer a, integer b, integer c, integer d, integer e) =
        a + b + c + d + e + 5;

    lemma division_property:
        \forall integer a,b,c,d,e,sum,count;
        valid_input(a,b,c,d,e) &&
        sum == total_sum(a,b,c,d,e) - 5 * count &&
        sum >= 0 ==>
        count <= total_sum(a,b,c,d,e) / 5;
*/

/*@
    requires valid_input(a,b,c,d,e);
    ensures \result == (a + b + c + d + e + 5) / 5;
*/
int func(int a, int b, int c, int d, int e)
{
    int sum;
    int result;
    int count;

    sum = a + b + c + d + e + 5;
    result = 0;
    count = 0;

    /*@
        loop invariant 1 <= a <= 123;
        loop invariant 1 <= b <= 123;
        loop invariant 1 <= c <= 123;
        loop invariant 1 <= d <= 123;
        loop invariant 1 <= e <= 123;
        loop invariant sum >= 0;
        loop invariant sum == a + b + c + d + e + 5 - 5 * count;
        loop invariant result == count;
        loop invariant count > 0 ==> count <= (a + b + c + d + e + 5) / 5;
        loop assigns sum, result, count;
    */
    while (sum >= 5)
    {
        //@ assert sum >= 5;
        sum -= 5;
        result += 1;
        count += 1;
    }

    //@ assert result == (a + b + c + d + e + 5) / 5;
    return result;
}
