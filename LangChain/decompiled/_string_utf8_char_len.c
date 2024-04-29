
undefined8 _string_utf8_char_len(char param_1)

{
  undefined8 local_10;
  
  if (((int)param_1 & 0x80U) == 0) {
    local_10 = 1;
  }
  else if (((int)param_1 & 0xe0U) == 0xc0) {
    local_10 = 2;
  }
  else if (((int)param_1 & 0xf0U) == 0xe0) {
    local_10 = 3;
  }
  else if (((int)param_1 & 0xf8U) == 0xf0) {
    local_10 = 4;
  }
  else {
    local_10 = 0;
  }
  return local_10;
}

