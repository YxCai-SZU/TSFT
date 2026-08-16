#include <stdbool.h>
#include <stdlib.h>

/*@ requires (1 <= (n) && (n) <= 10);
    ensures \result == n*n;
    assigns \nothing;
 */
int func(int n)
{
    //@ assert 1 <= n && n <= 10;
    return n * n;
}

/*@ requires \valid(vec+(0..4));
    ensures ((5) == 5);
    ensures vec[0] == 1 && vec[1] == 2 && vec[2] == 3 && vec[3] == 4 && vec[4] == 5;
    assigns vec[0..4];
 */
void vec_example(int *vec)
{
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    vec[3] = 4;
    vec[4] = 5;
}

/*@ requires \valid(vec+(0..4));
    ensures ((5) == 5 && 
      (vec)[0] == 1 && (vec)[1] == 2 && (vec)[2] == 3 && (vec)[3] == 4 && (vec)[4] == 5);
    assigns vec[0..4];
 */
void map_example(int *vec)
{
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    vec[3] = 4;
    vec[4] = 5;
}

/*@ requires (1 <= (n) && (n) <= 10) && \valid(vec+(0..n-1));
    ensures \forall integer i; 0 <= i < n ==> vec[i] == i+1;
    assigns vec[0..n-1];
 */
void func_vec(int n, int *vec)
{
    int i = 1;
    
    /*@ loop invariant ((1 <= ((n)) && ((n)) <= 10) && 
      1 <= (i) && (i) <= (n)+1 && 
      (\forall integer k; 0 <= k < (i)-1 ==> (vec)[k] == k+1));
        loop assigns i, vec[0..n-1];
        loop variant n-i+1;
     */
    while (i <= n)
    {
        //@ assert 0 <= i-1 && i-1 < n;
        vec[i-1] = i;
        i = i + 1;
    }
}
