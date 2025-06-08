// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            int leftVal = arr[left], rightVal = arr[right];
            int leftCount = 0, rightCount = 0;

            while (left < right && arr[left] == leftVal) {
                ++leftCount;
                ++left;
            }
            while (right >= left && arr[right] == rightVal) {
                ++rightCount;
                --right;
            }

            if (leftVal == rightVal) {
                count += (leftCount * (leftCount - 1)) / 2;
            } else {
                count += leftCount * rightCount;
            }
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }

    return count;
}

int countOccurrences(int *arr, int start, int end, int target) {
    int left = start, right = end;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    int first = left;

    left = start, right = end;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    int last = right;

    if (first <= last) {
        return last - first + 1;
    } else {
        return 0;
    }
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int complement = value - arr[i];
        int occurrences = countOccurrences(arr, i + 1, len - 1, complement);
        count += occurrences;
    }
    return count;
}
