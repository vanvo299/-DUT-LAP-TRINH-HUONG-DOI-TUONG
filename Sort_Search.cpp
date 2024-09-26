#include <iostream>
#include <algorithm>

using namespace std;

void input(int *arr, int n)
{
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}


// tăng dần
bool ascending(int left, int right)
{
    return left > right;
}

// giảm dần
bool descending(int left, int right)
{
    return left < right;
}

void output(int *arr, int n)
{
    cout << "The array is sorted: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' '; 
    } 
    cout << endl;
}

// Bubble Sort
void BubbleSort(int *arr, int n, bool (*compareFunction)(int, int))
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareFunction(*(arr + j), *(arr + j + 1))) {
                swap(arr[j], arr[j + 1]); 
            }
        }
    }
}

// Selection Sort
void SelectionSort(int *arr, int n, bool (*compareFunction)(int, int))
{
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (!compareFunction(arr[j], arr[min])) {
                min = j;
            }
        }
        if (min != i) {
            swap(arr[i], arr[min]);
        }
    }
}

// Insertion Sort
void InsertionSort(int *arr, int n, bool (*compareFunction)(int, int))
{
    int pos, x;
    for (int i = 1; i < n; i++) {
        x = arr[i];
        pos = i - 1;
        while(pos >= 0 && compareFunction(arr[pos], x)) {
            arr[pos + 1] = arr[pos];
            pos--;
        }

        arr[pos + 1] = x;
   } 
}

// Quick Sort
void quickSort(int *arr, int l, int r, bool (*compareFunction)(int, int))
{
    if (l < r) {
        int pivot = arr[r];
        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (!compareFunction(arr[j], pivot)) {
                ++i;
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        ++i;
        int tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;
        int pivotIndex = i;
        quickSort(arr, l, pivotIndex - 1, compareFunction);
        quickSort(arr, pivotIndex + 1, r, compareFunction);
    }
}

void quickSort(int *arr, int n, bool (*compareFunction)(int , int))
{
    quickSort(arr, 0, n - 1, compareFunction);
}


// Heap Sort
void heapify(int *arr, int n, int i, bool(*compareFunction)(int , int))
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && compareFunction(arr[left], arr[largest])) {
        largest = left;
    }
    if (right < n && compareFunction(arr[right], arr[largest])) {
        largest = right;
    }

    if (largest != i) {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, n, largest, compareFunction);
    }
}

void heapSort(int *arr, int n, bool (*compareFunction)(int, int))
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, compareFunction);
    }

    for (int i = n - 1; i > 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0, compareFunction);
    }
}

// Merge sort
void merge(int *arr, int left, int mid, int right, bool(*compareFunction)(int, int))
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if (!compareFunction(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }   

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    } 
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right, bool(*compareFunction)(int, int)) 
{
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, compareFunction);
    mergeSort(arr, mid + 1, right, compareFunction);
    merge(arr, left, mid, right, compareFunction);
}

void mergeSort(int *arr, int n, bool(*compareFunction) (int , int))
{
    mergeSort(arr, 0, n - 1, compareFunction);
}

// Shell sort

void shellSort(int *arr, int n, bool(*compareFunction) (int, int))
{
    for (int h = n / 2; h > 0; h /= 2) {
        for (int i = h; i < n; i++) {
            int tmp = arr[i];
            int j = i;

            while(j >= h && compareFunction(arr[j - h], tmp)) {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = tmp;
        }
    }
}


// Binary search 
int binarySearch(int* p, int n, int key, bool (*CompFunc)(int, int)) {
    int g = (n - 1) / 2;
    if (*(p + g) == key) {
        return g;
    }
    else if (CompFunc(*(p + g), key)) {
        for (int i = 0; i < g; i++) {
            if (*(p + i) == key) return i;
        }
        return -1;
    }
    else {
        for (int i = g + 1; i < n; i++) {
            if (*(p + i) == key) return i;
        }
        return -1;
    }
}

void sortArrayToSearch(int *arr, int n, bool (*compareFunction)(int, int), void (*sapXep)(int *, int, bool (*)(int, int))) {
    sapXep(arr, n, compareFunction);
}
int main()
{
    int n;
    cout << "So luong phan tu trong mang: ";
    cin >> n;
    int *arr = new int[n];
    input(arr, n);

    int select;
    cout << endl;
    cout << "1. Sap Xep." << endl;
    cout << "2. Tim Kiem." << endl;
    cout << "0. Thoat." << endl;
    cout << "Nhap lua chon: "; cin >> select;
    while(select < 0 || select > 2) {
        cout << "Vui long nhap lai: ";
        cin >> select;
    } 
    cout << endl;
    void (*sortArray) (int *, int, bool (*CompareFunction)(int , int));
        int (*searchArray) (int *, int, int, bool (*compareFunction)(int, int)) = binarySearch;
    switch (select)
    {
    case 1:
        // sap xep
        cout << "1. Selection Sort." << endl;
        cout << "2. Bubble Sort." << endl;
        cout << "3. Insertion Sort." << endl;
        cout << "4. Shell Sort." << endl;
        cout << "5. Quick Sort." << endl;
        cout << "6. Heap Sort." << endl;
        cout << "7. Merge Sort." << endl;
        int selectSort;
        cout << "Nhap lua chon thuat toan sap xep: ";
        cin >> selectSort;
        cout << endl;
        while(selectSort < 0 || selectSort > 7) {
            cout << "Vui long nhap lai: ";
            cin >> selectSort;
        }


        switch (selectSort) {
        case 1:
            sortArray = SelectionSort;
            break;
        case 2:
            sortArray = BubbleSort;
            break;
        case 3:
            sortArray = InsertionSort;
            break;
        case 4:
            sortArray = shellSort;
            break;
        case 5:
            sortArray = quickSort;
            break;
        case 6:
            sortArray = heapSort;
            break;
        default:
            sortArray = shellSort;
            break;
        }
        cout << "1. Tang dan." << endl;
        cout << "2. Giam dan." << endl;
        cout << "Chon thu tu sap xep: ";        
        int choice;
        do {
            cin >> choice;
        } while (choice != 1 && choice != 2);
        if (choice == 1) {
            sortArray(arr, n, ascending);
        }
        else sortArray(arr, n, descending);
        output(arr, n);
        break;
    case 2:
        // tim kiem
        int x;
        cout << "Nhap gia tri can tim: ";
        cin >> x;
        int choiceSearch;
        cout << "1. Tang dan." << endl;
        cout << "2. Giam dan." << endl;
        cout << "Chon thu tu sap xep cua mang: ";
        cin >> choiceSearch;

        while (choiceSearch < 1 || choiceSearch > 2) {
            cout << "Vui long nhap lai: ";
            cin >> choiceSearch;
        }
        if (choiceSearch == 1) {
            sortArrayToSearch(arr, n, ascending, quickSort);
        } else 
            sortArrayToSearch(arr, n, descending, quickSort);

        int pos;
        if (choiceSearch == 1) {
            pos = searchArray(arr, n, x, ascending);
        } else {
            pos = searchArray(arr, n, x, descending);
        }

        if (pos == -1) {
            cout << x << " khong ton tai trong mang." << endl;
        } else {
            cout << "So " << x << " nam o vi tri thu " << pos + 1 << " trong mang." << endl;
        }
        break;
    }

    delete []arr;
    return 0;
}