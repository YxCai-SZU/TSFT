#include <stdbool.h>

/*@
    requires \valid_read(arr + (0..2));
    requires ((3) == 3 &&
    1 <= (arr)[0] && (arr)[0] <= 20 &&
    1 <= (arr)[1] && (arr)[1] <= 20 &&
    1 <= (arr)[2] && (arr)[2] <= 20);
    assigns \nothing;
    ensures 0 <= \result <= 40;
*/
int func(int *arr) {
    int answer;
    int sub;
    
    answer = 0;
    
    //@ assert arr[0] >= 1 && arr[0] <= 20;
    //@ assert arr[1] >= 1 && arr[1] <= 20;
    //@ assert arr[2] >= 1 && arr[2] <= 20;
    
    if (arr[1] > arr[0]) {
        answer += arr[1] - arr[0];
    }
    
    //@ assert answer == (arr[1] > arr[0] ? arr[1] - arr[0] : 0);
    
    if (arr[2] > arr[1]) {
        answer += arr[2] - arr[1];
    }
    
    //@ assert answer == (((arr[1]) > (arr[0]) ? (arr[1]) - (arr[0]) : 0) +     ((arr[2]) > (arr[1]) ? (arr[2]) - (arr[1]) : 0));
    //@ assert answer >= 0;
    //@ assert answer <= 40;
    
    if (arr[2] > arr[0]) {
        sub = arr[2] - arr[0];
        if (sub < answer) {
            answer = sub;
        }
    }
    
    //@ assert answer >= 0;
    //@ assert answer <= 40;
    
    return answer;
}
