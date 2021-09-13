
#include <iostream>
#include <fstream>
using namespace std;
template<class T>
class Matrix
{

private:
    T **arr;
    int rows;
    int cols;
public:
//constructor 
    Matrix(int r = 4, int c = 4): rows(r), cols(c)
    {
        arr = new T*[r];
        for(int i = 0; i < r; ++i)
           { arr[i] = new T[c];}

         
    }
 //copy   
    Matrix(const Matrix &rhs)
    {rows = rhs.rows;
    cols = rhs.cols;

         arr = new T*[rows];
        for(int i = 0; i < rows; ++i)
           { arr[i] = new T[cols];}

       for(int i =0; i< rhs.rows;i++)
       {
           for(int k=0;k<rhs.cols;k++)
           {
               this->arr[i][k]=rhs.arr[i][k];
           }
       } 
       

    }
    
//assignment   
    Matrix operator=(const Matrix &rhs)
    {
        //check size; if not match delete structure and then create 
        if(&rhs == this)
        {
            return *this;

        }
        if((rhs.rows!= rows)||(rhs.cols!= cols))
        {
            //delete 
            for(int i =0; i<rows;i++)
        {
            delete arr[i];
        }
        delete []arr;
        rows = rhs.rows;
        cols = rhs.cols;

        arr = new T*[rows];
        for(int i = 0; i < rows; ++i)
           { arr[i] = new T[cols];}
        
        }
        
        for(int i =0; i<rows;i++)
        {
            for(int k =0; k<cols;k++)
            {
                this->arr[i][k]=rhs.arr[i][k];
            }
        }
        return (*this);
        


    }





//check if equal    
    bool operator == (const Matrix& rhs)
    {
        
        if(this->rows == rhs.rows && this->cols==rhs.cols)
        {

            for(int i =0;i<rhs.rows;i++)
                {
                    for(int j =0;j<rhs.cols;j++)
                    {
                        if(this->arr[i][j]!=rhs.arr[i][j])
                        {return false;}
                    }
                }
                return true;
        }

    

       
    }
    Matrix operator += (const Matrix& rhs)
    {   if((rhs.rows!= rows)||(rhs.cols!= cols))
        {
            cout<<"size of Matries are not equal !!"<<endl;
            exit(1);
        }
        
        for(int i =0;i<rhs.rows;i++)
        {
            for(int j =0;j<rhs.cols;j++)
        {
            arr[i][j]+=rhs.arr[i][j];

        }
        }
        return *this;

    }
    
    Matrix operator -= (const Matrix& rhs)
    {
         if((rhs.rows!= rows)||(rhs.cols!= cols))
        {
            cout<<"size of Matries are not equal !!"<<endl;
            exit(2);
        }
       for(int i =0;i<rhs.rows;i++)
        {
            for(int j =0;j<rhs.cols;j++)
        {
            arr[i][j]-=rhs.arr[i][j];

        }
        }
        return *this;
    }

    
    friend Matrix operator + (const Matrix& m1, const Matrix& m2)
    {
         if((m1.rows!= m2.rows)||(m1.cols!= m2.cols))
        {
            cout<<"size of Matrix 1 is not equal to Matrix 2 !!"<<endl;
            exit(3);
        }
        Matrix result(m1.rows,m1.cols);
        for(int i =0;i<m1.rows;i++)
        {
            for(int j =0;j<m1.cols;j++)
        {
            result.arr[i][j]=m1.arr[i][j]+m2.arr[i][j];

        }
        }
        return result;
       
    }
    
    friend Matrix operator - (const Matrix& m1, const Matrix& m2)
    {
        if((m1.rows!= m2.rows)||(m1.cols!= m2.cols))
        {
            cout<<"size of Matrix 1 is not equal to Matrix 2 !!"<<endl;
            exit(4);
        }
       Matrix result(m1.rows,m1.cols);
        for(int i =0;i<m1.rows;i++)
        {
            for(int j =0;j<m1.cols;j++)
        {
            result.arr[i][j]=m1.arr[i][j]-m2.arr[i][j];

        }
        }
        return result;
    }

    
    friend ostream& operator<<(ostream& outs, const Matrix& rhs)
    {
        for(int i=0;i<rhs.rows;i++)
        {
            for(int j=0;j<rhs.cols;j++)
            {
                outs<<rhs.arr[i][j]<<" ";
            } 
            outs<<endl;
        }
        return outs;
    }
   
    friend istream& operator>>(istream& ins, Matrix& rhs)
    {
       
       for(int i=0;i<rhs.rows;i++)
        {
            for(int j=0;j<rhs.cols;j++)
            {
                ins>>rhs.arr[i][j];
            } 
           
        }
        return ins;
    }


    
    T& operator () (const int r_index, const int c_index)
    {
       if(r_index<0|| r_index>=rows || c_index<0 || c_index>=cols)
       {
           cout<<"size mismatch!!"<<endl;
           exit(3);
       }
        return arr[r_index][c_index];
       
    }
    
