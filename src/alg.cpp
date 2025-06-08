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
