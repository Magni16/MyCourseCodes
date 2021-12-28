int multiplyNumbers(int m, int n) {
    if(n>m){
        return multiplyNumbers(n,m);
    }
    if(m==0 || n==0){
        return 0;
    }
    return m+multiplyNumbers(m,n-1);

}


