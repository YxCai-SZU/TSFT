#include <stdbool.h>

/*@
    requires n >= 2 && n <= 50;
    requires \valid(aa + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> aa[i] >= 1 && aa[i] <= 100;
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> 
           ((aa)[i] % 2 == 0 ==> (aa)[i] % 3 == 0 || (aa)[i] % 5 == 0));
*/
bool func(int n, int *aa) {
    bool flag = true;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant flag == true <==> 
            \forall integer j; 0 <= j < i ==> 
                (aa[j] % 2 == 0 ==> aa[j] % 3 == 0 || aa[j] % 5 == 0);
        loop assigns i, flag;
        loop variant n - i;
    */
    while (i < n) {
        int a = aa[i];
        if (a % 2 == 0) {
            if (a % 3 != 0 && a % 5 != 0) {
                flag = false;
            }
        }
        i++;
    }
    return flag;
}
