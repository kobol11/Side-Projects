//OOP244 Final Project
// File PosAppMain.cpp
// Version 1.0
// Date 13th April, 2017
// Author Bolarinwa Komolafe Email:bkomolafe@myseneca.ca
// Description
// This file contains the main function

#include "PosApp.h"
int main(){
  ict::PosApp app("posapp.txt", "bill.txt");
  app.run();
  return 0;
}