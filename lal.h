#define LAL_H_
using namespace std;
class Matrix {

public:
 
   Matrix(double* , int, int);
   void print(void);
   ~Matrix(); 
  void mRandom(void);
    int getrows( );
      int getcols ( );
      double* getentries ( );
   Matrix operator+(const Matrix& m);
   Matrix operator-(const Matrix& m);
   Matrix operator*(const Matrix& m);
   bool operator==(const Matrix& m);
 
    friend void vRandom(void);   
    friend void NormPrint(void);
protected: 
  double *entries;
  int rows;
  int cols;
 
};

class Vector : public Matrix{
	public:

   Vector(double* , int);
   void vRandom(void);  
  void NormPrint(void);
   void print(void);
   ~Vector();  
    Vector operator+(const Vector& v);
    Vector operator-(const Vector& v);
    Vector operator*(const Vector& v);
     bool operator==(const Vector& v);
   void operator++(int);
	void operator++();
private:
  double l2norm;
 
};

double norm(Matrix m);
double transpose(Matrix m);

