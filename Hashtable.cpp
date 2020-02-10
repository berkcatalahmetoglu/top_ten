#include "Hashtable.h"

HashMap::HashMap()
{
	table = new HashEntry*[Table_Size];
	for (int i = 0; i < Table_Size; i++)
	{
		table[i] = nullptr;
	}

	sortedArray = new HashEntry*[10];

	for (int i = 0; i < 10; i++)
	{
		sortedArray[i] = nullptr;

	}
}

unsigned long int HashMap::Hashfunc(string key)
{
	unsigned long int hash = 5381;
	int c;
	for (auto x : key)
	{
		c = x;
		hash = ((hash << 5) + hash) + c;
		/* hash * 33 + c */
	}
	return (hash % Table_Size);
}


int x = 0;


void HashMap::Insert(string key,string description, int value)
{
	long int index_hashtable = Hashfunc(key) % Table_Size;

	while (table[index_hashtable] != nullptr && table[index_hashtable]->key != key)
	{
		index_hashtable = (Hashfunc(key) + 1) % Table_Size;
		break;
	}

	if (table[index_hashtable] != nullptr&& table[index_hashtable]->key == key)
	{
		/*int new_quantity = stoi(table[index_hashtable]->value) + stoi(value);
		string new_quantity_string = to_string(new_quantity);
		table[index_hashtable]->value = new_quantity_string;
		table[index_hashtable] = new HashEntry(key, new_quantity_string);*/

		value = table[index_hashtable]->value + value;
		table[index_hashtable] = new HashEntry(key,description, value);

		/*if (table[index_hashtable]->key == key)
		{
			int new_quantity = stoi(table[index_hashtable]->value) + stoi(value);
			string new_quantity_string = to_string(new_quantity);
			table[index_hashtable]->value = new_quantity_string;
			table[index_hashtable] = new HashEntry(key, new_quantity_string);

		}
		else
		{
			//string temp_key = key + "1";
			cout <<table[index_hashtable]->key<<"	ile "<< key<<"	cakisti...	 "<<"	ikisi de bu degere gitmek istedi"<<index_hashtable << endl;
			Insert(key + "1", value);


			cout << "*********" << key << endl;

		}*/
	}
	else
	{
		table[index_hashtable] = new HashEntry(key,description, value);


	}


}

int index_array = 0;
int ass = 0;
void HashMap::print()
{
	int x = 1;
	for (int i = 0; i < 600000; i++)
	{
		if (table[i] != nullptr) {
			cout << x << "	" << i << "	" << "	Value->		" << table[i]->value << "	key->	" << table[i]->key << endl;
			x++;
		}

	}

}
int maxquantity = 1;


int j = 0;
/*void HashMap::search()
{
	int k = 0;

	int c1 = 0, c2 = 0;
	for (int k = 0; k < Table_Size; k++) {
		while (table[k] != nullptr&&j < 10)
		{
			sortedArray[j] = new HashEntry(table[k]->key, table[k]->value);



			if (j == 9)
			{
				int c1, c2;
				int n = sizeof(sortedArray) / sizeof(sortedArray[0]);

				for (c1 = 0; c1 < 9; c1++)

					// Last i elements are already in place  
					for (c2 = 0; c2 < n - c1 - 1; c2++)
						if (sortedArray[c2] > sortedArray[c2 + 1])
						{
							HashEntry **temp;
							temp = new HashEntry*[10];
							for (int j = 0; j < 10; j++)
							{
								temp[j] = new HashEntry("", 0);
							}
							for (int j = 0; j < 10; j++)
							{
								sortedArray[c2]->value = temp[c1]->value;
								sortedArray[c2]->key = temp[c1]->key;

								temp[c1]->value = sortedArray[c2 + 1]->value;
								temp[c1]->key = sortedArray[c2 + 1]->key;

								sortedArray[c2 + 1]->value = sortedArray[c2]->value;
								sortedArray[c2 + 1]->key = sortedArray[c2]->key;

							}

						}
			}

			j++;
			/*sortedArray[c2]->value = temp[c1]->value;
sortedArray[c2]->key = temp[c1]->key;
temp[c1]->value = sortedArray[c2 + 1]->value;
temp[c1]->key = sortedArray[c2 + 1]->key;
sortedArray[c2 + 1]->value = sortedArray[c2]->value;
sortedArray[c2 + 1]->key = sortedArray[c2]->key;*/

/*
		}


	}
	*/
		



	/*int j = 0;
	for (int j = 0; j < 600000; j++) {
		while (table[j] != nullptr)
		{

			a[index_array] = table[j]->value;
			index_array++;

			j++;
		}
	}
	int n = sizeof(a) / sizeof(a[0]);
	quickSort(a, 0, n - 1);

	printArray(a,n);

}*/



bool HashMap::indexhashtablebosmu(string key)
{
	long int index_hashtable = Hashfunc(key) % Table_Size;
	if (table[index_hashtable] == nullptr) { return true; }
	else { return false; }
}




void HashMap::printa()
{
	for (int j = 0; j < 99; j++)
	{
		cout << "A[ " << j << "]:	" << a[j] << endl;
	}
}






/*void swap(HashEntry** a, HashEntry** b)
{
	HashEntry **temp;
	temp = new HashEntry*[10];
	for (int j = 0; j < 10; j++)
	{
		temp[j] = new HashEntry("", 0);
	}
	for (int j = 0; j < 10; j++)
	{
		a[j]->value = temp[j]->value;
		a[j]->key = temp[j]->key;

		temp[j]->value = b[j]->value;
		temp[j]->key = b[j]->key;


		b[j]->value = a[j]->value;
		b[j]->key = a[j]->key;

	}


}*/

void HashMap::printTopTen() {
	int maxValue = 0;
	int indexHolder = 0;
	cout << "#" << " " << "Stock Code" << "\t" << "Description" << "\t\t\t" << "Quantity" << endl;
	for (int i = 0; i < 10; ++i) {  //-> This loop for top 10
		for (int index = 0; index < Table_Size; ++index) { //-> base loop to find max quantity in hash table
			if (table[index] != nullptr) 
			{  // to check if index is NULL or not
				if (table[index]->value > maxValue) {
					maxValue = table[index]->value; //update the maxValue with biggest quantity
					indexHolder = index; // -> to store index number of max quantity in hash table
				}
			}
		}
		for (int indeX = 0; indeX < Table_Size; ++indeX) { //find the max quantity's stockCode,description
			if (table[indeX] != nullptr) { // to check if index is NULL or not
				if (table[indeX]->value == maxValue) { //if we have reached the maxValue then it's quantity is top 1
					cout << i + 1 << "." << " " << table[indeX]->key << "\t" <<table[indeX]->description<< "\t" << table[indeX]->value << endl;
					table[indexHolder]->value = 0; //after cout the max one, delete the index so it can't be top 1 again
				}
			}
		}
		maxValue = 0; // update max value 0 again for second base loop
	}
}