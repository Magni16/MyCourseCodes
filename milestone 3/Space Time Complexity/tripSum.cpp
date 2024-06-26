
#include <iostream>
#include <algorithm>
using namespace std;




/*
2
    Time Complexity : O(n^2)
3
    Space Complexity : O(1)
4
    where n is size of Array/List
5
*/

int pairSum(int *arr, int startIndex, int endIndex, int num)

{

    int numPair = 0;

    while (startIndex < endIndex)

    {

        if (arr[startIndex] + arr[endIndex] < num)

        {

            startIndex++;
        }

        else if (arr[startIndex] + arr[endIndex] > num)

        {

            endIndex--;
        }

        else

        {

            int elementAtStart = arr[startIndex];

            int elementAtEnd = arr[endIndex];

            if (elementAtStart == elementAtEnd)

            {

                int totalElementsFromStartToEnd = (endIndex - startIndex) + 1;

                numPair += (totalElementsFromStartToEnd * (totalElementsFromStartToEnd - 1) / 2);

                return numPair;
            }

            int tempStartIndex = startIndex + 1;

            int tempEndIndex = endIndex - 1;

            while (tempStartIndex <= tempEndIndex && arr[tempStartIndex] == elementAtStart)

            {
                tempStartIndex += 1;
            }

            while (tempEndIndex >= tempStartIndex && arr[tempEndIndex] == elementAtEnd)

            {

                tempEndIndex -= 1;
            }

            int totalElementsFromStart = (tempStartIndex - startIndex);

            int totalElementsFromEnd = (endIndex - tempEndIndex);

            numPair += (totalElementsFromStart * totalElementsFromEnd);

            startIndex = tempStartIndex;

            endIndex = tempEndIndex;
        }
    }

    return numPair;
}

int tripletSum(int *arr, int n, int num)

{

    sort(arr, arr + n);

    int numTriplets = 0;

    for (int i = 0; i < n; i++)

    {

        int pairSumFor = num - arr[i];

        int numPairs = pairSum(arr, (i + 1), (n - 1), pairSumFor);

        numTriplets += numPairs;
    }

    return numTriplets;
}





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}