/**************************************************************************************************
* Title       - Matrix Operations                                                                 *	
* File        - main.cpp                                                                          *	
* Description - The code performs the below matrix operations -                                   *
*               a. Matrix Transpose                                                               *
*               b. Matrix Multiplication                                                          *
* Author      - Abhik Kumar Dey (akd)                                                             *
* Editor      - Sublime Text / GEdit                                                              *
* System Req  - Operating System - Linux           Windows                                        *
*               Compiler         - g++             Any C++ IDE                                    *
*                                                                                                 *
*                                History                                                          *
* Version               Date                Author          Description                           *
***************************************************************************************************			
* Initial Version       20 Feb, 2020        Abhik Dey       Code to Transpose and Multiply Matrix *
*                                                                                                 *
*                                                                                                 *
**************************************************************************************************/


#include <iostream>
#include <math.h>
using namespace std;


class LinearAlgebraOperations{

private:	
	float** createMatrix(int, int);
	void printMatrix(float **, int, int);
	float** transposeMatrix(float**, int, int);
	float** matrixMultiplication(float **, float **, int, int, int, int);
	float validateMatrixInput(int, int);
	
public:
	friend void performLinearAlgOperation(LinearAlgebraOperations, int );
	int validateInput(string);
};


/**************************************************************************************************
* Function          - validateInput                                                               *	
* Parameters        - inputType - Type - Integer, Takes the input type                            *
* Return            - Valid Input, Type - int                                                     *
* Description       - Validates input                                                             *
* Author            - Abhik Kumar Dey (akd)                                                       *
**************************************************************************************************/
int LinearAlgebraOperations::validateInput(string inputType){
	
	float input;
	
	if (inputType.compare("choice") == 0) {
		
		cout << "Provide 1 or 2 as input: ";
		cin >> input;
	
		while (!cin.good() || (input - floor(input)) > 0 || !(input == 1  || input ==2 )){
			
			cout<< "ERROR::  Incorrect option, should be 1 or 2 \n";
			
			cin.clear();
			cin.ignore(500, '\n');
			
			cout << "\nProvide 1 or 2 as input: ";
			cin >> input;
		
		}		
	}
	else{
		
		cout << "\nEnter the number of " << inputType << " :";	
		cin >> input;

		while (!cin.good() || (input - floor(input)) > 0 || input <= 0){
		
			cout<< "ERROR:: "<< inputType << " is integer data type and should be greater than 0, please enter integer values only\n";
			
			cin.clear();
			cin.ignore(500, '\n');
			
			cout << "\nEnter the number of " << inputType << " :";
			cin >> input;
		
		}
	}

	return (int)input;
}



/**************************************************************************************************
* Function          - performLinearAlgOperation                                                   *	
* Parameters        - mo - Type - Class MatrixOperation , Takes MatrixOperation class object      *	
*                     operationType - Type - Integer, Takes operation type                        *
* Return            - Null                                                                        *
* Description       - Calls required Matrix Operations                                            *
* Author            - Abhik Kumar Dey (akd)                                                       *
**************************************************************************************************/
void performLinearAlgOperation(LinearAlgebraOperations mo, int operationType){	
		
	if (operationType == 1)	{
			cout << "\nTranspose Matrix :" << "\n";
			cout << "--------------------" << "\n";
			float** matrix;
			float** transposeMatrix;
			bool valInputs;
			string rowStr, columnStr;
			int rows, columns;
				
			rows = mo.validateInput("Rows");
			columns = mo.validateInput("Columns");
							
			matrix = mo.createMatrix(rows, columns);
			cout << "Original Matrix:\n"; 
			cout << "--------------------" << "\n";
			mo.printMatrix(matrix, rows, columns);
			
			transposeMatrix = mo.transposeMatrix(matrix, rows, columns);
			cout << "\n\nTransposed Matrix: \n";
			cout << "--------------------" << "\n";
			mo.printMatrix(transposeMatrix, columns, rows);
			cout <<"\n";
	}	
				
	else if (operationType == 2) {
			cout << "\nMultiply Matrix" << "\n";			
			cout << "--------------------" << "\n";
			float** matrix1;
			int rows1;
			int columns1;
			
			float** matrix2;
			int rows2;
			int columns2;

			float** resultMatrix;
			
			rows1 = mo.validateInput("Rows for Matrix1");
			columns1 = mo.validateInput("Columns for Matrix1");			

			rows2 = mo.validateInput("Rows for Matrix2");
			columns2 = mo.validateInput("Columns for Matrix2");
			
			
			if (columns1 == rows2){
			
				cout << "\nMatrix1 Inputs:";
				matrix1 = mo.createMatrix(rows1, columns1);
								
				cout << "\nMatrix2 Inputs:";
				matrix2 = mo.createMatrix(rows2, columns2);
				
				cout << "Matrix 1\n"; 
				cout << "--------------------" << "\n";
				mo.printMatrix(matrix1, rows1, columns1);
				
				cout << "\nMatrix 2\n";
				cout << "--------------------" << "\n"; 
				mo.printMatrix(matrix2, rows2, columns2);
				
				resultMatrix = mo.matrixMultiplication(matrix1, matrix2, rows1, columns1, rows2, columns2);
				
				cout << "\nMultiplication of the above two Matrices are -\n";
				cout << "---------------------------------------------------" << "\n";
                for (int r = 0;r < rows1; r++){
                	for (int c = 0; c < columns2; c++){
                		cout << resultMatrix[r][c] << "\t";
                	}
                	cout << "\n";
            	}
            cout << "\n";

			}
			
			else{
				cout << "Cannot multiply the given matrices. No. of columns of Matrix1 should be equal to number of rows of Matrix 2. \n";
			}
	}
			
	else{
		cout << "Error:: Enter option between 1 and 2 \n";
	}
}

