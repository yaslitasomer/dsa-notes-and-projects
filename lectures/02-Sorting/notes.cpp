//============================================================================
// Name        : notes.cpp
// Author      : Ömer YASLITAŞ
// Version     : 1.0
// Description : Sorting - NOTES PART 1
//============================================================================
#include <iostream> //input/output
#include <math.h>   //usual C lib header file for math

using namespace std;

namespace Search
{
    int my_array[] = {10, 20, 30, 40, 50};
    const int DEFAULT_SIZE = 5;
    int sequentialSearch(int item, int n = DEFAULT_SIZE, const int a[] = my_array)
    {
        int i;
        for (i = 0; i < n && a[i] != item; i++)
            ;
        if (i == n)
            return -1;
        return i;

        //============================================================================
        // SEQUENTIAL SEARCH - TIME COMPLEXITY ANALYSIS (BIG O NOTATION)
        //============================================================================

        // 1. UNSUCCESSFUL SEARCH:
        //    -> O(n) : The item is not in the array, requiring a check of all 'n' elements.

        // 2. SUCCESSFUL SEARCH:
        //    -> Best-Case: The item is in the first location of the array. -> O(1)
        //    -> Worst-Case: The item is in the last location of the array. -> O(n)
        //    -> Average-Case: (n(n+1)/2)/n = O(n)
        //       * Requires checking approximately n/2 elements on average. -> O(n)
        //============================================================================
    }

    int binarySearch(int x, int a[] = my_array, int size = DEFAULT_SIZE)
    { // if the array is sorted
        int low = 0;
        int high = size - 1;
        int mid; // will be the index of target when found

        while (low <= high)
        {
            mid = (low + high) / 2;
            if (a[mid] < x)
                low = mid + 1;
            else if (a[mid] > x)
                high = mid - 1;
            else
                return mid;
        }
        return -1;

        //============================================================================
        // BINARY SEARCH - TIME COMPLEXITY ANALYSIS (BIG O NOTATION)
        // Note: Binary Search only works on SORTED arrays.
        //============================================================================

        // 1. UNSUCCESSFUL SEARCH:
        //    -> O(log₂n) : The number of iterations is ⌊log₂n⌋ + 1.

        // 2. SUCCESSFUL SEARCH:
        //    -> Best-Case: The item is found in the first iteration. -> O(1)
        //    -> Worst-Case: The number of iterations is ⌊log₂n⌋ + 1. -> O(log₂n)
        //    -> Average-Case: The average number of iterations is less than log₂n. -> O(log₂n)
        //============================================================================
    }
}

namespace Sort
{
    template <class Item>
    void selectionSort(Item a[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[min])
                {
                    min = j;
                }
            swap(a[i], a[min]);
        }
        // Selection sort is O(n^2) for all three cases
    }

    template <class Object>
    void swap(Object &lhs, Object &rhs)
    {
        Object tmp = lhs;
        lhs = rhs;
        rhs = tmp;
    }

    void printArray(int a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << a[i] << " ";
        }
        cout << endl;
    }

    template <class Item>
    void insertionSort(Item a[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            Item tmp = a[i]; // item to insert
            int j;
            for (j = i; j > 0 && tmp < a[j - 1]; j--)
            {
                a[j] = a[j - 1]; // shift
            }
            a[j] = tmp; // insert
        }

        // Best case: O(n) - already sorted
        // Worst case: O(n^2) - reverse order
        // Average case: O(n^2)
    }

    template <class Item>
    void bubleSort(Item a[], int n)
    {
        bool sorted = false;
        int last = n - 1;

        for (int i = 0; (i < last) && !sorted; i++)
        {
            sorted = true;
            for (int j = last; j > i; j--)
                if (a[j - 1] > a[j])
                {
                    swap(a[j], a[j - 1]);
                    sorted = false; // signal exchange
                }
        }
        // Best case: O(n) - already sorted
        // Worst case: O(n^2) - reverse order
        // Average case: O(n^2)
    }

}

int main()
{
    // for (int i = 10; i <= 60; i+=10) {cout << "Index of " << i << " : " << Search::sequentialSearch(i) << endl;}
    // for (int i = 10; i <= 60; i+=10) {cout << "Index of " << i << " : " << Search::binarySearch(i) << endl;}

    int data[] = {64, 5, 12, 22, 11};
    int size = sizeof(data) / sizeof(data[0]);

    /* SELECTION SORT
    Sort::selectionSort(data, size);
    Sort::printArray(data, size);
    */

    /*
    Sort::insertionSort(data, size);
    Sort::printArray(data, size);
    */

    Sort::bubleSort(data, size);
    Sort::printArray(data, size);

    return 0;
}