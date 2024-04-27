
void _string_shuffle(char **param_1)

{
  char cVar1;
  int iVar2;
  time_t tVar3;
  ulong uVar4;
  ulong local_20;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_shuffle.\n");
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_shuffle.\n");
  }
  else {
    tVar3 = _time((time_t *)0x0);
    _srand((uint)tVar3);
    uVar4 = _strlen(*param_1);
    while (local_20 = uVar4 - 1, local_20 != 0) {
      iVar2 = _rand();
      cVar1 = (*param_1)[local_20];
      (*param_1)[local_20] = (*param_1)[(ulong)(long)iVar2 % uVar4];
      (*param_1)[(ulong)(long)iVar2 % uVar4] = cVar1;
      uVar4 = local_20;
    }
  }
  return;
}

