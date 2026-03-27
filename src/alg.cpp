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
            int leftCount = 1;
            int rightCount = 1;
            
            while (left + leftCount < right && arr[left + leftCount] == arr[left]) {
                leftCount++;
            }
            while (right - rightCount > left && arr[right - rightCount] == arr[right]) {
                rightCount++;
            }
            
            count += leftCount * rightCount;
            left += leftCount;
            right -= rightCount;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                int first = mid;
                while (first > i + 1 && arr[first - 1] == target) {
                    first--;
                }
                int last = mid;
                while (last < len - 1 && arr[last + 1] == target) {
                    last++;
                }
                count += (last - first + 1);
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count;
}
