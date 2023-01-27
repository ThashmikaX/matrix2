#include "cMatrix.h"

cMatrix::cMatrix()
{
	// default constructor
	elm = NULL;
	r = 0;
	c = 0;
	name = "NoName";
}

cMatrix::cMatrix(double data[], int rows, int cols, string argname)
{
	if (rows == 0 || cols == 0)
	{
		name = "NoName";
		elm = NULL;
	}
	else
	{
		r = rows;
		c = cols;
		elm = new double[r *c];
		name = argname;
		for (int i = 0; i < r * c; ++i)
			*
			(elm + i) = data[i];
	}
}

cMatrix::~cMatrix()
{
	// destructor
	if (elm != NULL)
		delete[] elm;
}

// copy constructor
cMatrix::cMatrix(const cMatrix &other)
{

	r = other.r;
	c = other.c;
	name = other.name;
	if (other.elm == NULL)
		elm = NULL;
	else
	{
		elm = new double[r *c];
		for (int i = 0; i < r * c; ++i)
			*
			(elm + i) = *(other.elm + i);
	}
}

// assignment operator
cMatrix &cMatrix::operator=(const cMatrix &other)
{

	if (this == &other)
		return * this;

	if (elm != NULL)
		delete[] elm;
	r = other.r;
	c = other.c;
	name = other.name;
	if (other.elm == NULL)
		elm = NULL;
	else
	{
		elm = new double[r *c];
		for (int i = 0; i < r * c; ++i)
			*
			(elm + i) = *(other.elm + i);
	}

	return * this;
}

// operator for matrix addition
cMatrix cMatrix::operator+(const cMatrix &other)
{

	if (r != other.r || c != other.c)
	{
		cout << "Error: matrices have different dimensions." << endl;
		return cMatrix();
	}

	double *data = new double[r *c];
	for (int i = 0; i < r * c; ++i)
		data[i] = *(elm + i) + *(other.elm + i);
	return cMatrix(data, r, c, "SumMatrix :\n");
}

// operator for matrix subtraction
cMatrix cMatrix::operator-(const cMatrix &other)
	{

		if (r != other.r || c != other.c)
		{
			cout << "Error: matrices have different dimensions." << endl;
			return cMatrix();
		}

		double *data = new double[r *c];
		for (int i = 0; i < r * c; ++i)
		{
			data[i] = *(elm + i) - *(other.elm + i);
		}
		return cMatrix(data, r, c, "DiffMatrix :\n");
		}


// operator for matrix multiplication
cMatrix cMatrix::operator*(const cMatrix &other)
		{
			if (c != other.r)
			{
				cout << "Error: matrices have incompatible dimensions." << endl;
				return cMatrix();
			}

			double *data = new double[r *other.c];
			for (int i = 0; i < r; ++i)
				for (int j = 0; j < other.c; ++j)
				{ 		*(data + j + i *other.c) = 0;
					for (int k = 0; k < c; ++k)
						*
						(data + j + i *other.c) += *(elm + k + i *c) * *(other.elm + j + k *other.c);
				}

			return cMatrix(data, r, other.c, "MulMatrix :\n");
		}


// operator for matrix transpose
cMatrix cMatrix::operator^(int x)
		{
			double *data = new double[r *c];
			for (int i = 0; i < r; ++i)
				for (int j = 0; j < c; ++j)
					*
					(data + i + j *r) = *(elm + j + i *c);
			return cMatrix(data, c, r, "TransposeMatrix :\n");
		}

		bool cMatrix::operator==(const cMatrix &other)
		{
			// operator for equality comparison
			if (r != other.r || c != other.c)
				return false;
			for (int i = 0; i < r * c; ++i)
				if (*(elm + i) != *(other.elm + i))
					return false;
			return true;
		}

		bool cMatrix::operator!=(const cMatrix &other)
		{
			// operator for inequality comparison
			return !(*this == other);
		}

		void cMatrix::show()
		{
			cout << endl;
			if (elm == NULL)
				cout << "Null matrix";
			else
			{
				cout << name << "\t";
				for (int i = 0; i < r; ++i)
				{
					for (int j = 0; j < c; ++j)
						cout << *(elm + j + i *c) << "\t";
					cout << endl <<
						"\t";
				}
			}
		}

		int main()
        {
            // initialize variable
            int n;
            double *data1, *data2;
            string name1, name2;


            cout  << "Enter the dimension of the matrices: ";
            cin >> n;

            data1 = new double[n * n];
            cout << "Enter the elements of the first matrix: " << endl;
            for (int i = 0; i < n * n; ++i)
                cin >> *(data1 + i);
            cout << "Enter the name of the first matrix: ";
            cin >> name1;

            data2 = new double[n * n];
            cout << "Enter the elements of the second matrix: " << endl;
            for (int i = 0; i < n * n; ++i)
                cin >> *(data2 + i);
            cout << "Enter the name of the second matrix: ";
            cin >>name2;

            cMatrix mat1(data1, n, n, name1);
            cMatrix mat2(data2, n, n, name2);

            // example of chaining operators
            mat1.show();
            mat2.show();
            (mat1 + mat2).show();
            (mat1 - mat2).show();
            (mat1 * mat2).show();
            (mat1 ^ 1).show();
            (mat2 ^ 1).show();
            (mat1 == mat2 ? cout << "mat1 and mat2 are equal" : cout << "mat1 and mat2 are not equal") << endl;
            (mat1 != mat2 ? cout << "mat1 and mat2 are not equal" : cout << "mat1 and mat2 are equal") << endl;

            return 0;
        }

