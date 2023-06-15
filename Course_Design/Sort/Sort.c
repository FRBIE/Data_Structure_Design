#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义排序算法函数

// 直接插入排序
void insertionSort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }

}

// 折半插入排序
void binaryInsertionSort(int arr[], int n) 
{
    int i, j, temp, low, high, mid;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        low = 0;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] > temp) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= high + 1; j--) {
            arr[j+1] = arr[j];
        }
        arr[high+1] = temp;
    }
}

// 希尔排序
void shellSort(int arr[], int n) 
{
    int i, j, temp, gap;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
                arr[j+gap] = arr[j];
            }
            arr[j+gap] = temp;
        }
    }
}

// 冒泡排序
void bubbleSort(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (arr[j-1] > arr[j]) {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 快速排序
void quickSort(int arr[], int low, int high) 
{
    int i, j, temp;
    if (low < high) {
        i = low;
        j = high;
        temp = arr[i];
        while (i < j) {
            while (i < j && arr[j] >= temp) {
                j--;
            }
            if (i < j) {
                arr[i++] = arr[j];
            }
            while (i < j && arr[i] < temp) {
                i++;
            }
            if (i < j) {
                arr[j--] = arr[i];
            }
        }
        arr[i] = temp;
        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }
}


// 简单选择排序
void selectionSort(int arr[], int n) 
{
    int i, j, k, temp;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        if (k != i) {
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}

// 堆排序
void heapSort(int arr[], int n) 
{
    int i, j, k, temp;
    for (i = n / 2 - 1; i >= 0; i--) {
        while (2 * i + 1 < n) {
            j = 2 * i + 1;
            if (j + 1 < n && arr[j] < arr[j+1]) {
                j++;
            }
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i = j;
            } else {
                break;
            }
        }
    }
    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        k = 0;
        while (2 * k + 1 < i) {
            j = 2 * k + 1;
            if (j + 1 < i && arr[j] < arr[j+1]) {
                j++;
            }
            if (arr[k] < arr[j]) {
                temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
                k = j;
            } else {
                break;
            }
        }
    }
}
void merge(int arr[], int low, int mid, int high) 
{
    int i, j, k;
    int *temp = (int *)malloc((high - low + 1) * sizeof(int));
    for (i = low, j = mid + 1, k = 0; i <= mid && j <= high; k++) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i++];
        } else {
            temp[k] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= high) {
        temp[k++] = arr[j++];
    }
    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
    free(temp);
}
// 归并排序
void mergeSort(int arr[], int low, int high) 
{
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// 生成随机数
void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 99 + 1;
    }
}
// 测试排序算法性能
void testSortingAlgorithm(int algorithmType, int arr[], int n) {
    clock_t start, end;
    double cpu_time_used;

    switch (algorithmType) {
        case 1:
            printf("算法: 直接插入排序\n");
            // 调用直接插入排序函数
            start = clock();
            insertionSort(arr, n);
            end = clock();
            break;
        case 2:
            printf("算法: 折半插入排序\n");
            // 调用折半插入排序函数
            start = clock();
            binaryInsertionSort(arr, n);
            end = clock();
            break;
        case 3:
            printf("算法: 希尔排序\n");
            // 调用希尔排序函数
            start = clock();
            shellSort(arr, n);
            end = clock();
            break;
        case 4:
            printf("算法: 冒泡排序\n");
            // 调用冒泡排序函数
            start = clock();
            bubbleSort(arr, n);
            end = clock();
            break;
        case 5:
            printf("算法: 快速排序\n");
            // 调用快速排序函数
            start = clock();
            quickSort(arr, 0, n-1);
            end = clock();
            break;
        case 6:
            printf("算法: 简单选择排序\n");
            // 调用简单选择排序函数
            start = clock();
            selectionSort(arr, n);
            end = clock();
            break;
        case 7:
            printf("算法: 堆排序\n");
            // 调用堆排序函数
            start = clock();
            heapSort(arr, n);
            end = clock();
            break;
        case 8:
            printf("算法: 归并排序\n");
            // 调用归并排序函数
            start = clock();
            mergeSort(arr, 0, n-1);
            end = clock();
            break;
        default:
            printf("无效的算法类型。\n");
            return;
    }

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("耗时: %f 秒\n", cpu_time_used);
    printf("\n");
}

int main() {
    // 设置常量
    const int numAlgorithms = 8;
    const int numDataSets = 5;
    const int dataLengths[] = {10000, 20000, 30000, 40000, 50000};

    int arr[50000];

    // 选择排序算法
    int algorithmType;
    do {
        printf("===== 排序算法比较 =====\n");
        printf("可用的算法:\n");
        printf("1. 直接插入排序\n");
        printf("2. 折半插入排序\n");
        printf("3. 希尔排序\n");
        printf("4. 冒泡排序\n");
        printf("5. 快速排序\n");
        printf("6. 简单选择排序\n");
        printf("7. 堆排序\n");
        printf("8. 归并排序\n");
        printf("0. 退出\n");
        printf("请输入算法类型 (0-%d): ", numAlgorithms);
        scanf("%d", &algorithmType);

        if (algorithmType == 0) {
            break;
        }

        if (algorithmType < 1 || algorithmType > numAlgorithms) {
            printf("无效的算法类型，请重试。\n");
            continue;
        }

        printf("测试算法 %d\n\n", algorithmType);

        for (int i = 0; i < numDataSets; i++) {
            int n = dataLengths[i];
            printf("数据集 %d\n", i + 1);

            // 生成随机数组
            generateRandomArray(arr, n);

            // 测试排序算法性能
            testSortingAlgorithm(algorithmType, arr, n);
        }

    } while (1);

    return 0;
}
