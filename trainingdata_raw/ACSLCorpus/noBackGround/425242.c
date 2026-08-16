#include <stdbool.h>

/*@ requires (1 <= (n) && (n) <= 100);
    requires (1 <= (m) && (m) <= 100);
    requires (1 <= (x) && (x) <= (n));
    requires \valid(an + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> ((an[i]) >= 1 && (an[i]) <= (n) && (an[i]) != (x));
    requires \valid(am + (0 .. m-1));
    requires \forall integer j; 0 <= j < m ==> ((am[j]) >= 1 && (am[j]) <= (n) && (am[j]) != (x));
    ensures \result >= 0;
    ensures \result <= m;
*/
int func(int n, int m, int x, int *an, int *am) {
    int ans = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= m;
        loop invariant 0 <= ans <= i;
        loop invariant \forall integer k; 0 <= k < i ==> 
            (x > am[k] && am[k] > 0) || (0 < x - am[k] && am[k] > 0) ==> ans >= 1;
        loop invariant ans <= m;
        loop assigns i, ans;
        loop variant m - i;
    */
    while (i < m) {
        int friend = am[i];
        int x_is_strictly_greater_than_friend = x > friend;
        int friend_is_strictly_greater_than_zero = friend > 0;
        int zero_is_strictly_less_than_x_minus_friend = 0 < x - friend;
        int condition1 = x_is_strictly_greater_than_friend && friend_is_strictly_greater_than_zero;
        int condition2 = zero_is_strictly_less_than_x_minus_friend && friend_is_strictly_greater_than_zero;
        int condition = condition1 || condition2;
        
        //@ assert condition == ((x > friend && friend > 0) || (0 < x - friend && friend > 0));
        
        if (condition) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
