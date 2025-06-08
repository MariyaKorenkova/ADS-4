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
  int right = len - 1;

  while (right >= 0) {
    if (arr[right] <= value) {
      break;
    }
    right--;
  }

  int left = 0;
  while (left < right) {
    int current = right;
    while (current > left) {
      if (arr[left] + arr[current] == value) {
        cnt += 1;
      }
      current--;
    }
    left++;
  }

  return cnt;
}

int countPairs3(int* arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len; ++i) {
    int first = -1;
    int left = i + 1;
    int right = len - 1;
    int target = value - arr[i];

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
