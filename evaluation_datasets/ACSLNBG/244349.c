
void func(int n)
{
    //@ assert n % 2 == 0;
    //@ assert (n + 4) % 2 == 0;
}


void func2(int n)
{
    //@ assert n % 3 == 0;
    //@ assert (n + 6) % 3 == 0;
}


void func3(int n)
{
    //@ assert n % 2 == 0;
    //@ assert (n + 12) % 2 == 0;
    //@ assert n % 3 == 0;
    //@ assert (n + 12) % 3 == 0;
}

int main()
{
    return 0;
}
