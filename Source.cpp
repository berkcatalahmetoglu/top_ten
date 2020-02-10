#include "Hashtable.h"
struct product
{
	string quantity;
};
istream& operator>>(std::istream& is, product& coordinates)
{
	is >> coordinates.quantity;

	return is;
}


int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	//HashEntry object("", "", "");
//	HashMap object2;


	/*ifstream inputFile;
	inputFile.open("OnlineRetail.csv");*/
	fstream inputFile("OnlineRetail.txt");

	string firstrow;
	getline(inputFile, firstrow);//we did that skip first row because we dont use first row.

	int quantity_int = NULL;
	
	product product;
	string invoiceno = "";
	string stockcode = "";
	string description = "";
	string quantity = "";
	string invoicedate = "";
	string unitprice = "";
	string customerid = "";
	string country = "";
	int i = 0;
	while (!inputFile.eof())
	{

		
		
		switch (i)
		{
		case 0:
			getline(inputFile, invoiceno, ';');
			i++;
		case 1:
			getline(inputFile, stockcode, ';');
			//object.key = stockcode;

			i++;
		case 2:
			getline(inputFile, description, ';');
			//object.description = description;

			i++;
		case 3:
			getline(inputFile, quantity, ';');
			
			product.quantity = quantity;


			i++;
		case 4:
			getline(inputFile, invoicedate, ';');
			i++;
		case 5:
			getline(inputFile, unitprice, ';');
			i++;
		case 6:
			getline(inputFile, customerid, ';');
			i++;
		case 7:
			getline(inputFile, country);
			i++;
			break;
		}

		cout << product.quantity << endl;

		//object2.Insert(object.key, object.description, object.value);


		//i++;






		/*//deðerlere atayabildik mi diye kontrol etmek için
		cout << "	stockcode is: " << ProductArray[counter_arrayindex].stockcode << endl;
		cout << "	description is: " << ProductArray[counter_arrayindex].description << endl;
		cout << "	quantity is: " << ProductArray[counter_arrayindex].quantity << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;
		*/


	}
	//object2.printTopTen();




	//object.search();


	//object.printa();

	//object.print();

	//object.search();
	//object.printTopTen();


	auto finish = std::chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = finish - start;			//for calculate elapsed time
	cout << "Elapsed time: " << elapsed.count() << " \n";

	system("Pause");
}
