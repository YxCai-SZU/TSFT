#include <stdbool.h>

/*@
    requires \valid_read(numbers + (0 .. 2));
    requires ((3) >= 3 &&
    1 <= (numbers)[0] <= 100 &&
    1 <= (numbers)[1] <= 100 &&
    1 <= (numbers)[2] <= 100);
    ensures \result == true <==> 
        (numbers[0] + numbers[1] == numbers[2] || 
         numbers[1] + numbers[2] == numbers[0] || 
         numbers[0] + numbers[2] == numbers[1]);
*/
bool func(int *numbers) {
    int a;
    int b;
    int c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert a == numbers[0] && b == numbers[1] && c == numbers[2];
    
    if (a + b == c || a + c == b || b + c == a) {
        result = true;
        //@ assert result == true;
    } else {
        //@ assert a + b != c && a + c != b && b + c != a;
        result = false;
        //@ assert result == false;
    }
    
    return result;
}
