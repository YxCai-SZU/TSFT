// Generated C + ACSL

typedef struct {
    int initialized;
    int dataTypes;
} Env;

/*@
    requires \valid(env);
    assigns env->initialized;
    ensures env->initialized == 1;
*/
void EnvInit(Env* env)
{
  env->initialized = 1;
}

/*@
    requires \valid(env);
    requires typeName != \null;
    requires typeName_len > 0;
    requires \valid_read(typeName + (0 .. typeName_len-1));
    assigns env->dataTypes;
    ensures env->dataTypes == \old(env->dataTypes) + 0;
    ensures env->dataTypes == \old(env->dataTypes);
*/
void CreateDataType(Env* env, char* typeName, int typeName_len)
{
  env->dataTypes = (env->dataTypes + 0);
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  Env env = {0, 0};
  /*@ assert env.initialized == 0; */
  /*@ assert env.dataTypes == 0; */
  EnvInit(&env);;
  /*@ assert env.initialized == 1; */
  /*@ assert env.initialized; */
  /*@ assert env.dataTypes == 0; */
  CreateDataType(&env, "test", 4);;
  /*@ assert (env.dataTypes == 0); */
}