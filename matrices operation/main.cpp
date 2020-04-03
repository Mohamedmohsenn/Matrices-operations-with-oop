// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Problem 1
// Program: CS213-2018-A2-P1
// Author:  Eng.Mohamed Mohsen / Mahmoud Magdy / Mahmoud Mohamed
// Date:    31 August 2018

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A class to store a matrix
class Matrix
{
private :
    int* data;       // Pointer to 1-D array that will simulate matrix
    int row, col;
public :
    Matrix() //Defult constructor
    {
        row=0;
        col=0;
        data=new int [10000];
    }

    Matrix(int row,int col,int *arr) //Parametrized constructor
    {
        this->row=row;
        this->col=col;
        data=new int[row*col];
        for(int i=0 ; i<row*col ; i++)
            data[i]=arr[i];
    }

    Matrix(const Matrix &mat)//copy constructor
    {
        row=mat.row;
        col=mat.col;
        for(int i=0 ; i<row*col ; i++)
            data[i]=mat.data[i];
    }

    void setRow(int row)
    {
        this->row=row;
    }

    int getRow()
    {
        return row;
    }

    void setCol(int col)
    {
        this->col=col;
    }

    int getCol()
    {
        return col;
    }

    void setData (int *arr)
    {
        for(int i=0 ; i<row*col ; i++)
            data[i]=arr[i];
    }

    Matrix operator+ (const Matrix &mat2)
    {
        for(int i=0 ; i<row*col ; i++)
            data[i]=data[i]+mat2.data[i];
        return Matrix(row,col,data);
    }

    Matrix operator- (const Matrix &mat2)
    {
        for(int i=0 ; i<row*col ; i++)
            data[i]=data[i]-mat2.data[i];
        return Matrix(row,col,data);
    }

    Matrix operator* (const Matrix& mat2)
    {
        int arr_mat4[row*col];
        Matrix mat3(1,col,data);
        Matrix mat4(row,col,arr_mat4);
        int index=0,index3=0;
        if (col == mat2.row)
        {
            for (int i=0; i<row; i++)
            {
                int index2=0,col1=0;
                for(int j=0; j<col; j++)
                {
                    mat3.data[j]=data[index];
                    index++;
                }
                for (int z=0; z<mat2.col; z++)
                {
                    int sum=0;
                    for (int s=0; s<mat2.row; s++)
                    {
                        sum+=mat3.data[s]*mat2.data[index2];
                        index2+=mat2.col;
                    }
                    mat4.data[index3]=sum;
                    index3++;
                    col1++;
                    index2=col1;
                }
            }
        }
        return mat4;
    }

    Matrix operator+ (int scalar)
    {
        for(int i=0; i<row*col; i++)
            data[i]=data[i]+scalar;
        return Matrix (row,col,data);
    }

    Matrix operator- (int scalar)
    {
        for(int i=0; i<row*col; i++)
            data[i]=data[i]-scalar;
        return Matrix(row,col,data);
    }

    Matrix operator* (int scalar)
    {
        for(int i=0; i<row*col; i++)
            data[i]=data[i]*scalar;
        return Matrix(row,col,data);
    }

    Matrix operator+=(const Matrix& mat2)
    {
        for(int i=0 ; i<row*col ; i++)
            data[i]=data[i]+mat2.data[i];
        return Matrix(row,col,data);
    }

    Matrix operator-=(const Matrix& mat2)
    {
        for(int i=0 ; i<row*col ; i++)
            data[i]=data[i]-mat2.data[i];
        return Matrix(row,col,data);
    }

    Matrix operator+=(int scalar)
    {
        for(int i=0 ; i<row*col ; i++)
            data[i]=data[i]+scalar;
        return Matrix(row,col,data);
    }

    Matrix operator-=(int scalar)
    {
        for(int i=0 ; i<row*col ; i++)
            data[i]=data[i]-scalar;
        return Matrix(row,col,data);
    }

    void operator++()
    {
        for(int i=0 ; i<row*col ; i++)
            data[i]++;
    }

    void operator--()
    {
        for(int i=0 ; i<row*col ; i++)
            data[i]--;
    }

    bool operator== (const Matrix& mat)
    {
        if(col==mat.col && row==mat.row)
        {
            for(int i=0 ; i<row*col ; i++)
            {
                if(data[i]!=mat.data[i])
                    return false;
            }
            return true;
        }
        return false;
    }

    bool operator!= (const Matrix& mat)
    {
        if(col==mat.col && row==mat.row)
        {
            for(int i=0; i<row*col; i++)
            {
                if(data[i]!=mat.data[i])
                    return true;
            }
        }
        return false;
    }

    bool isSquare ()
    {
        if(row==col)
            return true;
        return false;
    }

    bool isSymetric ()
    {
        int temp[row][col];
        int x=0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                temp[i][j]=data[x];
                x++;
            }
        }
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(temp[i][j]!=temp[j][i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isIdentity()
    {
        int temp[row][col];
        int x=0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                temp[i][j]=data[x];
                x++;
            }
        }
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(i==j && temp[i][j]!=1)
                    return false;
                else if(i!=j && temp[i][j]!=0)
                    return false;
            }
        }
        return true;
    }

    Matrix transpose()
    {
        int temp[row][col];
        int transposedata[row*col];
        int x=0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                temp[i][j]=data[x];
                x++;
            }
        }
        x=0;
        for(int i=0; i<col; i++)
        {
            for(int j=0; j<row; j++)
            {
                transposedata[x] = temp[j][i];
                x++;
            }
        }
        return Matrix (col,row,transposedata);
    }

    Matrix operator=(const Matrix& mat2)
    {
        row=mat2.row;
        col=mat2.col;
        for(int i=0 ; i<row*col ; i++)
            data[i]=mat2.data[i];
        return Matrix(row,col,data);
    }

    friend istream& operator>>(istream &in,Matrix &m);
    friend ostream& operator<<(ostream &out,const Matrix &m);

};

istream& operator>>(istream &in,Matrix &m)
{
    for(int i=0 ; i<m.row ; i++)
    {
        for(int j=0 ; j<m.col ; j++)
        {
            in>>m.data[i*m.col+j];
        }
    }
    return in;
}

ostream& operator<<(ostream &out,const Matrix &m)
{
    for(int i=0 ; i<m.row ; i++)
    {
        for(int j=0 ; j<m.col ; j++)
        {
            out<<m.data[i*m.col+j]<<" ";
        }
        out<<endl;
    }
    return out;
}

int main()
{
    int arr[]= {1,2,3,4};
    int arr2[]= {1,2,3,4,5,6,7,8,9};
    int arr3[]= {1,2,3,4,5,6,7,8,9};
    Matrix mat(2,2,arr);
    Matrix mat2(3,3,arr2);
    Matrix mat3(3,3,arr3);

    return 0;
}
