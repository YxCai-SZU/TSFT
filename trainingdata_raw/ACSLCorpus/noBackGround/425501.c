/*@
requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
ensures \result == (b - a == c - b);
assigns \nothing;
*/
int func(int a, int b, int c)
{
    int diff1;
    int diff2;
    int result;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    
    diff1 = b - a;
    diff2 = c - b;
    
    //@ assert diff1 == b - a;
    //@ assert diff2 == c - b;
    
    result = (diff1 == diff2);
    return result;
}

int main()
{
    return 0;
}