/**************************************************************************************************
* Function          - validateMatrixInput                                                         *	
* Parameters        - row - Type - Integer, Takes No. of Rows of Matrix                           *	
*                     cols - Type - Integer, Takes No. of Columns of Matrix                       *
* Return            - Valid input                                                                 *
* Description       - Validates a Matrix input from user                                          *
* Author            - Abhik Kumar Dey (akd)                                                       *
**************************************************************************************************/
float  LinearAlgebraOperations::validateMatrixInput(int row, int col){
	
	float input;
	cout << "\nEnter column "<< col <<" value for row " << row << " :";
	cin >> input;
	
	while (!cin.good()){
		
		cout<< "ERROR:: " << " No characters allowed\n";
		
		cin.clear();
		cin.ignore(500, '\n');
		
		cout << "\nEnter column "<< col <<" value for row " << row << " :";
		cin >> input;
		
	}
	
	return input;
}


/**************************************************************************************************
* Function          - createMatrix                                                                *	
* Parameters        - row - Type - Integer, Takes No. of Rows of Matrix                           *	
*                     cols - Type - Integer, Takes No. of Columns of Matrix                       *
* Return            - Matrix, Type - Pointer to pointers                                          *
* Description       - Creates a Matrix from user input                                            *
* Author            - Abhik Kumar Dey (akd)                                                       *
**************************************************************************************************/
float** LinearAlgebraOperations::createMatrix(int row, int cols){

		float** mat = new float* [row];

		for (int r = 0; r < row; r++){
			mat[r] = new float[cols];
			for (int c = 0; c < cols; c++){
				mat[r][c] = validateMatrixInput(r+1, c+1);
			}
			cout << "\n";
		}

		return mat;
	}


/**************************************************************************************************
* Function          - printMatrix                                                                 *	
* Parameters        - mat - Type - Pointer to pointers, Takes the matrix as input                 *
*                     row - Type - Integer, Takes No. of Rows of Matrix                           *	
*                     cols - Type - Integer, Takes No. of Columns of Matrix                       *
* Return            - Null                                                                        *
* Description       - Displays Matrix to user                                                     *
* Author            - Abhik Kumar Dey (akd)                                                       *
**************************************************************************************************/
void LinearAlgebraOperations::printMatrix(float **mat, int row, int cols){

	for (int i = 0; i<row; i++){
		for (int j = 0; j<cols; j++){
			cout << mat[i][j] <<"\t";
		}
		cout << "\n";
	}

}

/**************************************************************************************************
* Function          - transposeMatrix                                                             *	
* Parameters        - mat - Type - Pointer to pointers, Takes the matrix as input                 *
*                     row - Type - Integer, Takes No. of Rows of Matrix                           *	
*                     cols - Type - Integer, Takes No. of Columns of Matrix                       *
* Return            - Matrix Type - Pointer to pointers                                           *
* Description       - Transpose a Matrix                                                          *
* Author            - Abhik Kumar Dey (akd)                                                       *
**************************************************************************************************/
float** LinearAlgebraOperations::transposeMatrix(float **mat, int row, int cols){
		
	float **transMatrix = new float* [cols];
		
	for (int i = 0; i < cols; i++ ){
		transMatrix[i] = new float [row];
		for (int j = 0; j < row; j++){
			transMatrix[i][j] = mat[j][i];		
		}
	}

	return transMatrix;
}

/**************************************************************************************************
* Function          - matrixMultiplication                                                        *	
* Parameters        - mat1 - Type - Pointer to pointers, Takes the matrix as inpu                 *
*                     row1 - Type - Integer, Takes No. of Rows of Matrix1                         *	
*                     col1 - Type - Integer, Takes No. of Columns of Matrix1                      *
                      mat2 - Type - Pointer to pointers, Takes the matrix as input                *
*                     row2 - Type - Integer, Takes No. of Rows of Matrix2                         *	
*                     col2 - Type - Integer, Takes No. of Columns of Matrix2                      *
* Description       - Multiply two Matrices                                                       *
* Author            - Abhik Kumar Dey (akd)                                                       *
**************************************************************************************************/
float ** LinearAlgebraOperations::matrixMultiplication(float ** mat1, float ** mat2, int row1, int col1, int row2, int col2){
	
	float ** resultMatrix = new float* [row1];
	for (int i = 0; i< row1; i++){
		resultMatrix[i] = new float [col2];
		for (int j = 0; j < col2; j++){			
			resultMatrix[i][j] = 0;
			for (int k = 0; k < col1; k++){
				resultMatrix[i][j] += mat1[i][k]*mat2[k][j];
			}
		}
	}
	return resultMatrix;
}



/**************************************************************************************************
* Function          - Main Function                                                               *	
* The code starts from here                                                                       *
* Author            - Abhik Kumar Dey (akd)                                                       *
**************************************************************************************************/
int main(){

	int option;
	int rows, columns;
	char cont = 'Y';

	LinearAlgebraOperations matr;

	while (cont == 'Y' || cont == 'y'){
	
		cout << "\n";
		cout << "Enter the Matrix operation you want to perform: \n";
		cout << "1. Transpose a Matrix\t 2. Multiply two Matrices\n";		
		option = matr.validateInput("choice");
		
		performLinearAlgOperation(matr, option);
		
		cout << "Do you wish to continue ? Press Y/y to continue:  ";
		cin >> cont;
		
	}
	
	return 0;
}
