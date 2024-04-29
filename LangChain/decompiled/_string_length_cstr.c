
size_t _string_length_cstr(char *param_1)

{
  size_t local_10;
  
  if (param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: str is null in string_length_cstr.\n");
    local_10 = 0;
  }
  else {
    local_10 = _strlen(param_1);
  }
  return local_10;
}

