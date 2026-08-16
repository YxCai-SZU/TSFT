#include <stdbool.h>
/*@
    predicate all_satisfy(integer n, int *numbers) =
        \forall integer i; 0 <= i < n ==>
            (numbers[i] % 2 != 0) || (numbers[i] % 3 == 0) || (numbers[i] % 5 == 0);
    
    predicate exists_violation(integer i, int *numbers) =
        \exists integer j; 0 <= j < i &&
            (numbers[j] % 2 == 0) && (numbers[j] % 3 != 0) && (numbers[j] % 5 != 0);
*/

/*@
    requires n > 0 && n <= 100;
    requires \valid(numbers + (0..n-1));
    requires \forall integer i; 0 <= i < n ==> numbers[i] > 0 && numbers[i] <= 1000;
    ensures \result == true <==> all_satisfy(n, numbers);
    assigns \nothing;
*/
bool func(int n, int *numbers)
{
    bool flag = true;
    int i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant flag == true ==> \forall integer j; 0 <= j < i ==>
            (numbers[j] % 2 != 0) || (numbers[j] % 3 == 0) || (numbers[j] % 5 == 0);
        loop invariant flag == false ==> exists_violation(i, numbers);
        loop assigns flag, i;
        loop variant n - i;
    */
    while (i < n)
    {
        int a = numbers[i];
        if (a % 2 == 0 && a % 3 != 0 && a % 5 != 0)
        {
            flag = false;
        }
        i++;
    }
    //@ assert flag == true <==> all_satisfy(n, numbers);
    return flag;
}