    const T& operator () (const int r_index, const int c_index) const
    {
           if(r_index<0|| r_index>=rows || c_index<0 || c_index>=cols)
       {
           cout<<"size mismatch!!"<<endl;
           exit(3);
       }
        return arr[r_index][c_index];
         
    }


     Matrix<T> operator++(){       // Pre increment.
       
       for(int i =0;i<rows;i++)
       {
           for(int k =0; k<cols;k++)
           {
               ++(arr[i][k]);
           }
       }
        return (*this);
    };


    Matrix operator++(int)   //post increment
    {
        Matrix temp = *this;
        for(int i =0;i<rows;i++)
       {
           for(int k =0; k<cols;k++)
           {
              this->arr[i][k]=this->arr[i][k]+1 ;
           }
       }
        return (temp);
      
    }
    ~Matrix()
    {
        for(int i =0; i<rows;i++)
        {
            delete arr[i];
        }
        delete []arr;
    }
    void teamScoresCalculator()
    {

        for(int i=0; i<rows;i++)
        {   int team1=0 , team2 =0 ;
            for(int j=0;j<cols;j++)
            {
                if(arr[i][j]> arr[j][i])
                {
                    team1 = team1+3;
                }
                if(arr[i][j]<arr[j][i])
                {
                    team2 = team2+3;
                }
                  if( i!=j && arr[i][j]==arr[j][i])
                {
                    team2 ++;
                    team1++;
                }

            }
            cout<< "team "<<i <<" = "<< team1<<endl;
        }
    }
  
    
    
    
};


//input.txt
// 0 3 2 4 1 2 4 3 5 1
// 2 0 3 2 6 4 2 1 0 4
// 1 3 0 2 4 3 6 1 3 0
// 2 4 1 0 5 2 1 2 0 2
// 3 5 6 2 0 5 4 2 3 0
// 4 3 2 5 1 0 5 3 2 3
// 2 5 3 1 4 2 0 3 2 1
// 4 3 1 5 3 2 3 0 5 2
// 4 3 5 2 1 5 4 2 0 3
// 0 2 1 3 4 2 1 4 2 0


int main()
{
Matrix <int> R(10,10);
ifstream in("input.txt");
    if(in.fail())
    {
        cout<<"File cannot be opened!!"<<endl;
        exit(1);
    }
    in>>R;
    cout<< R <<endl;
    R.teamScoresCalculator();

    return 0;
}


// int main() {

//     Matrix<int> a(2, 2), b(2, 2);
//     cout << "Please enter the content of the first Matrix (A):\n";
//     cin >> a;
//     cout << "Please enter the content of the second Matrix (B):\n";
//     cin >> b;
//     cout << "Printing A and B using the << operator :\n";
//     cout << "A \n" << a << "B \n" << b;


//     cout << "\nTesting Copy Constructor Matrix d = a = :\n";
//     Matrix<int> d = a;
//     cout << d << endl;


//     cout << "Testing = operator, Matrix E; E = B;\n";
//     Matrix<int> e;
//     e = b;
//     cout << "E before changing the value of B :\n";
//     cout << e << endl;


//     //Testing addition “ + ” and subtraction “ - “ operators.
//     //Testing addition assignment “ += ” and subtraction assignment “ - = ” operators.
//     cout << "Testing B + A = :\n" << b + a;
//     cout << "Testing B - A = :\n" << b - a;
//     cout << endl;

//     cout << "Testing E+=B = :\n";
//     e += b;
//     cout << e;

//     cout << "Testing E-=B = :\n";
//     e -= b;
//     cout << e << endl;

//     //Testing comparison operator “ = “
//     cout << "Testing A == A = " << (a == a) << endl;
//     cout << "Testing A == B = " << (a == b) << endl;

//     //Testing operator ()
//     cout << "Testing cout << A[index] \n";
//     int index1, index2;
//     cout << "Enter row index : ";
//     cin >> index1;
//     cout << "Enter column index : ";
//     cin >> index2;
//     cout << "A[" << index1 << "," << index2 << "] = " << a(index1, index2) << endl;
//     cout << "Enter new value : ";
//     int value;
//     cin >> value;
//     a(index1, index2) = value;
//     cout << "A[" << index1 << "," << index2 << "] = " << a(index1, index2) << endl;
//     cout << "New values of a : \n" << a;
    
//     cout<<"Post increment A:"<<endl<<(a ++) <<endl;
//     cout<<"Pre increment A:"<<endl<<(++a)<<endl;
   
    
    
    
//     return 0;
// }



