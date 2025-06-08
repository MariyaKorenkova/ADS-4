// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int* arr, int len, int value) {
  int cnt = 0;
  for (int m = 0; m < len - 1; m++) {
    for (int n = m + 1; n < len; ++n) {
      if (arr[m] + arr[n] == value) {
        cnt++;
      }
    }
  }
  return cnt;
}

int countPairs2(int* arr, int len, int value) {
  int cnt = 0;
  int left = 0, right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int leftVal = arr[left], rightVal = arr[right];
      int leftCount = 0, rightCount = 0;

      while (left < right && arr[left] == leftVal) {
        leftCount++;
        left++;
      }

      while (right >= left && arr[right] == rightVal) {
        rightCount++;
        right--;
      }

      if (leftVal == rightVal) {
        cnt += (leftCount * (leftCount - 1)) / 2;
      } else {
        cnt += leftCount * rightCount;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }

  return cnt;
}

int countPairs3(int* arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len - 1; ++i) {
    int target = value - arr[i];
    int first = -1;
    int left = i + 1, right = len - 1;

    while (left <= right) {
      int x = left + (right - left) / 2;
      if (arr[x] >= target) {
        right = x - 1;
        if (arr[x] == target) {
          first = x;
        }
      } else {
        left = x + 1;
      }
    }

    if (first != -1) {
      int last = first;
      left = first;
      right = len - 1;

      while (left <= right) {
        int x = left + (right - left) / 2;
        if (arr[x] <= target) {
          left = x + 1;
          if (arr[x] == target) {
            last = x;
          }
        } else {
          right = x - 1;
        }
      }

      cnt += last - first + 1;
    }
  }
  return cnt;
}

