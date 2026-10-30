#include <iostream>
#include <random>//для рандомных значений

using namespace std;

const int N = 1000;

size_t bubble_sort(int arr[], int size)
{
    size_t iterations = 0;

    for (int n = size; n > 1; )
    {
        int last_swap = 0;

        for (int j = 1; j < n; ++j)
        {
            ++iterations;

            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                last_swap = j;
            }
        }

        if (last_swap == 0) break;
        n = last_swap;
    }

    return iterations;
}

size_t selection_sort(int arr[], int size)
{
    size_t iterations = 0;

    for (int i = 0; i < size - 1; ++i)
    {
        int min_index = i;

        for (int j = i + 1; j < size; ++j)
        {
            ++iterations;

            if (arr[j] < arr[min_index])
                min_index = j;
        }

        if (min_index != i)
            swap(arr[i], arr[min_index]);
    }

    return iterations;
}

size_t insertion_sort(int arr[], int size)
{
    size_t iterations = 0;

    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i;

        while (j > 0)
        {
            ++iterations;

            if (arr[j - 1] <= key)
                break;

            arr[j] = arr[j - 1];
            --j;
        }

        arr[j] = key;
    }

    return iterations;
}

int main()
{
    int original[N];
    int bubble[N];
    int selection[N];
    int insertion[N];

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, 9999);
    for (int i = 0; i < N; ++i)
        original[i] = distribution(generator);
    for (int i = 0; i < N; ++i)
    {
        bubble[i] = original[i];
        selection[i] = original[i];
        insertion[i] = original[i];
    }

    cout << "Bubble sort:    "
         << bubble_sort(bubble, N) << " comparisons\n";

    cout << "Selection sort: "
         << selection_sort(selection, N) << " comparisons\n";

    cout << "Insertion sort: "
         << insertion_sort(insertion, N) << " comparisons\n";
}