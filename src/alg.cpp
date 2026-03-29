// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int leftCount = 1;
                int rightCount = 1;
                while (left + leftCount < right &&
                       arr[left + leftCount] == arr[left]) {
                    leftCount++;
                }
                while (right - rightCount > left &&
                       arr[right - rightCount] == arr[right]) {
                    rightCount++;
                }
                count += leftCount * rightCount;
                left += leftCount;
                right -= rightCount;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        int pos = binarySearch(arr, i + 1, len - 1, target);
        if (pos != -1) {
            count++;
            int j = pos + 1;
            while (j < len && arr[j] == target) {
                count++;
                j++;
            }
            j = pos - 1;
            while (j > i && arr[j] == target) {
                count++;
                j--;
            }
        }
    }
    return count;
}
