#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

/*@
    requires ((n) >= 2 && (n) <= 200000 &&
        \valid((input) + (0 .. (n)-2)) &&
        \forall integer j; 0 <= j < (n)-1 ==> (input)[j] > 0 && (input)[j] < j + 1);
    ensures \valid(\result + (0 .. n-1));
    ensures \forall integer i; 0 <= i < n ==> \result[i] >= 0;
    assigns \nothing;
*/
int* func(size_t n, int* input) {
    int* ans = (int*)malloc(n * sizeof(int));
    if (!ans) return NULL;
    
    size_t i = 0;
    
    // Initialize vector with zeros
    /*@
        loop invariant (0 <= (i) && (i) <= (n) &&
        \valid((ans) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (i) ==> (ans)[j] == 0);
        loop invariant ((n) >= 2 && (n) <= 200000 &&
        \valid((input) + (0 .. (n)-2)) &&
        \forall integer j; 0 <= j < (n)-1 ==> (input)[j] > 0 && (input)[j] < j + 1);
        loop assigns i, ans[0 .. n-1];
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i && i < n;
        ans[i] = 0;
        i++;
    }
    
    i = 0;
    /*@
        loop invariant (0 <= (i) && (i) <= (n)-1 &&
        \valid((ans) + (0 .. (n)-1)) &&
        \valid((input) + (0 .. (n)-2)) &&
        \forall integer j; 0 <= j < (n)-1 ==> (ans)[j] >= 0 &&
        \forall integer j; 0 <= j < (i) ==> (ans)[(input)[j] - 1] > 0 &&
        \forall integer j; 0 <= j < (n) ==> (ans)[j] >= 0 &&
        \forall integer j; 0 <= j < (n) ==> (ans)[j] <= (int)(i));
        loop assigns i, ans[0 .. n-1];
        loop variant n-1 - i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i && i < n-1;
        int index = input[i] - 1;
        //@ assert 0 <= index && index < n;
        int current_value = ans[index];
        //@ assert current_value >= 0;
        ans[index] = current_value + 1;
        i++;
    }
    
    //@ assert \forall integer j; 0 <= j < n ==> ans[j] >= 0;
    return ans;
}
