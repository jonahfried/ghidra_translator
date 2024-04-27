
bool _string_starts_with(char **param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  bool local_9;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_starts_with.\n");
    local_9 = false;
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_starts_with.\n");
    local_9 = false;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The substring is NULL in string_starts_with.\n");
    local_9 = false;
  }
  else {
    pcVar2 = (char *)_strlen(param_2);
    if (param_1[1] < pcVar2) {
      local_9 = false;
    }
    else {
      iVar1 = _strncmp(*param_1,param_2,(size_t)pcVar2);
      local_9 = iVar1 == 0;
    }
  }
  return local_9;
}

