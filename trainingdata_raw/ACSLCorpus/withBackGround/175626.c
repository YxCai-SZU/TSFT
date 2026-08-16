#include <stdbool.h>
/*@
    predicate sorted{L}(unsigned int *a, integer n) =
        \forall integer i, j; 0 <= i < j < n ==> a[i] <= a[j];

    predicate strictly_increasing{L}(unsigned int *a, integer n) =
        \forall integer i, j; 0 <= i < j < n ==> a[i] < a[j];

    lemma increasing_lemma:
        \forall unsigned int *v, integer i, integer j, integer n;
            0 <= i < j < n && v[i] < v[j] ==> i < j;

    lemma sorted_lemma:
        \forall unsigned int *v, integer i, integer j, integer n;
            0 <= i < j < n && v[i] <= v[j] ==> i < j;

    lemma strictly_increasing_lemma:
        \forall unsigned int *v, integer i, integer j, integer n;
            0 <= i < j < n && v[i] < v[j] ==> i < j;

    lemma is_sorted_lemma:
        \forall unsigned int *v, integer n;
            (\forall integer i, j; 0 <= i < j < n ==> v[i] <= v[j]) ==>
                sorted(v, n);

    lemma is_strictly_increasing_lemma:
        \forall unsigned int *v, integer n;
            (\forall integer i, j; 0 <= i < j < n ==> v[i] < v[j]) ==>
                strictly_increasing(v, n);
*/

int main() {
    unsigned int v[4];
    unsigned int i;
    
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    
    //@ assert sorted(&v[0], 4);
    //@ assert strictly_increasing(&v[0], 4);
    
    return 0;
}
