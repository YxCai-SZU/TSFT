/*@
    predicate valid_params(integer n, integer x) =
        1 <= n && n <= 100 &&
        1 <= x && x <= 10000;

    predicate valid_array(integer n, int* numbers) =
        \forall integer i; 0 <= i < n ==> 1 <= numbers[i] && numbers[i] <= 100;

    lemma sum_bound_property:
        \forall integer sum, integer x, integer index;
        sum <= x + 100 * index ==> sum <= x + 100 * (index + 1);
*/

/*@
    requires valid_params(n, x);
    requires \valid_read(numbers + (0 .. n-1));
    requires valid_array(n, numbers);
    ensures \result >= 0;
*/
int func(int n, int x, int* numbers)
{
    int sum = 0;
    int cnt = 0;
    int index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= cnt <= index;
        loop invariant sum <= x + 100 * index;
        loop invariant \forall integer i; 0 <= i < index ==> 1 <= numbers[i] && numbers[i] <= 100;
        loop invariant valid_params(n, x);
        loop assigns sum, cnt, index;
        loop variant n - index;
    */
    while (index < n && sum <= x)
    {
        //@ assert sum <= x + 100 * index;
        sum += numbers[index];
        cnt += 1;
        index += 1;
        //@ assert sum <= x + 100 * index;
    }

    return cnt;
}
