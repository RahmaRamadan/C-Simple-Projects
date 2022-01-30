// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
    int data1 [] = {1,0,0,1};
    int data2 [] = {13,233,3,4,5,6,7,9};
    int data3 [] = {10,100,10,100,10,100,10,100};


    matrix mat1, mat2, mat3;
    createMatrix (2, 2, data1, mat1);
    createMatrix (4, 2, data2, mat2);
    createMatrix (4, 2, data3, mat3);
////.........................................
//    cout << (mat1 + mat2) << endl << endl;
//    cout << (mat1 * mat2) << endl << endl ;
//    cout << (mat1 - 2) << endl << endl ;
////......................................
//
//    cout << (mat1 += mat3) <<endl << endl ;
////.......................................
//    --mat2 ;
//    cout << mat2 ;

cout<< isIdentity(mat1) ;

    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];

    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}
//____________________________________________

//Student: Lubna Hassan    ID:20170202
matrix operator+  (matrix mat1, matrix mat2)
{
    matrix mat0;
    int data0 [] = {0,0,0,0,0,0,0,0};
    createMatrix (mat1.row, mat1.col, data0, mat0);   // new matrix to store the answer
    if (mat1.row == mat2.row && mat1.col == mat2.col)
    {
        for (int i = 0; i <mat1.row; i++)
            for (int j = 0; j <mat1.col; j++)
                mat0.data[i][j]= mat1.data[i][j] + mat2.data[i][j];

        return mat0;
    }
    else
    {
        cout<<"Can't add two matrices of unEqual row and columns "<<endl;
    }

}

matrix operator-  (matrix mat1, matrix mat2)
{
    matrix mat0;
    int data0 [] = {0,0,0,0,0,0,0,0};
    createMatrix (mat1.row, mat1.col, data0, mat0);

    if (mat1.row==mat2.row && mat1.col==mat2.col)
    {
        for (int i = 0; i <mat1.row; i++)
            for (int j = 0; j <mat1.col; j++)
                mat0.data[i][j]= mat1.data[i][j] - mat2.data[i][j];

        return mat0 ;
    }
    else
    {
        cout<<"Can't Subtract two matrices of UnEqual row and columns  "<<endl;
    }
}

matrix operator*  (matrix mat1, matrix mat2)
{
    matrix mat0;
    int data0 [] = {0,0,0,0,0,0,0,0};
    createMatrix (mat1.row, mat1.col, data0, mat0);

    if (mat1.col==mat2.row )
    {
        for (int i = 0; i <mat1.row; i++)
            for (int j = 0; j <mat1.col; j++)
                mat0.data[i][j]=mat0.data[i][j]+ (mat1.data[i][j] * mat2.data[j][i]);

        return mat0;
    }
    else
    {
        cout<<" Can't Multiply two matrices [Number of rows != Number of columns]  "<<endl;
    }

}

matrix operator+  (matrix mat1, int scalar)
{
    cout<<"Enter Number : ";
    cin>>scalar;
    matrix mat0;
    int data0 [] = {0,0,0,0,0,0,0,0};
    createMatrix (mat1.col, mat1.row, data0, mat0);   //new matrix to store the answer
    for (int i = 0; i <mat1.row; i++)
        for (int j = 0; j <mat1.col; j++)
            mat0.data[i][j]= mat1.data[i][j] + scalar;

    return mat0;
}

matrix operator-  (matrix mat1, int scalar)
{
    cout<<"Enter Number : ";
    cin>>scalar;
    matrix mat0;
    int data0 [] = {0,0,0,0,0,0,0,0};
    createMatrix (mat1.col, mat1.row, data0, mat0);   //new matrix to store the answer
    for (int i = 0; i <mat1.row; i++)
        for (int j = 0; j <mat1.col; j++)
            mat0.data[i][j]= mat1.data[i][j] - scalar;

    return mat0;
}
//___________________________________________________

// Student: Leena Essam    ID:20170204
matrix operator+= (matrix& mat1, matrix mat3)
{
    if (mat1.row==mat3.row && mat1.col==mat3.col)
    {
        for (int i=0 ; i<mat3.row; i++)
        {
            for (int j=0 ; j<mat3.col; j++)
            {
                mat1.data[i][j]=mat1.data[i][j]+mat3.data[i][j];
            }
        }

    return mat1;

    }

    else
    {
        cout<<"Oops two matrices have different dimensions!"<<endl;
    }

}

