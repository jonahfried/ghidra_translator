
void _string_to_capitalize(char **param_1)

{
  int iVar1;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_to_capitalize.\n");
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_to_capitalize.\n");
  }
  else if (param_1[1] == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The size of String object is zero in string_to_capitalize.\n");
  }
  else {
    iVar1 = _toupper((int)**param_1);
    **param_1 = (char)iVar1;
  }
  return;
}

