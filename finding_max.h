#pragma once
#include<utility>
#include<vector>
std::pair<int, int> find_elements(int* a, int* b, int n, int m, int sum);
int max_sum_of_segments(int a[], int n);
int max_sum_of_segments_recursive(int a[], int l, int r);
int find_majority_element(int a[], int n);
int max_len_of_segments(int a[], int n);
int max_rectangle(int** a, int n, int m);
int max_rectangle_brute_force(int** a, int n, int m);
