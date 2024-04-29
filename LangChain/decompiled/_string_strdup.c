
void * _string_strdup(char *param_1)

{
  size_t sVar1;
  void *local_10;
  
  if (param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Parameter \'s\' is NULL in string_strdup.\n"
            );
    local_10 = (void *)0x0;
  }
  else {
    sVar1 = _strlen(param_1);
    local_10 = _malloc(sVar1 + 1);
    if (local_10 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_strdup for string: %s\n",param_1);
      local_10 = (void *)0x0;
    }
    else {
      ___strcpy_chk(local_10,param_1,0xffffffffffffffff);
    }
  }
  return local_10;
}

