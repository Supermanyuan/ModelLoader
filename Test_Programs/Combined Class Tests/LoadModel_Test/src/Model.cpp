#include "Model.h"
#include <vector>
Model::Model(string FileName) {
	LoadModel(FileName);
}
Model::~Model() {
	//delete[]Vertices;
	//delete[]Cells;
	//delete[]Materials;
}
int Model::SaveModel(void) {
	return 0;
}
void Model::LoadModel(string FileName) {
	string line, data;
	ifstream file;
	
	vector<Vector> Vertices;
	vector<Material> Materials;
	vector<Pyramid> Pyramids;
	vector<Hexahedron> Hexahedrons;
	vector<Tetrahedron> Tetrahedrons;

	

	file.open(FileName);
	while (getline(file, data)) { //Read each line and send data to classes
		line = data[0];
		
		if (line == "v") {
			SetVertices(data); //
			
		
		}
		else if (line == "m") {
			SetMaterial(data);
			
		}
		else if (line == "c") {
			SetCell(data);
		}
	}
	file.close();
}
void Model::SetCell(string data) {
	istringstream iss(data);
	vector<std::string> results((std::istream_iterator<std::string>(iss)),
		istream_iterator<std::string>());

	int ID = stoi(results[1]);
	string Type = results[2];
	int MaterialID = stoi(results[3]);


	if (Type == "h") {
		Hexahedron *H = new Hexahedron;
		H->setCell(ID, MaterialID, Type);
		Hexahedrons.push_back(*H);
		for (int i = 0; i < 8; i++) {
			H->setVertices(stoi(results[i + 4]));
		}
	} 
	else if (Type == "p") {
		Pyramid *P = new Pyramid;
		P->setCell(ID, MaterialID, Type);
		Pyramids.push_back(*P);
		for (int i = 0; i < 5; i++) {	
			P->setVertices(stoi(results[i + 4]));
		}	
	}
	else if (Type == "t") {
		Tetrahedron *T = new Tetrahedron;
		T->setCell(ID, MaterialID, Type);
		Tetrahedrons.push_back(*T);
		for (int i = 0; i < 4; i++) {		
			T->setVertices(stoi(results[i + 4]));

		}	
	}

}
void Model::SetVertices(string data) {
	istringstream iss(data);
	vector<std::string> results((std::istream_iterator<std::string>(iss)),
		istream_iterator<std::string>());
	int ID = stoi(results[1]);
	float X = stof(results[2]);
	float Y = stof(results[3]);
	float Z = stof(results[4]);

	Vector *V = new Vector;
	V->SetVector(ID, X, Y, Z);
	Vertices.push_back(*V);
}
void Model::SetMaterial(string data) {

	istringstream iss(data);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	int ID = stoi(results[1]);
	int Density = stoi(results[2]);
	string Name = results[4];
	string Colour = results[3];

	//Materials[NumN].setMaterial(ID, Density, Colour, Name);

	Material *M = new Material;
	M->setMaterial(ID, Density, Colour, Name);
	Materials.push_back(*M);
}
string Model::GetCell(int ID, string Type) {
	/*if (Type == "p") {
		if (ID <= pyramids.size())
			return pyramids[ID] <-ID;
	}
	else if (Type == "t") {

	}
	else if (Type == "h") {

	}
	else
		cout << "Type not Found" << endl;*/
	return "";
}
void Model::GetVertices(int ID) {
	float x = Vertices[ID].getx();
	float y = Vertices[ID].gety();
	float z = Vertices[ID].getz();

	cout << x << y << z;

}
void Model::GetMaterial(int ID) {
	int ID2 = Materials[ID].getMatID();
	string Colour = Materials[ID].getColour();
	string Name = Materials[ID].getName();
	int Density = Materials[ID].getDensity();

	cout << "ID: "<<ID2 << "Colour: "<< Colour << "Name: "<<Name <<"Density"<< Density;
	

}
void Model::FindCentre(void) {
}
int Model::NumberVertices(void) {
	return Vertices.size();

}

void Model::NumberCells(void) {
	int NumP = Pyramids.size();
	int NumT = Tetrahedrons.size();
	int NumH = Hexahedrons.size();

	cout << "There are " << NumP << " Pyramid Cells" << endl;
	cout << "There are " << NumT << " Tetrahedron Cells" << endl;
	cout << "There are " << NumH << " Hexahedron Cells" << endl;
}