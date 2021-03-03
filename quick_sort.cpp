#include"quick_sortr.h"
#include<stack>
#include<utility>

int partition(int* arr, int l, int r)
{
	int v = arr[r];
	int i = l;
	for (int j = l; j < r; j++) {
		if (arr[j] <= v) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
		}
	}
	int temp = arr[i];
	arr[i] = arr[r];
	arr[r] = temp;
	return i;
}

void qsort_iter(int arr[], int n)
{
	int start = 0;
	int end = n - 1;
	std::stack<std::pair<int, int>> st;
	st.push(std::make_pair(start, end));
	while (!st.empty()) {
		start = st.top().first;
		end = st.top().second;
		st.pop();

		int p = partition(arr, start, end);

		if (p-1 > start) {
			st.push(std::make_pair(start, p - 1));
		}
		if (p+1 < end) {
			st.push(std::make_pair(p + 1, end));
		}
	}
}