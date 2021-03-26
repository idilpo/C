int main()
{
    int n;
    int arr[100000];

    quicksort(arr, 0, n - 1);

}


void quicksort(int arr[], int start, int end)
{
    int pivotindex;

    if (start < end)
    {
        pivotindex = partitionarray(arr, start, end);

        quicksort(arr, start, pivotindex - 1);
        quicksort(arr, pivotindex + 1, end);
    }

    return;
}


int partitionarray(int arr[], int start, int end)
{
    int pivot;
    int i, j;

    pivot = arr[start];

    i = start + 1;
    j = end;
    while (i <= j)
    {
        if (arr[i] <= pivot)
            i++;
        else if (arr[j] > pivot)
            j--;
        else
        {
            swap(arr, i, j);
            i++;
            j--;
        }
    }

    swap(arr, start, j);

    return j;
}


void swap(int arr[], int i, int j)
{
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    return;
}
