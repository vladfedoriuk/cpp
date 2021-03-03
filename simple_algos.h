#pragma once
#include<iostream>
void bubble_sort(int* a, std::size_t n);
void insertion_sort(int* a, std::size_t n);
void print(int* a, std::size_t n);
void selection_sort(int* a, std::size_t n);
void selection_sort_minmax(int* a, const std::size_t n);
void counting_sort(int* a, const std::size_t n);
void merge_sort(int* a, int left, int right);

