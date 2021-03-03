#include"finding_max.h"
#include<iostream>
#include<algorithm>
#include<utility>
#include<exception>
#include<stack>

struct el {
	int data;
	char arr;
};
 std::pair<int, int> find_elements(int* a, int* b, int n, int m, int sum) {
	int i, j;
	std::sort(a, a + n);
	std::sort(b, b + m);
	std::cout << std::endl;
	el* c = new el[n + m];
	i = 0, j = 0;
	int k;
	for (k = 0; i < n && j < m; k++) {
		if (a[i] <= b[j]) {
			c[k].data = a[i++];
			c[k].arr = 'a';
		}
		else {
			c[k].data = b[j++];
			c[k].arr = 'b';
		}
	}

	while (i < n) {
		c[k++].data = a[i++];
		c[k-1].arr = 'a';
	}

	while (j < m) {
		c[k++].data = b[j++];
		c[k - 1].arr = 'b';
	}
	i = 0, j = n+m-1;
	while (true) {
		if (c[i].data + c[j].data < sum) i++;
		if (c[i].data + c[j].data > sum) j--;
		if (c[i].data + c[j].data == sum) {
			if(c[i].arr == 'a' & c[j].arr =='b')  return std::make_pair(c[i].data, c[j].data);
			if(c[j].arr == 'a' & c[i].arr == 'b')  return std::make_pair(c[j].data, c[i].data);
			i++;
		}
		if (i - j == n+m-1) break;
	}
	return std::make_pair(0, 0);
 };


 int max_sum_of_segments(int a[], int n){
	 int max_so_far = INT_MIN, max_ending_here = 0;
	 for (int i = 0; i < n; i++)
	 {
		 max_ending_here = max_ending_here + a[i];
		 if (max_so_far < max_ending_here)
			 max_so_far = max_ending_here;

		 if (max_ending_here < 0)
			 max_ending_here = 0;
	 }
	 return max_so_far;
 }

 int max2(int a, int b) {
	 return (a > b) ? a : b;
 }

 int max(int a, int b, int c) {
	 return max2(a, max2(b, c));
 }

 int merge_sum(int* a, int l, int m, int r) {
	 int sum = 0;
	 int max_left = INT_MIN;
	 for (int i = m; i >= l; i--) {
		 sum += a[i];
		 if (sum > max_left) {
			 max_left = sum;
		 }
	 }
	 sum = 0;
	 int max_right = INT_MIN;
	 for (int i = m + 1; i <= r; i++) {
		 sum += a[i];
		 if (sum > max_right) {
			 max_right = sum;
		 }
	 }
	 return max_left + max_right;
 }


 int max_sum_of_segments_recursive(int a[], int l, int r) {
	 if (l == r) {
		 return a[l];
	 }

	 int m = (l + r) / 2;
	 return max(max_sum_of_segments_recursive(a, l, m),
		 max_sum_of_segments_recursive(a, m + 1, r),
		 merge_sum(a, l, m, r));

 }

 int find_majority_element(int a[], int n) {
	 int count = 0;
	 int candidate = INT_MIN;
	 for (int i = 0; i < n; i++) {
		 if (count == 0) {
			 candidate = a[i];
			 count++;
		 } else
			 if (a[i] == candidate) {
				 count++;
			 }
			 else {
				 count--;
			 }
	 }
	 count = 0;
	 for (int i = 0; i < n; i++) {
		 if (a[i] == candidate) count++;
	 }
	 if (count > n / 2) return candidate; else throw std::runtime_error("no majority element");
 }

 int max_his(int d[], int m){
	 int res = 0;
	 int curr_res = 0;
	 std::stack<int> st;
	 int top_val;
	 int i=0;
	 while(i<m) {
		 if (st.empty() || d[st.top()] <= d[i])
			 st.push(i++);
		 else { 
			 top_val = d[st.top()];
			 st.pop();
			 curr_res = top_val * i;

			 if (!st.empty())
				 curr_res = top_val *(i - st.top() - 1);
			 res = max2(curr_res, res);
		 }
	 }

	 while (!st.empty()) {
		 top_val = d[st.top()];
		 st.pop();
		 curr_res = top_val*i;
		 if (!st.empty())
			 curr_res = top_val*(i - st.top() - 1);

		 res = max2(curr_res, res);
	 }
	 return res;
 }

 int max_len_of_segments(int a[], int n) {
	 std::sort(a, a + n);
	 int without_last = 0;
	 int with_last = 0;
	 for (int i = 1; i < n; i++) {
		 int without_last_curr = max2(with_last, without_last);
		 int with_last_curr = without_last + a[i] - a[i - 1];
		 without_last = without_last_curr;
		 with_last = with_last_curr;
	 }
	 return max2(without_last, with_last);
 }

 int max_rectangle(int** a, int n, int m) {
	 int res = 0;
	 res = max_his(a[0], m);
	 for (int i = 1; i < n; ++i) {
		 for (int j = 0; j < m; ++j)
			 if (a[i][j] == 1)
				 a[i][j] += a[i - 1][j];
		 res = max2(res, max_his(a[i], m));
	 }
	 return res;
 }

 int max_rectangle_brute_force(int** a, int n, int m) {
	 int max_area = 0;
	 int x, y, x1, y1;
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < m; j++) {
			 x = i, y = j;
			 for (int k = i; k < n; k++) {
				 for (int h = j + 1; h < m; h++) {
					 x1 = k, y1 = h;
					 bool is_zero  = false;
					 for (int g = x; g < x1; g++) {
						 for (int f = y; f < y1; f++) {
							 if (a[g][f] == 0) {
								 is_zero = true;
								 break;
							 }
						 }
					 }
					 if (!is_zero) if (max_area < (x - x1)*(y - y1)) max_area = (x - x1)*(y - y1);
				 }
			 }
		 }
	 }
	 return max_area;
 }

	 


