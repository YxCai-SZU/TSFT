#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (N) && (N) <= 20);
    requires \valid(H + (0 .. N-1));
    requires (\forall integer i; 0 <= i < (N) ==> 1 <= (H)[i] && (H)[i] <= 100);
    assigns \nothing;
    ensures 0 <= \result <= N;
*/
int func(int N, int *H) {
    int answer = 0;
    int tmp = 0;
    int flag = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= (size_t)N;
        loop invariant 0 <= flag <= (int)index;
        loop invariant 0 <= answer <= (int)index;
        loop invariant (1 <= (N) && (N) <= 20);
        loop invariant (\forall integer i; 0 <= i < (N) ==> 1 <= (H)[i] && (H)[i] <= 100);
        loop assigns answer, tmp, flag, index;
        loop variant N - index;
    */
    while (index < (size_t)N && index + 1 < (size_t)N) {
        //@ assert 0 <= index < (size_t)N;
        if (H[index] >= tmp) {
            flag += 1;
            //@ assert flag >= 1;
            answer = (answer > flag) ? answer : flag;
            //@ assert answer >= flag;
        } else {
            flag = 0;
        }
        tmp = H[index];
        index += 1;
        //@ assert answer <= (int)index;
    }
    //@ assert 0 <= answer <= N;
    return answer;
}
