/*@
    requires n > 0;
    requires \valid(numbers + (0 .. n-1));
    requires ((n) > 0 &&
        \forall integer i; 0 <= i < (n) ==> (numbers)[i] > 0 && (numbers)[i] <= 1000);
    ensures \result == 1 <==> 
            \forall integer i; 0 <= i < n ==> 
                numbers[i] % 2 != 0 || numbers[i] % 3 == 0 || numbers[i] % 5 == 0;
    assigns \nothing;
*/
int func(int n, int *numbers)
{
    int i = 0;
    int num;
    int ans = 1;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ((n) > 0 &&
        \forall integer i; 0 <= i < (n) ==> (numbers)[i] > 0 && (numbers)[i] <= 1000);
        loop invariant ans == 1 <==> (\forall integer j; 0 <= j < (i) ==> 
            (numbers)[j] % 2 != 0 || (numbers)[j] % 3 == 0 || (numbers)[j] % 5 == 0);
        loop invariant i > 0 ==> (ans == 1 <==> (\forall integer j; 0 <= j < (i) ==> 
            (numbers)[j] % 2 != 0 || (numbers)[j] % 3 == 0 || (numbers)[j] % 5 == 0));
        loop assigns i, num, ans;
        loop variant n - i;
    */
    while (i < n)
    {
        num = numbers[i];

        if (num % 2 != 0)
        {
            i += 1;
            continue;
        }

        if (!(num % 3 == 0 || num % 5 == 0))
        {
            ans = 0;
            break;
        }
        i += 1;
    }

    //@ assert ans == 1 <==> (\forall integer j; 0 <= j < (n) ==>              (numbers)[j] % 2 != 0 || (numbers)[j] % 3 == 0 || (numbers)[j] % 5 == 0);

    return ans;
}

int main()
{
    return 0;
}
