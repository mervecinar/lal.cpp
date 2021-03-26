#include "lal.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <typeinfo>
#include <string.h>
int main(void){
	srand(time(NULL));
	
   cout<<"***********MATRIX1************\n"<<endl;
   Matrix m1((double*)1,3,3);
      m1.mRandom();
      m1.print();
   cout<<"***********MATRIX2***********\n"<<endl;
  Matrix m2((double*)1,3,3);
      m2.mRandom();
      m2.print();
 cout<<"********* MATRIX TOPLAMLARI ***********\n"<<endl;
   (m1+m2).print();
cout<<"********** MATRIX CIKARIMLARI **********\n"<<endl;
   (m1-m2).print();
cout<<"********** MATRIX CARPIMLARI ***********\n"<<endl;
   (m1*m2).print();
   cout<<"********** MATRIX ESITLIK ***********\n"<<endl;
   (m1==m2);
  m2.~Matrix();
  m1.~Matrix();
cout<<"\n";
  
   cout<<"***********VEKTOR1***********\n"<<endl;
  Vector v1((double*)1,4);
   v1.vRandom();
   v1.print();
   v1.NormPrint();
cout<<"\n";
   cout<<"***********VEKTOR2***********\n"<<endl;
  Vector v2((double*)1,4);
    v2.vRandom();
    v2.print();
    v2.NormPrint();
   cout<<"\n";
   cout<<"********* VEKTOR TOPLAMLARI ***********\n"<<endl;
  Vector d3=v1+v2;
    d3.print();
   cout<<"\n";
   cout<<"********** VEKTOR CIKARIMLARI ********** \n"<<endl;
   (v1-v2).print();
    cout<<"\n";
   cout<<"********** VEKTOR CARPIMLARI *********** \n"<<endl;
    (v1*v2).print();
    cout<<"\n";
     cout<<"********** VEKTOR ESITLIGI *********** \n"<<endl;
    v1==v2;
    cout<<"\n";
   cout<<"pre"<<endl;
     ++v1;
     cout<<"\n\n";
       cout<<"post"<<endl;
     v2++;
    cout<<"\n\n";
    cout<<"Matrix icin typeidname degeri= "<<typeid(m1).name()<<endl;
    cout<<"Vektor icin typeidname degeri= "<<typeid(v1).name()<<endl;
    cout<<"MATRIX Transose\n\n";
    transpose(m1);
     cout<<"\n\n";
      cout<<"VECTOR Transose\n\n";
     transpose(v1);
        cout<<"*************\n\n";
        cout<<"MATRIX NORM\n\n";
        double b=norm(m1);
        cout<<b;
     cout<<"\n\n";
      cout<<"VECTOR NORM\n\n";
      double a=norm(v1);
      cout<<a;
      
        cout<<"\n\n";
        
       
      /*
    Matrix *dizi=(Matrix*)malloc(sizeof(Matrix)*4);
	Matrix *ma1((double*)1,3,3));
	Matrix *ma2((double*)1,3,3));
	Vector *ve1((double*)1,2));
	Vector *ve2((double*)1,2));
	dizi[0]=ma1;
	dizi[1]=ma2;
	dizi[2]=ve1;
	dizi[3]=ve2;
*/   
  try
  { 
     int* hata = new int[100000000]; 
  } 
  catch (std::bad_alloc & e) 
  { 
     std::cerr << "bad_alloc caught: " << e.what(); 
  } 
  
       int p=10;
       int m=10;
      Vector* vectorArray = (Vector*)malloc(sizeof(Vector)*m);
    	for(int i=0;i<m;i++){
		double* entries = (double*)malloc(sizeof(double)*p);
		for(int j=0;j<p;j++){
		entries[j]= (rand() % 10) / 1.0; 
		}
		vectorArray[i]= Vector(entries,m);
	}
}
 
 
   

