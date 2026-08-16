#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

/*@
    requires (2 <= (n) && (n) <= 200000);
    requires (\forall integer i; 0 <= i < (n) - 1 ==> 
            (numbers)[i] >= 1 && (numbers)[i] < i + 1);
    requires \valid(numbers + (0 .. n-2));
    ensures \valid(\result + (0 .. n-1));
    ensures ((n) == (n));
    ensures (\forall integer i; 0 <= i < (n) ==> (\result)[i] >= 0);
    assigns \nothing;
*/
int* func(size_t n, const int* numbers) {
    int* ans = (int*)malloc(n * sizeof(int));
    if (!ans) return NULL;
    
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==> ans[j] == 0;
        loop assigns i, ans[0 .. n-1];
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        ans[i] = 0;
        i++;
    }
    
    i = 0;
    
    /*@
        loop invariant 0 <= i <= n - 1;
        loop invariant \forall integer j; 0 <= j < n ==> ans[j] >= 0;
        loop invariant \forall integer j; 0 <= j < n ==> ans[j] <= (int)i;
        loop assigns i, ans[0 .. n-1];
        loop variant n - 1 - i;
    */
    while (i < n - 1) {
        //@ assert i < n - 1;
        int ai = numbers[i];
        //@ assert ai >= 1 && ai < i + 1;
        size_t index = (size_t)(ai - 1);
        //@ assert index < n;
        int current_value = ans[index];
        ans[index] = current_value + 1;
        i++;
    }
    
    //@ assert (\forall integer i; 0 <= i < (n) ==> (ans)[i] >= 0);
    return ans;
}
