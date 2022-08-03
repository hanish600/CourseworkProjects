
#include <iostream>
#include <fstream>
#include  "ChunkList.h"
using namespace std;

int main()
{
    ChunkList<int> obj;
    ifstream file;
    file.open("TestDr.txt");
    string command;
    int item;
    while (!file.eof())
    {
        file >> command;
        if (command == "Append")
        {
            file >> item;
            cout << "Inserting: " << item << endl;
            obj.Append(item);
        }

        else if (command == "GetLength")
        {
            int total = obj.GetLength();
            cout << "Total Length: " << total << endl;
        }
        else if (command == "GetIndex")
        {
            file >> item;
            int index = obj.GetIndex(item);
            if (index != -1)
            {
                cout << "Item at index " << item << " was " << index<<endl;
            }
            else { cout << "Item at index " << item << " was not found" << endl; }
        }
        else if (command == "Contains")
        {
            file >> item;
            bool x = obj.Contains(item);
            if (x == false)
            {
                cout << "Item "<<item<<" was not found" << endl;
            }
            else { cout <<"Item "<<item<<" Item was found" << endl; }
        }
        else if (command == "Remove")
        {
            file >> item;
            bool x = obj.Remove(item);
            if (x == true)
            {
                cout << "Item "<<item<<" was removed" << endl;
            }
            else { cout << "Item"<<item<<" was not found" << endl; }
        }
        else if (command == "Print")
        {
            ostream& out = cout;
            obj.Print(out);
        }
        else if (command == "IsEmpty")
        {
            bool x = obj.IsEmpty();
            if (x == true)
            {
                cout << "List was empty"<<endl;
            }
            else
            { 
                cout << "List was not empty"<<endl;
            }
        }
        else
        {
            // do nothing
        }
    }
    /*
    * 
    * This was used to test each function
    * This should be ignored
    * 
    obj.Append(5);
    obj.Append(19);
    obj.Append(24);
    obj.Append(34);
    obj.Append(11);
    obj.Append(12);
    obj.Append(23);
    obj.Append(233);
    obj.Append(14);
    obj.Append(10);
    //obj.printList);
    obj.Append(45);
    obj.Append(5);
    obj.Append(34);
    obj.Append(134); */
    //int j=obj.GetIndex(30);
    //cout << j<<endl;
    //int z= obj.Contains(77);
    //cout << z;
    //obj.Remove(45);
    //ostream& out=cout;
    //obj.Print(out);
    //bool x=obj.IsEmpty();
    //cout << x;
}