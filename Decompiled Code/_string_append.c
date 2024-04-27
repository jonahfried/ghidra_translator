
void _string_append(long *param_1,char *param_2)

{
  size_t sVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_append.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The strItem is NULL in string_append.\n");
  }
  else {
    sVar1 = _strlen(param_2);
    if (sVar1 != 0) {
      if ((ulong)param_1[2] <= param_1[1] + sVar1) {
        lVar2 = param_1[1] + sVar1 + 1;
        lVar3 = _memory_pool_allocate(param_1[3],lVar2);
        if (lVar3 == 0) {
          _fprintf(*(FILE **)PTR____stderrp_10000a038,
                   "Error: Memory allocation failed in string_append.\n");
          return;
        }
        ___memcpy_chk(lVar3,*param_1,param_1[1],0xffffffffffffffff);
        *param_1 = lVar3;
        param_1[2] = lVar2;
      }
      ___strcpy_chk(*param_1 + param_1[1],param_2,0xffffffffffffffff);
      param_1[1] = sVar1 + param_1[1];
    }
  }
  return;
}

