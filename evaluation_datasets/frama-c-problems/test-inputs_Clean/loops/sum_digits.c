/*@
    
    
    
    logic integer SumDigits(integer n) =
        (n <= 0) ? 0 : (n % 10) + SumDigits(n / 10);
*/

int func(int num) {
    int i = 0;
    int sum = 0;

    while(num > 0) {
        i = num % 10;
        sum += i;
        num /= 10;
    }
    return sum;
}

void test() {

    int s1 = func(5);
    //@ assert s1 == 5;

    int s2 = func(123);
    //@ assert s2 == 6;

    int s3 = func(10203);
    //@ assert s3 == 6;

    int s4 = func(0);
    //@ assert s4 == 0;
}
