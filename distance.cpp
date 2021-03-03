#include"heap.hpp"
#include"point.hpp"
#include<random>
#include"finding_max.h"

double smallest_distance(Point<double> p[], int l, int r) {
	if (l == r) {
		return INFINITY;
	}
	else
		if (r > l) {
			if (r - l == 1) {
				return p[l].dist(p[r]);
			}
			else if (r - l > 1) {
				int mid = (l + r) / 2;
				double dl = smallest_distance(p, l, mid);
				double dr = smallest_distance(p, mid, r);
				double d = (dl <= dr) ? dl : dr;
				int l1 = mid;
				int r1 = mid;
				while (l1 >= l && p[mid]['x'] - p[l1]['x'] <= d) l1--;
				while (r1 <= r && p[mid]['x'] - p[r1]['x'] <= d) r1++;

				for (int i = l1; i <= mid; i++) {
					for (int j = mid+1; j <= r1; j++) {
						if (p[i].dist(p[j]) < d) {
							d = p[i].dist(p[j]);
						}
					}
				}
				return d;
			}
		}
}

double brute_force_smallest_distance(Point<double> p[], int n) {
	double d = p[0].dist(p[1]);
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < n; j ++) {
			if ( i!=j && p[i].dist(p[j]) < d) {
				d = p[i].dist(p[j]);
			}
		}
	}
	return d;
}

int merge(int *a, int left, int right, int middle) {
	int i, j, k;
	const int n1 = middle - left + 1;
	const int n2 = right - middle;
	int* L = new int[n1];
	int* R = new int[n2];

	for (i = 0; i < n1; i++) {
		L[i] = a[left + i];
	}

	for (j = 0; j < n2; j++) {
		R[j] = a[middle + j + 1];
	}

	i = 0, j = 0;
	int inversion_num = 0;
	for (k = left; i < n1 && j < n2; k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i++];
		}
		else {
			a[k] = R[j++];
			inversion_num += n1 - i;
		}
	}
	
	while (i < n1) {
		a[k++] = L[i++];
	}

	while (j < n2) {
		a[k++] = R[j++];
	}
	delete[] L;
	delete[] R;
	return inversion_num;
}


int inversion_number(int* a, int left, int right) {
	int middle;
	if (left < right) {
		middle = (left + right) / 2;
		int ra = inversion_number(a, left, middle);
		int rb = inversion_number(a, middle + 1, right);
		int r = merge(a, left, right, middle);
		return r + ra + rb;
	}
	return 0;
}

int brute_force_inversion(int* a, int n) {
	int num = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (a[i] > a[j]) num++;
		}
	}
	return num;
}

int brute_force_max_sum(int* a, int n) {
	int max = INT_MIN;
	for (int i = 0; i < n-1; i++) {
		int max_local = a[i];
		int sum = a[i];
		for (int j = i+1; j < n; j++) {
			sum += a[j];
			if (sum > max_local) {
				max_local = sum ;
			}
		}
		if (max_local > max) max = max_local;
	}
	return max;
}

void genSquare(Point<double> p[], std::size_t n) {
	std::random_device rd;
	std::mt19937 generator(rd());
	std::normal_distribution<double> distribution(0.0, 0.5);
	for (int i = 0; i < n; i++) {
		p[i] = Point<double>(abs(distribution(generator)), abs(distribution(generator)));
		p[i].print();
		std::cout << std::endl;
	}
}

void genRandomPermutation(int* a, int n) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, n-1);
	for (int i = 0; i < n; i++) {
		int k = dis(gen);
		if (k != n - 1) {
			int temp = a[n - 1];
			a[n - 1] = a[k];
			a[k] = temp;
		}
	}
}



int main() {
	Heap<Point<double>> h([](Point<double> p1, Point<double> p2) {return p1['x'] - p2['x']; });
	Point<double> p[50000];
	/*std::size_t n = 0;
	double x, y;
	while (std::cin >> x >> y) {
		p[n++] = Point<double>(x, y);
	}*/
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(2, 25);
	int n = dis(gen);
	genSquare(p, n);

	h.sortIter(p, n);
	for (int i = 0; i < n; i++) {
		p[i].print();
		std::cout<<std::endl;
	}
	double d = smallest_distance(p, 0, n - 1);
	std::cout << "smallest distance= " << d << std::endl;
	std::cout << "smallest_distance brute_force= " << brute_force_smallest_distance(p, n) << std::endl;

	n = dis(gen);
	int* a = new int[n];
	for (int i = 1; i <= n; i++) {
		a[i - 1] = i;
	}
	genRandomPermutation(a, n);
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}

	int b[5] = { 1, 4, 7, 11, 45 };
	int c[7] = { 3, 5, 8, 10, 12, 13, 15 };
	std::pair<int, int> pr = find_elements(b, c, 5, 7, 22);
	std::cout << std::endl;
	std::cout << pr.first << " " << pr.second << std::endl;
	std::cout << "brute_force_inversion= " << brute_force_inversion(a, n) << std::endl;
	std::cout <<"inversion number= "<< inversion_number(a, 0, n-1)<< std::endl;

	int f[9] = {-9, 1, 3, 23, 5, 6, 7 ,-8, -11};
	int max = max_sum_of_segments(f, 9);
	std::cout << "brute_force_max= " << brute_force_max_sum(f, 9)<<std::endl;
	std::cout <<"max= "<< max << std::endl;
	std::cout << "max recursive= " << max_sum_of_segments_recursive(f, 0, 8)<<std::endl;

	int g[10] = { 5, 5, 4, 5, 5, 3, 5, 5 ,6, 5 };
	std::cout << "majority element= " << find_majority_element(g, 10) << std::endl;

	int s[6] = { 1, 3, 4, 6, 7, 10 };
	std::cout << "max segment's lehgth sum= " << max_len_of_segments(s, 6) << std::endl;
	int m;
	std::cout << "Input n and m" << std::endl;
	std::cin >> n >> m;
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> matrix[i][j];
		}
	}
	std::cout<<"res= "<<max_rectangle(matrix, n, m)<<std::endl;
	std::cout << "res_brute_force= " << max_rectangle_brute_force(matrix, n, m) << std::endl;
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	system("pause");
	return 0;
}


/* 
16 16
1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 
0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 0 1 1 1 1 1 1 0 1 1 0 
1 1 1 1 1 0 0 1 1 1 0 1 1 1 0 1 
0 1 1 1 1 1 0 1 1 1 1 1 1 0 1 1 
1 0 0 1 0 0 1 1 1 1 0 0 0 0 1 0 
1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 
1 0 1 1 1 1 0 1 0 1 1 1 1 1 1 1 
1 1 1 0 1 1 1 1 1 1 1 0 0 1 0 1 
1 1 1 0 0 1 0 1 0 1 1 1 1 1 1 1 
1 0 0 0 1 1 1 0 1 0 0 1 1 0 1 1 
1 1 1 0 0 1 1 0 1 1 1 1 1 1 1 1 
1 1 1 0 1 1 0 1 0 0 1 1 1 1 1 0 
0 1 0 0 1 1 1 0 0 1 1 1 1 1 0 1 
0 1 1 1 1 1 1 1 1 0 1 1 1 0 0 1 
1 0 1 1 1 0 0 1 1 1 1 1 1 1 1 1
*/