#include <stdbool.h>

/*@
    requires (\valid((input)) &&
        (input)[0] >= 1 && (input)[0] <= 100 &&
        (input)[1] >= 1 && (input)[1] <= 100 &&
        (input)[2] >= 1 && (input)[2] <= 100);
    ensures \result >= 0 && \result <= 3;
    ensures \result == (((input)[0] == (input)[1] && (input)[0] == (input)[2]) ? 1 :
        ((input)[0] == (input)[1] || (input)[1] == (input)[2] || (input)[0] == (input)[2]) ? 2 : 3);
    assigns \nothing;
*/
int func(int *input)
{
    int answer = 0;
    
    //@ assert (\valid((input)) &&         (input)[0] >= 1 && (input)[0] <= 100 &&         (input)[1] >= 1 && (input)[1] <= 100 &&         (input)[2] >= 1 && (input)[2] <= 100);
    
    if (input[0] == input[1] && input[0] == input[2]) {
        answer += 1;
        //@ assert answer == 1;
    } else if (input[0] == input[1] || input[1] == input[2] || input[0] == input[2]) {
        answer += 2;
        //@ assert answer == 2;
    } else {
        answer += 3;
        //@ assert answer == 3;
    }
    
    //@ assert answer >= 0 && answer <= 3;
    return answer;
}
