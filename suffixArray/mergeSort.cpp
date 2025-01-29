#include <iostream>
using namespace std;

void merge(pair<pair<int, int>, int> *array, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    auto *L = new pair<pair<int, int>, int>[n1];
    auto *R = new pair<pair<int, int>, int>[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i].first < R[j].first || (L[i].first == R[j].first && L[i].second <= R[j].second))
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(pair<pair<int, int>, int> *array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}