void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
{

    int i=0;
    int j=0;
    int k=0;
        
    while(i < size1 && j<size2) {
      if(arr1[i] <= arr2[j]) {
         ans[k] = arr1[i];
         i++;
      }else{
         ans[k] = arr2[j];
         j++;
      }
      k++;
   }
   while(i<size1) {       //extra element in left ans
      ans[k] = arr1[i];
      i++; k++;
   }
   while(j<size2) {     //extra element in right ans
      ans[k] = arr2[j];
      j++; k++;
   }
    
}