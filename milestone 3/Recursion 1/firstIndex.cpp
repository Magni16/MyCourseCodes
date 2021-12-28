int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

    
    
    for(int i=0;i<size;i++){
        if(input[i]==x){
            return i;
        }
    }
    return -1;
}



