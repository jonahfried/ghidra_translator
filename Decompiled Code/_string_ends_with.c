
bool _string_ends_with(long *param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  bool local_9;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_ends_with.\n");
    local_9 = false;
  }
  else if (*param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_ends_with.\n");
    local_9 = false;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The substring is NULL in string_ends_with.\n");
    local_9 = false;
  }
  else {
    sVar2 = _strlen(param_2);
    if ((ulong)param_1[1] < sVar2) {
      local_9 = false;
    }
    else {
      iVar1 = _strncmp((char *)((*param_1 + param_1[1]) - sVar2),param_2,sVar2);
      local_9 = iVar1 == 0;
    }
  }
  return local_9;
}

