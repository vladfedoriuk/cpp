#ifndef MATRIX_H_
#define MATRIX_H_
#include<iostream>

	class Matrix {
	private:
		double **A;
		std::size_t m, n;
	public:
		Matrix(std::size_t n, std::size_t m);
		Matrix::Matrix(std::size_t n, std::size_t m, double **a);
		Matrix(const Matrix& b);//konstruktor kopiujacy
		Matrix(Matrix&& a);
		double get_element(std::size_t i, std::size_t j) const;
		void set_element(double a, std::size_t i, std::size_t j);

		~Matrix();
		std::size_t get_m() const {
			return m;
		};
		std::size_t get_n() const {
			return n;
		};
		double ** get_A() {
			return A;
		};
		void set_m(std::size_t m) {
			this->m = m;
		};
		void set_n(std::size_t n) {
			this->n = n;
		};
		friend void swap(Matrix &a, Matrix &b);
		Matrix& operator=(const Matrix& b);
		friend Matrix operator+(const Matrix& a, const Matrix& b);
		Matrix& operator+(const Matrix& b);
		Matrix& operator-(const Matrix& b);
		Matrix& operator-();
		Matrix& operator*(const double a);
		double det(double** Arr, std::size_t size);
		double** minor(double **Arr, std::size_t row, std::size_t column, std::size_t size);
		double determinant();
		double* Matrix::operator[](std::size_t i) const;
		friend Matrix operator*(const double n, Matrix& a);
		friend Matrix operator*(const Matrix&  a, const Matrix& b);
		friend std::ostream& operator<<(std::ostream &os, const Matrix &v);

	};

#endif
