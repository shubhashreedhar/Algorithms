/* Given an array of positive integers. We need to make the given array a ‘Palindrome’.
 * Only allowed operation on array is merge. Merging two adjacent elements means replacing them with their sum.
 * The task is to find minimum number of merge operations required to make given array a ‘Palindrome’.
 * Input : arr[] = {1, 4, 5, 1}
 * Output : 1
 * We can make given array palindrome with minimum one merging (merging 4 and 5 to make 9)
 */

int palindromic_array(int arr[], int n)
{
    int i,j;
    int res = 0;
   
    for(i=0,j=n-1; i<=j;)
    {
        if(arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if(arr[i] > arr[j])
        {
            arr[j-1] += arr[j];
            j--;
            res++;
        }
        else
        {
            arr[i+1] += arr[i];
            i++;
            res++;
        }
    }
    return res;
}
