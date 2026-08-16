// Generated C + ACSL

typedef enum { T, C, E, I } State;

typedef struct {
    State n[100];
    int x;
} TopStruct;

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv4;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    assigns top->n[i];
    ensures top->n[i] == T;
*/
void n_Tryinv__1_0(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = T;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv3;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    assigns top->n[i];
    ensures top->n[i] == T;
*/
void n_Tryinv__1_1(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = T;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires i != p__Inv3;
    requires i != p__Inv4;
    requires \valid(top);
    assigns top->n[i];
    ensures top->n[i] == T;
*/
void n_Tryinv__1_2(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = T;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv4;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    assigns top->n[i], top->x;
    ensures top->n[i] == C;
    ensures top->x == 0;
*/
void n_Critinv__1_0(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = C;
  top->x = 0;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv3;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    assigns top->n[i], top->x;
    ensures top->n[i] == C;
    ensures top->x == 0;
*/
void n_Critinv__1_1(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = C;
  top->x = 0;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i != p__Inv3;
    requires i != p__Inv4;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    assigns top->n[i], top->x;
    ensures top->n[i] == C;
    ensures top->x == 0;
*/
void n_Critinv__1_2(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = C;
  top->x = 0;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv4;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    assigns top->n[i];
    ensures top->n[i] == E;
*/
void n_Exitinv__1_0(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = E;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv3;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    assigns top->n[i];
    ensures top->n[i] == E;
*/
void n_Exitinv__1_1(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = E;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i != p__Inv3;
    requires i != p__Inv4;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    assigns top->n[i];
    ensures top->n[i] == E;
*/
void n_Exitinv__1_2(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = E;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv4;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    assigns top->n[i], top->x;
    ensures top->n[i] == I;
    ensures top->x == 1;
*/
void n_Idleinv__1_0(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = I;
  top->x = 1;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv3;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    assigns top->n[i], top->x;
    ensures top->n[i] == I;
    ensures top->x == 1;
*/
void n_Idleinv__1_1(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = I;
  top->x = 1;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires i != p__Inv3;
    requires i != p__Inv4;
    requires \valid(top);
    assigns top->n[i], top->x;
    ensures top->n[i] == I;
    ensures top->x == 1;
*/
void n_Idleinv__1_2(TopStruct *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = I;
  top->x = 1;
}