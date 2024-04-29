
int _string_find_last_not_of(long *param_1,char *param_2,ulong param_3)

{
  int iVar1;
  size_t sVar2;
  ulong local_40;
  int local_34;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_find_last_not_of.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The buffer is NULL in string_find_last_not_of.\n");
  }
  else {
    sVar2 = _strlen(param_2);
    if (sVar2 == 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: The buffer is empty in string_find_last_not_of.\n");
    }
    else if (param_3 < sVar2 - 1) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Position is too small in string_find_last_not_of.\n");
    }
    else {
      local_40 = param_3;
      if (param_1[1] - sVar2 <= param_3) {
        local_40 = param_1[1] - sVar2;
      }
      for (local_34 = (int)local_40; -1 < local_34; local_34 = local_34 + -1) {
        iVar1 = _strncmp((char *)(*param_1 + (long)local_34),param_2,sVar2);
        if (iVar1 != 0) {
          return local_34;
        }
      }
    }
  }
  return -1;
}

