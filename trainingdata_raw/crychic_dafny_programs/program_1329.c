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
    requires 0 <= top_idx < N0;
    requires p__Inv4 < N0;
    requires i != p__Inv4;
    requires !(top_idx == p__Inv4 && top_x == 1);
    requires top_idx == i;
    requires \valid(top);
    assigns top->n[i];
*/
void n_Tryinv__2_1(TopStruct *top, int i, int N0, int p__Inv4, int top_idx, int top_x)
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
    requires top != \null;
    requires \valid(top);
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