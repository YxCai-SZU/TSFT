#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(input + (0 .. 4));
    requires (\forall integer j; 0 <= j < 5 ==> ((input)[j] == j + 1 || (input)[j] == 0) &&
        \exists integer j; 0 <= j < 5 && (input)[j] == 0);
    ensures 1 <= \result <= 5;
    ensures input[\result - 1] == 0;
    assigns \nothing;
*/
int func(int* input) {
    int v[5];
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> v[j] == input[j];
        loop invariant (\forall integer j; 0 <= j < 5 ==> ((input)[j] == j + 1 || (input)[j] == 0) &&
        \exists integer j; 0 <= j < 5 && (input)[j] == 0);
        loop assigns i, v[0 .. 4];
        loop variant 5 - i;
    */
    while (i < 5) {
        v[i] = input[i];
        i++;
    }

    int index = 0;
    
    /*@
        loop invariant 0 <= index <= 5;
        loop invariant \forall integer j; 0 <= j < 5 ==> v[j] == input[j];
        loop invariant \forall integer j; 0 <= j < index ==> v[j] != 0;
        loop invariant (\forall integer j; 0 <= j < 5 ==> ((input)[j] == j + 1 || (input)[j] == 0) &&
        \exists integer j; 0 <= j < 5 && (input)[j] == 0);
        loop assigns index;
        loop variant 5 - index;
    */
    while (index < 5) {
        if (v[index] == 0) {
            break;
        }
        index++;
    }

    //@ assert index < 5;
    //@ assert v[index] == 0;
    //@ assert input[index] == 0;
    
    return index + 1;
}