matrix operator-= (matrix& mat1, matrix mat3)
{
    if (mat1.row==mat3.row && mat1.col==mat3.col)
    {
        for (int i=0 ; i<mat3.row; i++)
        {
            for (int j=0 ; j<mat3.col; j++)
            {
                if (mat1.data[i][j]>mat3.data[i][j])
                {
                    mat1.data[i][j]=mat1.data[i][j]-mat3.data[i][j];
                }
                else
                {
                    mat1.data[i][j]=mat3.data[i][j]-mat1.data[i][j];
                }
            }
        }
      return mat1 ;
    }
    else
    {
        cout<<"Oops two matrices have different dimensions!"<<endl;
    }
    cout<<endl;

}

matrix operator+= (matrix& mat1,int scalar)
{
    for (int i=0 ; i<mat1.row; i++)
    {
        for (int j=0 ; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]+scalar;
        }
    }
    return mat1;
}


matrix operator-= (matrix& mat1,int scalar)
{
    for (int i=0 ; i<mat1.row; i++)
    {
        for (int j=0 ; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]-scalar;
        }
    }
    return mat1;
}


void operator++ (matrix& mat)
{
    for (int i=0 ; i<mat.row; i++)
    {
        for (int j=0 ; j<mat.col; j++)
        {
            mat.data[i][j] = mat.data[i][j]+1;
        }
    }
}

void operator-- (matrix& mat1)
{
    for (int i=0 ; i<mat1.row; i++)
    {
        for (int j=0 ; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]-1;
        }
    }

}
//______________________________________________________

// Student: Amr Magdy mohamed   ID:20170188
bool operator== (matrix mat1, matrix mat2)
{
    for(int i = 0 ; i < mat1.row ;  i++)
    {
        for(int k = 0 ; k < mat1.col ; k++)
        {
            if(mat1.data[i][k] != mat2.data[i][k]) return false ;
        }
    }
    return true ;
}
//---------------------------------------------
bool operator!= (matrix mat1, matrix mat2)
{
    for(int i = 0 ; i < mat1.row ;  i++)
    {
        for(int k = 0 ; k < mat1.col ; k++)
        {
            if(mat1.data[i][k] == mat2.data[i][k]) return false ;
        }

    }
    return true ;
}
//----------------------------------------------
bool isSquare(matrix mat)
{
    if(mat.row == mat.col)
        return true ;

    else
        return false ;



}
//----------------------------------------------
bool isSymetric (matrix mat)
{
// Checking if it is square Matrix or not
    if(mat.row == mat.col)
    {
        for(int i=0 ; i < mat.row ; ++i)
            for(int k=0 ; k < mat.col ; ++k )
                if(mat.data[i][k] != mat.data[k][i])
                    return false ;
        return true ;
    }
    else
    {
        return false ;
    }



}
//--------------------------------------------
bool isIdentity(matrix mat)
{
    if(mat.row == mat.col)
    {


    for(int i=0 ; i < mat.row ; i++){
        if(mat.data[i][i] != 1)return false ;

            }


    for(int i=0 ; i < mat.row ; i++ )
    {
        for(int j=0 ; j < mat.col ; j++)
        {
            if(i == j)
            {
                j++ ;
            }

            if(mat.data[i][j] != 0 && j != mat.col )
            {
                return false ;

            }


        }
    }
    return true ;


    }

}
//----------------------------------------------
matrix transpose(matrix mat)
{

    int rows = mat.row ;
    int cols = mat.col ;
    matrix mat2 ;
    mat2.data = new int *[rows];

    for(int i=0 ; i < rows ; i++)                          // Creating another matrix                                                            // putting previous matrix to the new matrix
        mat2.data[i] = new int [cols] ;


    for(int i=0 ; i< rows ; i++)
    {
        for(int j=0 ; j < cols ; j++ )
        {
            mat2.data[j][i] = mat.data[i][j];
        }
    }

    return mat2 ;
}

istream& operator>> (istream& in, matrix& mat)
{
    int row, col ;
    cout<< "Enter no. of Row :" ;
    cin>> row ;
    cout<<"Enter no. of col: " ;
    cin >> col ;

    for(int i =0; i < row ; i++)
    {
        for(int j = 0; j < col; j++)
        {
            in >> mat.data[i][j];
        }

    }

    return in;
}

ostream& operator<< (ostream& out, matrix mat)
{
    for (int i = 0; i < mat.row; i++){
        for (int j = 0; j <mat.col; j++){

            out << mat.data[i][j] <<" ";
        }
        cout<<endl ;

    }


   return out ;
}








