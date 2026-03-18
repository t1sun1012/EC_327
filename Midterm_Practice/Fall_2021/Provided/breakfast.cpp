#include <iostream>
#include <fstream>
using namespace std;

extern const int PANCAKES;
extern const int FRENCHTOAST;
extern const int WAFFLES;
extern const int FRUITPLATE;

//4 FIX statements
//add getBreakfastOrders header
??//FIX
{
	
	int *breakfastArray = ??;//FIX
	for(int i=0; i< count; i++)
	{
		cout << "Order #" << i << " is?: ";
		cin >> ??;//FIX
	}
	
	return ??;//FIX
}

//6 Fix statements
//add processBreakfastFile header
??//FIX
{
	char *filename = ??;//FIX
	filename = (char*) "Orders.txt";
	ofstream outputFile;
	outputFile.open(filename);
	outputFile.clear();
	for (int i=0; i<orderCount; i++)
	{
		 switch(orders[i])
		  {
			case 1:  ?? << ?? << endl; //FIX
				break;
			case 2:  ?? << ?? << endl; //FIX 
				break;
			case 3:  ?? << ?? << endl; //FIX  
				break;
			case 4:  ?? << "FruitPlate" << endl; //FIX
				break;
			default:
			  cout << "Error processing breakfast. There is no " << orders[i] << endl;
		  }
		
	}
	outputFile.close();
	return filename;
}

