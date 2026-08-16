/*@
    requires (0 <= (A) && (A) <= 100 && 0 <= (P) && (P) <= 100);
    ensures \result == ((3 * (A) + (P)) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int A, unsigned int P)
{
    unsigned int ans;
    unsigned int temp;
    unsigned int count;
    
    ans = 0;
    temp = 3 * A + P;
    count = 0;
    
    /*@
        loop invariant 0 <= temp <= 3 * A + P;
        loop invariant 0 <= count <= ((3 * (A) + (P)) / 2);
        loop invariant temp == 3 * A + P - 2 * count;
        loop invariant (0 <= (A) && (A) <= 100 && 0 <= (P) && (P) <= 100);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
    }
    
    //@ assert temp < 2;
    //@ assert count == ((3 * (A) + (P)) / 2);
    ans = count;
    
    return ans;
}

int main(void)
{
    return 0;
}
