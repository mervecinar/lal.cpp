#include "lal.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <typeinfo>
#include <string.h>

using namespace std;
// constructor 
 Matrix::Matrix(double* entries, int r, int c){
   rows=r;
   cols=c;
   this->entries=new double[r*c];
}
void Matrix::mRandom(void){
		for (int i = 0; i <rows; i++){
          for (int j = 0; j <cols; j++){
   	        entries[i* cols + j] =(rand() % 10) / 1.0;      
}
}    
}
//Matrisi yazd�rma
  void Matrix::print(void) {	
  	for (int i = 0; i <rows; i++) {
          for (int j = 0; j <cols; j++) {
          		cout<<entries[i* cols + j];
          			 cout<<" ";
}
cout<<"\n";
}    
}
//get metotlar�
   int Matrix::getrows(){
   	return rows;
   }
    int Matrix::getcols(){
   return cols;
   }
     double* Matrix::getentries(){
   return this->entries;
   }
   
	//Matrix toplam
  Matrix Matrix::operator+(const Matrix& sag){
	 
	 	Matrix top(entries, rows, cols);
	 	 if(this->rows!=sag.rows || this->cols!=sag.cols){
	 	 	cout<<"Islem gecersiz: boyut uyumsuzlugu!"<<endl;
	 	 return *this;
	 	  } 
	for (int i = 0; i < rows * cols; ++i) {
    top.entries[i] = entries[i] + sag.entries[i];
      } 
        return top;
}
	//Matrix Fark�
 Matrix Matrix::operator-(const Matrix &sag){
	 	if(this->rows!=sag.rows || this->cols!=sag.cols){
	 	 	cout<<"Islem gecersiz: boyut uyumsuzlugu!"<<endl;
	 	 return *this;
	 }
	 	Matrix fark(entries, rows, cols);
      for (int i = 0; i < rows * cols; ++i) {
    fark.entries[i] = entries[i] - sag.entries[i];
       }
      return fark;
}
//Matrix �arpma
Matrix Matrix::operator*(const Matrix &sag){
	if(this->rows!=sag.rows || this->cols!=sag.cols){
	 	 	cout<<"Islem gecersiz: boyut uyumsuzlugu!"<<endl;
	 	 return *this;
	 }
        Matrix carp(entries,rows,cols);
               carp.rows=rows;
               carp.cols=sag.cols;
            for(int i=0;i<carp.rows;i++)
            for(int j=0;j<carp.cols;j++)  {
        carp.entries[i* cols + j]=0;
           for(int k=0;k<cols;k++)
           carp.entries[cols*i+j]+=entries[cols*i+k]*sag.entries[cols*k+j];                                
                        }
         return carp;
} 
//Matrix E�itlik Kontrol
	 bool Matrix::operator==(const Matrix& sag){
	 	bool isEqual=0;
for(int i=0; i<rows*cols; i++){
	
if(this->entries[i]==sag.entries[i]){
	isEqual=1;
}else{
	isEqual=0;
}
}
return cout<<"isEqual: "<< boolalpha<<isEqual;
}
  //destructer Matrix 
  Matrix::~Matrix() {} 
 // Vekt�r constructor 
  Vector::Vector(double* entries, int rows):Matrix(entries, rows, cols){
     //cols=1
      this->rows=rows;
      	 cols=1;
	 this->entries=new double[rows];
    double v[rows];
    for(int i=0; i<rows; i++){
	this->entries[i]=i;
	}
	double kareTop=0;	
	for(int i=0; i<rows*cols; i++){
		kareTop+=v[i]*v[i]; //a^2+b^2=kareler toplam�
	}
	double l2norm=sqrt(kareTop); //uzunlu�u bulmak i�in toplam�n k�k�n� al�yor.
}
//Random Vekt�r olu�turuyor
void Vector::vRandom(void){
	entries[rows];
    for (int i = 0; i < rows; i++) {
        entries[i] = (rand() % 10) / 1.0; 
       
    }
}
//Vekt�r�n elemanlar�n�n karesinin toplam�n� k�k i�ine al�p yazd�r�yor ve normu buluyor.
void Vector::NormPrint(void){
    double kareTop = 0.;
    for (int i = 0; i < rows; i++) {
        kareTop += entries[i] * entries[i];
    }
    this->l2norm= sqrt(kareTop);
    cout<<"l2norm :"<<l2norm;
}
    //Vekt�r� yazd�rma
  void Vector::print(void){
  for (int i = 0; i < rows; i++) {
       cout<<entries[i];
       cout<<" ";
    }
}

