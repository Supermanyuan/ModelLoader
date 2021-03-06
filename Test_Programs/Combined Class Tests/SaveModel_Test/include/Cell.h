#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Vector.h"
#include "Material.h"

#include <cmath>
#include "Vector.h"


using namespace std;

/*Class cell*/
class cell {
protected:
	  friend class Pyramid;
	  friend class Tetrahedron;
	  friend class Hexahedron;
      int CellID, material;
      string type;
      vector<int> p;
	  vector<Vector> v;
public:
	 
      void setCell(int ID, int m, string type); //store cellID, matID and cell type
      void setVertices(int v);
	  string getType();
	  int getCellID();
	  int getMaterialID();
	  int getVerticesID(int n);
	  void setV(vector<Vector>& CellVertices);
	  std::vector<Vector> getV();
      //double getweight(double volume);
      //virtual double getcentre();
};






/*Member class tetrahedron*/
/*class tetrahedron : public cell {
public:
      void setTetrahedron(int p[4]); //store tetrahedron veteces
      //double getvolume();
      //double getcentre();
};


/*Member class pyramid*/
/*class pyramid : public cell {
public:
      void setPyramid(int p[5]);
      //double getvolume();
      //double getcentre();
};
/*----------------------------------------------------------------------------*/
/*
      void setPyramid(int p[5]); //store pyramid veteces
      //double getvolume();
      //double getcentre();
}

/*Menber class hexahedron*/
/*class hexahedron : public cell {
public:
      void setHexahedron(int p[8]); //store hexahedron veteces
      //double getvolume();
      //double getcentre();
}*/
