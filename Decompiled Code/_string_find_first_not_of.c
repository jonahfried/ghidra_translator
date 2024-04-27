
undefined4 _string_find_first_not_of(long *param_1,char *param_2,ulong param_3)

{
  int iVar1;
  size_t sVar2;
  ulong local_38;
  undefined4 local_c;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_find_first_not_of.\n");
    local_c = 0xffffffff;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The buffer is NULL in string_find_first_not_of.\n");
    local_c = 0xffffffff;
  }
  else if (param_3 < (ulong)param_1[1]) {
    sVar2 = _strlen(param_2);
    local_38 = param_3;
    if (sVar2 == 0) {
      local_c = (undefined4)param_3;
    }
    else {
      for (; local_38 <= param_1[1] - sVar2; local_38 = local_38 + 1) {
        iVar1 = _strncmp((char *)(*param_1 + local_38),param_2,sVar2);
        if (iVar1 != 0) {
          return (int)local_38;
        }
      }
      local_c = 0xffffffff;
    }
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Position out of bounds in string_find_first_not_of.\n");
    local_c = 0xffffffff;
  }
  return local_c;
}