//Vekt�r Toplama
 Vector Vector::operator+(const Vector& vsag){
 	
	 	Vector top(entries, rows);
   for (int i = 0; i < rows; i++) {
    top.entries[i] = entries[i] + vsag.entries[i];
	 }
     return top; 
}
//Vekt�r Fark
Vector Vector::operator-(const Vector& vsag){
	 	Vector fark(entries, rows);
   for (int i = 0; i < rows; i++) {
    fark.entries[i] = entries[i] - vsag.entries[i];
	 }
     return fark; 	
}
//Vekt�r �arpma
 Vector Vector::operator*(const Vector& vsag){
	 	Vector carp(entries, rows);
   for (int i = 0; i < rows; i++) {
    carp.entries[i] = entries[i] * vsag.entries[i];
	 }
     return carp;
} 

//Vekt�r E�itli�i
 bool Vector::operator==(const Vector& vsag){
 	bool isEqual=0;
	  for(int i=0;i<rows;i++){
		if(entries[i]==vsag.entries[i]){
		 isEqual=1;	
	}else{
		isEqual=0;
	}
	}
	  	return cout<<" isEqual : "<< boolalpha << isEqual;
      }  
//pre
    void Vector::operator++(int){
	for(int i=0;i<rows;i++){
		cout<<++entries[i];
	}
}
//post
    void Vector::operator++(){
	for(int i=0;i<rows;i++){
	    cout<<entries[i]++;
	    
	}
}
   double norm(Matrix m){
 //typeidname de�eri vekt�r i�in "6Vector" matrix i�in "6Matrix" dir. main de �a��rarak kontrol
 //buna g�re girilen de�er hangi t�r ise o ko�ula g�le i�lem yapan bir if ko�ulu kulland�m.
	string a=typeid(m).name();
	string b="6Matrix";
	string c="6Vector";
	
	if(a==b){
		double norm=0;
		for(int i=0;i<m.getrows();i++){
			for(int j=0;j<m.getcols();j++){
				norm+=m.getentries()[m.getcols()*i+j]*m.getentries()[m.getcols()*i+j];
			}
		}
		return sqrt(norm);
	}
	//vek�r
	else if(a==c){
		double norm=0;
		for(int i=0;i<m.getrows();i++){
			norm+=m.getentries()[i]*m.getentries()[i];
		}
		return sqrt(norm);
		}
		else{
	cout<<"girilen t�r matrix veyahut vector degildir.";
}
 }
    double transpose(Matrix m){
	//Yine typeid ismi kontrol edilerek Matrix mi, vektor mu oldugu sorgulanir
	string a=typeid(m).name();
	string b="6Matrix";
	string c="6Vector";
	if(a==b){
    
	for(int i=0;i<m.getrows();i++){
			for(int j=0;j<m.getcols();j++){
			m.getentries()[i*m.getcols()+j]	=m.getentries()[j*m.getrows()+i];
			cout<<m.getentries()[i*m.getcols()+j];
			cout<<" ";
			}
			cout<<"\n";
		}	
}
 else if(a==c){
	for(int i=0;i<m.getcols();i++){
		 	m.getentries()[i*m.getcols()+1]	=m.getentries()[1*m.getcols()+i];
			cout<<m.getentries()[i*m.getcols()+1];
		}
}
else{
	cout<<"girilen t�r matrix veyahut vector degildir.";
}
}
//Destructer
 Vector::~Vector() { }

