void Leaders(int* arr,int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                break;
            }

            if (j == n - 1)
                printf("%d ", arr[i]);
        }
    }
}
 

