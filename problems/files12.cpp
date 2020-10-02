#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
 
struct Product
{
	char description[32];
	int partNum;
	double cost;
};

void print (const Product& p, ostream& out)
{
	out << p.description << endl;
	out	<< p.partNum << endl;
	out	<< p.cost << endl;
}
void read (Product& p, istream& in)
{
	in.getline(p.description, 32);
	in >> p.partNum;
	in >> p.cost;
	in.ignore();
}

int main()
{
	
	Product p1, p2;
	// First you need to initilaize the object !!!
	strncpy(p1.description, "screw driver", 32);
	p1.partNum = 456;
	p1.cost = 5.50;

	strncpy(p2.description, "hammer", 32);
	p2.partNum = 324;
	p2.cost = 8.20;
	
	//Then you print the data in a file
	ofstream outf("products.txt");
	print(p1, outf);
	print(p2, outf);
	
	//Now you can read the written data in products.txt and write it on
	//the console or to another text file(for instance, products2.txt)
	ifstream inf ("products.txt");
	ofstream outf2 ("products2.txt");

	Product* arr = new Product[2];

	for (int i = 0; i < 2; i++)
	{
		read(arr[i], inf);
		//print(arr[i], cout);
		print(arr[i], outf2); //---> if you want to print what you have
		//already read to another file, instead of on the console
	}

	delete[] arr;
	return 0;
}