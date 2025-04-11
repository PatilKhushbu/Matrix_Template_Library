#include <iostream>

using namespace std;


// Defining a generic array which will later be used in main for object instantiation
template <typename T>
class MatOp
{

public:
	int mrows;
	int ncols;
	T ***ObjMatrix;
	
	
	//MatOp Constructors for different purposes
	MatOp() {}

	MatOp(int m, int n)
	{
		mrows = m;
		ncols = n;
		ObjMatrix = new T **[mrows];
		for (int x = 0; x < mrows; ++x) {
			ObjMatrix[x] = new T*[ncols];
			for(int y = 0; y < ncols; y++) {
            	ObjMatrix[x][y] = new T();
        	}
		}
	}

/*
	 This constructor is specifically for SubMatrix operation in which you can pass 
	 MatOp class as third argument in function to make it work as object class.
	
*/
	MatOp(int m, int n, T ***result)
	{
		ObjMatrix = result;
		mrows = m;
		ncols = n;
	}
	
	//Setter function for Matrix Data that requires matrix coordinates for value insertion
	void insertat(int m, int n, T data)
	{
		*ObjMatrix[m][n] = data;
	}

	// Function to perform transpose of a given matrix 
	MatOp MatrixTranspose()
	{
		/*
		We need result matrix to return the answer of given function. Thats why we need result variable.
		Apart from that we are just replcing column with row and row with column in the matrix index.
		*/
		
		int m = ncols, n = mrows;
		
		MatOp<T> result(m, n);

		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++)
				result.ObjMatrix[x][y] = ObjMatrix[y][x];
		return result;
	}

	/* This function basically creates deep copy of the reference object.
		That means there are more than one matrix objects holding same data.
	*/
	MatOp DeepCopy()
	{
		MatOp<T> result(mrows, ncols);
		for (int x = 0; x < mrows; x++)
			for (int y = 0; y < ncols; y++)
				result.insertat(x, y, *ObjMatrix[x][y]);
		return result;
	}

	/*
	SubMatrixOperation function just does the work of taking out the chopped portion of matrix. 
	It will keep the desired rows and cols into matrix and discard the remaining data.
	*/
	MatOp SubMatrixOperation(int m, int n)
	{
		MatOp<T> result(m, n, ObjMatrix);
		return result;
	}

	/*
		Matrix addition also needs a resultant matrix which stores addition of both operands.
		Addition process follows adding values at the same indexes in the given operands
		For addition operation to be successful, both operands and resultant matrix has to be identical in size.
	*/
	static MatOp<T> MatrixAddition(MatOp<T> Operand1, MatOp<T> Operand2)
	{
		
		MatOp<T> result(Operand1.mrows, Operand1.ncols);

		for (int x = 0; x < Operand1.mrows; x++)
			for (int y = 0; y < Operand1.ncols; y++)
			{
				result.insertat(x, y, (Operand1.fetchfrom(x, y) + Operand2.fetchfrom(x, y)));
			}
		return result;
	}

	/*
		Matrix multiplication is a process where one operand's row elements are 
		multiplied with another operands column elements respectively and summerized addition is stored 
		in resultant matrix's position. Martrix Multiplication can only happen if row of one operand is matched with column of 
		other operand to be multiplied.
	*/
	static MatOp<T> MatrixMultiplication(MatOp<T> Operand1, MatOp<T> Operand2)
	{
		if (Operand1.ncols != Operand2.mrows)
		{
			cout << "Matrix multiplication not possible!" << endl;
			MatOp<T> result(0, 0);
			return result;
		}
		else
		{
			MatOp<T> result(Operand1.mrows, Operand2.ncols);
			for (int x = 0; x < Operand1.mrows; x++)
				for (int y = 0; y < Operand2.ncols; y++)
					for (int z = 0; z < Operand1.ncols; z++)
						result.insertat(x, y, result.fetchfrom(x, y) + Operand1.fetchfrom(x, z) * Operand2.fetchfrom(z, y));
			return result;
		}
	}

	/* Function for multiplyig more than two matrices, specifically 3.
		Here it takes care of choosing least multiplication 
		possible while performing overall matrix multiplication.
		It is necessary to check for fundamental matrix rule following before processing further.
	*/
	static MatOp<T> MatrixMultiplicationFor3(MatOp<T> Operand1, MatOp<T> Operand2, MatOp<T> Operand3)
	{
		if (Operand1.ncols == Operand2.mrows && Operand2.ncols == Operand3.mrows)
		{
			MatOp<T> intresult;
			MatOp<T> result;
			if (Operand1.ncols >= Operand2.ncols)
			{
				cout << "First Two Operand's Multiplication'" << endl;
				intresult = MatOp<T>::MatrixMultiplication(Operand1, Operand2);
				result = MatOp<T>::MatrixMultiplication(intresult, Operand3);
			}
			else
			{
				cout << "Multiplication of Second & Third Operand" << endl;
				intresult = MatOp<T>::MatrixMultiplication(Operand2, Operand3);
				
				result = MatOp<T>::MatrixMultiplication(Operand1, intresult);
			}
			return result;
		}
		else
		{
			cout << "Matrix multiplication not possible!" << endl;
			MatOp<T> result(0, 0);
			return result;
		}
	}

	//Getter function to get the particular index value from given matrix
	T fetchfrom(int m, int n)
	{
		return *ObjMatrix[m][n];
	}

	//Row wise traversal of a matrix. Traversal means accessing matrix values one by one in order.
	void RowTraversal()
	{
		for (int x = 0; x < mrows; x++)
		{
			cout << "[ ";
			for (int y = 0; y < ncols; y++)
			{
				cout << *ObjMatrix[x][y];
				
				if(y!= ncols-1)
					cout << ", ";
			}
			cout << " ]" << endl;
		}
		cout << endl;
	}

	//Column wise traversal of a matrix. Traversal means accessing matrix values one by one in order.
	void ColTraversal()
	{
		for (int y = 0; y < ncols; y++)
		{
			cout << "[ ";
			for (int x = 0; x < mrows; x++)
			{
				cout << *ObjMatrix[x][y];
				
				if(y!= ncols-1)
					cout << ", ";
			}
			cout << " ]" << endl;
		}
		cout << endl;
	}
	
	// Frequently used input function to get matrix elements and related inputs
	static MatOp<T> InputFunction(char MatName)
	{
		int mrows, ncols;
		T input;
		cout << "\nEnter Details of Matrix: ";
		cout << "\n No of Rows for Matrix " << MatName << ": ";
		cin >> mrows;
		cout << "\n No of Cols for Matrix " << MatName << ": ";
		cin >> ncols;

		MatOp<T> result(mrows, ncols);
		cout << "\n Enter Matrix "<< MatName << "'s Elements: \n";
		for (int x = 0; x < result.mrows; x++)
		{
			for (int y = 0; y < result.ncols; y++)
			{
				cout << MatName << "[" << x << "]" << "[" << y << "]: ";
				cin >> input;
				result.insertat(x, y, input);
			}
		}
		return result;
	}
};

