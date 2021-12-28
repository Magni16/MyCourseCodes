string getCompressedString(string &str) {
    
  int i = 0;
  string s1;
  while (i < str.length())
  {
    int count = 1;
    while (i < str.length() && str[i] == str[i + 1])
    {
      i++;
      count++;
    }
    s1+=str[i];
    if (count > 1)
      s1+=std::to_string(count);

    i++;
  }
    return s1;

}

