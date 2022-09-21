#include <bits/stdc++.h>
using std::string;
using std::swap;

string trans(int num, int base) {
  if (num == 0)
    return "";
  return trans(num / base, base) + "0123456789ABCDEF"[num % base];
}

void arraySort(int* array, int left, int mid, int right) {
  int* arrayCopy = (int*)malloc(sizeof(int) * (right - left));
  memcpy(arrayCopy, array + left, sizeof(int) * (right - left));
  int one = 0, another = mid - left;
  for (int ite = left; one < mid - left || another < right - left; ite++) {
    if (one == mid - left)
      array[ite] = arrayCopy[another++];
    else if (another == right - left)
      array[ite] = arrayCopy[one++];
    else {
      if (arrayCopy[one] < arrayCopy[another])
        array[ite] = arrayCopy[one++];
      else
        array[ite] = arrayCopy[another++];
    }
  }
  free(arrayCopy);
}

void recurSort(int* array, const int& size, int left, int right) {
  if (left == right)
    return;
  else if (right - left == 1) {
    if (array[left] > array[right]) {
      int tmp = array[left];
      array[left] = array[right];
      array[right] = tmp;
    }
  }
  else {
    int mid = (left + right) / 2;
    recurSort(array, size, left, mid);
    recurSort(array, size, mid, right);
    arraySort(array, left, mid, right);
  }
}

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    // Last i elements are already
    // in place
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
}

void printArray(int* a, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

void randomArray(int* a, int size) {
  for (long long i = 0; i < size; i++)
    a[i] = ((i * 5 + 2) * 3 + i % 4) % 1000000000;
}

bool arrayIsSorted(int* a, int size) {
  for (int i = 0; i < size - 1; i++) {
    if (a[i] > a[i + 1])
      return false;
  }
  return true;
}

void testRecurSort() {
  int a1[] = { 0 };
  int a2[] = { 1, 0 };
  int a3[] = { 0, 2 };
  int a4[] = { 0, 2, 4, 1, 3, 5 };
  int a5[] = { 8, 6, 3, 3, 7, 55 };
  int a6[1000000];
  randomArray(a6, 1000000);

  recurSort(a1, 1, 0, 0);
  printArray(a1, 1);
  recurSort(a2, 2, 0, 1);
  printArray(a2, 2);
  recurSort(a3, 2, 0, 1);
  printArray(a3, 2);
  recurSort(a4, 6, 0, 5);
  printArray(a4, 6);
  recurSort(a5, 6, 0, 5);
  printArray(a5, 6);
  recurSort(a6, 1000000, 0, 999999);
  printArray(a5, 1000000);
}

void testSTLSortAndRecur() {
  const int arraySize = 100000000;
  int* recur = (int*)malloc(sizeof(int) * arraySize);
  int* stl = (int*)malloc(sizeof(int) * arraySize);
  randomArray(recur, arraySize);
  memcpy(stl, recur, sizeof(int) * arraySize);

  int start = clock();
  recurSort(recur, arraySize, 0, arraySize - 1);
  int cost = clock() - start;
  if (!arrayIsSorted(recur, arraySize)) {
    printf("recurSort failed!\n");
    return;
  }
  printf("recur sort costs: %Lf s\n", (long double)cost / CLOCKS_PER_SEC);

  start = clock();
  std::sort(stl, stl + arraySize);
  cost = clock() - start;
  if (!arrayIsSorted(stl, arraySize)) {
    printf("STLSort failed!\n");
    return;
  }
  printf("STL sort costs: %Lf s\n", (long double)cost / CLOCKS_PER_SEC);
}

void testCmpBubbleAndRecur() {
  int bubble[100000];
  int* recur = (int*)malloc(sizeof(int) * 100000000);
  randomArray(bubble, 100000);
  randomArray(recur, 100000000);
  int start = clock();
  //bubbleSort(bubble, 100000);
  int cost = clock() - start;
  printf("bubble sort costs: %Lf s\n", (long double)cost / CLOCKS_PER_SEC);

  start = clock();
  recurSort(recur, 100000000, 0, 99999999);
  cost = clock() - start;
  printf("recur sort costs: %Lf s\n", (long double)cost / CLOCKS_PER_SEC);
}

int main(int argc, char** argv) {
  testSTLSortAndRecur();
}