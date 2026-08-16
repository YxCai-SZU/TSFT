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
    requires p__Inv4 < N0;
    requires \valid(top);
    assigns top->n[i];
*/
void n_Tryinv__2_0(TopStruct *top, int i, int N0, int p__Inv4)
{
  top->n[i] = T;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires 0 <= p__Inv4 < N0;
    requires i != p__Inv4;
    requires \valid(top);
    requires \forall integer ii, jj;
        0 <= ii < N0 && 0 <= jj < N0 && ii != jj ==>
        top->n[ii] != top->n[jj];
    requires !(top->n[p__Inv4] == C && top->x == 1);
    requires top->n[i] == I;
    assigns top->n[i];
*/
void n_Tryinv__2_1(TopStruct *top, int i, int N0, int p__Inv4)
{
  top->n[i] = T;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv4;
    requires p__Inv4 < N0;
    requires \valid(top);
    assigns top->n[i], top->x;
*/
void n_Critinv__2_0(TopStruct *top, int i, int N0, int p__Inv4)
{
  top->n[i] = C;
  top->x = 0;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i != p__Inv4;
    requires p__Inv4 < N0;
    requires \valid(top);
    assigns top->n[i], top->x;
*/
void n_Critinv__2_1(TopStruct *top, int i, int N0, int p__Inv4)
{
  top->n[i] = C;
  top->x = 0;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv4;
    requires p__Inv4 < N0;
    requires \valid(top);
    assigns top->n[i];
*/
void n_Exitinv__2_0(TopStruct *top, int i, int N0, int p__Inv4)
{
  top->n[i] = E;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires \valid(top);
    requires \forall integer ii, jj;
        0 <= ii < N0 && 0 <= jj < N0 && ii != jj ==> top->n[ii] != top->n[jj];
    requires p__Inv4 < N0;
    requires i != p__Inv4;
    requires !(top->n[p__Inv4] == C && top->x == 1);
    requires top->n[i] == C;
    assigns top->n[i];
*/
void n_Exitinv__2_1(TopStruct *top, int i, int N0, int p__Inv4)
{
  top->n[i] = E;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv4;
    requires p__Inv4 < N0;
    requires \valid(top);
    assigns top->n[i], top->x;
*/
void n_Idleinv__2_0(TopStruct *top, int i, int N0, int p__Inv4)
{
  top->n[i] = I;
  top->x = 1;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i != p__Inv4;
    requires p__Inv4 < N0;
    requires \valid(top);
    assigns top->n[i], top->x;
*/
void n_Idleinv__2_1(TopStruct *top, int i, int N0, int p__Inv4)
{
  top->n[i] = I;
  top->x = 1;
}