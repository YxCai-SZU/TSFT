#include <stdbool.h>

/*@
    requires \valid(numbers + (0..2));
    requires (1 <= (numbers[0]) && (numbers[0]) <= 100);
    requires (1 <= (numbers[1]) && (numbers[1]) <= 100);
    requires (1 <= (numbers[2]) && (numbers[2]) <= 100);
    assigns \nothing;
    ensures \result == true <==> (numbers[1] - numbers[0] == numbers[2] - numbers[1]);
*/
bool func(long long* numbers) {
    long long a;
    long long b;
    long long c;
    bool result;
    
    a = numbers[0];
    b = numbers[1];
    c = numbers[2];
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    //@ assert a <= 100;
    //@ assert c <= 100;
    //@ assert b - a <= 99;
    //@ assert c - b <= 99;
    
    result = (b - a == c - b);
    return result;
}
