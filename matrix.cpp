#include"matrix.h"
#include<iostream>
#include<cmath>


Matrix::Matrix(std::size_t n, std::size_t m) {
	this->n = n;
	this->m = m;
	A = new double*[n];
	for (std::size_t i = 0; i < n; i++) {
		A[i] = new double[m];
	}
}

Matrix::Matrix(const Matrix& b) {
	std::cout << "Copy c-tor\n";
	n = b.get_n();
	m = b.get_m();
	A = new double*[n];
	for (std::size_t i = 0; i < n; i++) {
		A[i] = new double[m];
	}
	for (std::size_t i = 0; i < n; i++) {
		for (std::size_t j = 0; j < m; j++) {
			A[i][j] = b.get_element(i,j);
		}
	}
}

Matrix::Matrix(std::size_t n, std::size_t m, double **a) {
	this->n = n;
	this->m = m;
	A = new double*[n];
	for (std::size_t i = 0; i < n; i++) {
		A[i] = new double[m];
	}
	for (std::size_t i = 0; i < n; i++) {
		for (std::size_t j = 0; j < m; j++) {
			A[i][j] = a[i][j];
		}
	}
	for (std::size_t i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}

Matrix::Matrix(Matrix&& at):n(at.get_n()), m(at.get_m()), A(at.A) {
	std::cout << "Move c-tor\n";
	at.A = NULL;
	at.set_n(0);
	at.set_m(0);
}
	
double Matrix::get_element(std::size_t i, std::size_t j) const {
	return A[i][j];
}
void Matrix::set_element(double a, std::size_t i, size_t j) {
	A[i][j] = a;
}
Matrix::~Matrix() {
	for (std::size_t i = 0; i < n; i++) {
		delete[] A[i];
	}
	delete[] A;
}


void swap(Matrix &a, Matrix &b) {
	Matrix temp = Matrix(a);
	a = b;
	b = temp;
}


Matrix& Matrix::operator+(const Matrix& b) {
	if (n == b.get_n() && m == b.get_m()) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				A[i][j] = A[i][j] + b.get_element(i, j);
			}
		}
	}
	return *this;
}

Matrix operator+(const Matrix& a, const Matrix& b) {
	if (a.get_n() == b.get_n() && a.get_m() == b.get_m()) {
		std::cout << "Przeladowany przeladowany +\n";
		double**T = new double*[a.get_n()];
		for (std::size_t i = 0; i < a.get_n(); i++) {
			T[i] = new double[a.get_m()];
		}
		for (int i = 0; i < a.get_n(); i++) {
			for (int j = 0; j < a.get_m(); j++) {
				T[i][j] = a.get_element(i,j) + b.get_element(i, j);
			}
		}
		return Matrix(a.get_n(), a.get_m(), T);
	}
	else
		return Matrix(a.get_n(),a.get_m());
}


Matrix& Matrix::operator-(const Matrix& b) {
	if (n == b.get_n() && m == b.get_m()) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				A[i][j] = A[i][j] - b.get_element(i, j);
			}
		}
	}
	return *this;
}


Matrix& Matrix::operator-() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				A[i][j] = -A[i][j];
			}
		}
	return *this;
}


Matrix& Matrix::operator=(const Matrix& b) {
	if (this != &b) {
		for (std::size_t i = 0; i < n; i++) {
			delete[] A[i];
		}
		delete[] A;
		n = b.get_n();
		m = b.get_m();
		A = new double*[n];
		for (std::size_t i = 0; i < n; i++) {
			A[i] = new double[m];
		}
		for (std::size_t i = 0; i < n; i++) {
			for (std::size_t j = 0; j < m; j++) {
				A[i][j] = b.get_element(i, j);
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator*(const double a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = A[i][j] * a;
		}
	}
return *this;
}


Matrix operator*(const Matrix&a, const Matrix& b) {
	Matrix temp = Matrix(a.get_n(), b.get_m());
	if (a.get_m() == b.get_n()) {
		for (std::size_t i = 0; i < a.get_n(); i++) {
			for (std::size_t j = 0; j < b.get_m(); j++) {
				double sum = 0;
				for (std::size_t k = 0; k < a.get_m(); k++)
					sum += a.get_element(i, k)*b.get_element(k,j);
				temp.set_element(sum, i, j);
			}
		}
	}
		return temp;
}

 Matrix operator*(double n, Matrix& a) {
	 return a*n; //a.operator*(n);
}
 double Matrix::determinant() {
	 return det(get_A(), get_n());
 }
 double Matrix::det(double** Arr, std::size_t size) {
	 if (size == 1) {
		 return Arr[0][0];
	 }
	 if (size == 2) {
		 return Arr[0][0] * Arr[1][1] - Arr[1][0] * Arr[0][1];
	 }
	 double result = 0.0;
	 for (std::size_t j = 0; j < size; ++j) {
		 result += Arr[0][j] * pow(-1.0, (2+j))*det(minor(Arr, 0, j, size), size - 1);
	 }
	 return result;
 }

 double** Matrix::minor(double **Arr, std::size_t row, std::size_t column, std::size_t size)
 {
	 double **M = new double *[size - 1];
	 for (std::size_t i = 0; i < size - 1; i++) {
		 M[i] = new double[size - 1];
	 }
	 for (std::size_t i = 0; i < size - 1; i++) {
		 for (std::size_t j = 0; j < size - 1; j++) {
			 if (i < row && j < column) {
				 M[i][j] = Arr[i][j];
			 }
			 if (i < row && j >= column) {
				 M[i][j] = Arr[i][j + 1];
			 }
			 if (i >= row && j < column) {
				 M[i][j] = Arr[i + 1][j];
			 }
			 if (i >= row && j >= column) {
				 M[i][j] = Arr[i + 1][j + 1];
			 }
		 }
	 }
	 return M;
 }

double* Matrix::operator[](std::size_t i) const {
	 return A[i];
 }

std::ostream& operator<<(std::ostream &os, const Matrix &v) {
	if ((v.A)) {
		for (size_t i = 0; i < v.get_n(); i++) {
			for (size_t j = 0; j < v.get_m(); j++) {
				os << v.get_element(i, j) << " ";
			}
			os << std::endl;
		}
		os << std::endl;
	}
	return os;
}