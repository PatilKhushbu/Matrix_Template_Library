#include <iostream>
#include "MatOp.h"

using namespace std;


template <typename T>
int func() {
    int option = 0;
    do {
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        cout << "Choose from one of the following matrix operations." << endl;
        cout << "1. Transpose of a matrix" << endl;
        cout << "2. Finding a sub-matrix" << endl;
        cout << "3. Addtion of two matrices" << endl;
        cout << "4. Effective Multiplication of 3 matrices" << endl;
        cout << "Press Any Key For Exit..." << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        cin >> option;

        if(option == 1) {
        	
            MatOp<T> Operand = MatOp<T>::InputFunction('A');
            MatOp<T> result = Operand.MatrixTranspose();
            
            cout << "\nTranspose of given matrix is: " << endl;
            result.RowTraversal();
            
        } else if(option == 2) {
        	
            int mrows, ncols;
			MatOp<T> Operand = MatOp<T>::InputFunction('A');
           
            cout << "\nSub-matrix row size: ";
			cin >> mrows;
            cout << "sub-matrix col-size: ";
			cin >> ncols;
            
			MatOp<T> result = Operand.SubMatrixOperation(mrows, ncols);
            cout << "\nResultant Sub-matrix is : " << endl;
            result.RowTraversal();
            
        } else if(option == 3) {
        	
            MatOp<T> Operand1 = MatOp<T>::InputFunction('A');
            MatOp<T> Operand2 = MatOp<T>::InputFunction('B');
            
            MatOp<T> result = MatOp<T>::MatrixAddition( Operand1, Operand2);
            cout << "\nAddition of given two matrices is: " << endl;
            result.RowTraversal();
            
        } else if(option == 4) {
        	
            MatOp<T> Operand1 = MatOp<T>::InputFunction('A');
            MatOp<T> Operand2 = MatOp<T>::InputFunction('B');
            MatOp<T> Operand3 = MatOp<T>::InputFunction('C');
            
            MatOp<T> result = MatOp<T>::MatrixMultiplicationFor3(Operand1, Operand2, Operand3);
            cout << "\nMultiplication of given three matrrices is: " << endl;
            result.RowTraversal();
        }
        else{
        	break;	
		}
    } while(option);
}

int main() {
    return func<int>();
}

