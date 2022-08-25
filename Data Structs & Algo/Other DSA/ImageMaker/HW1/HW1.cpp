// HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#include <cmath>


// Limits
const int MAX_WIDTH = 640;
const int MAX_HEIGHT = 480;
const int MAX_COLOR = 255;
enum COLOR {RED,GREEN,BLUE};
using namespace std;

// x y cordinates
int values();

int values()
{
    int x,y=0;
    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter y: ";
    cin>>y;

    // First Input validation
    // Only compares max/min size first
    while (x<0 || x>640)
        {
            try {throw("X Error");}
            catch(const char* msg)
            {
                cout<<"Error"<<endl;
                cout<<"Enter a new X: ";
                cin>>x;
            }
        }
    while (y<0 || y>480)
        {
            try {throw("Y Error");}
            catch (const char* msg)
            {
                cout<<"Error"<<endl;
                cout<<"Enter a new Y: ";
                cin>>y;
            }
        }
    return x,y;
}

class ImageMaker
{
public:

    // Self executes
    ImageMaker()
    {
        fstream opener;
        opener.open("C:\\Users\\hanis\\AppData\\Local\\Programs\\GIMP 2\\bin\\gimp-2.10.exe");
    };
    ImageMaker(string filename);
private:

    // Dimentions
    int width;
    int height;

    // Colors
    int pen_red;
    int pen_green;
    int pen_blue;

    // Image Array
    short image[MAX_WIDTH][MAX_HEIGHT][3];

public:
    // Functions

    // If everything else is invalid
    void DEFAULT(int width=0,int height=0)
    {
        pen_red=0;
        pen_green=0;
        pen_blue=0;
    }

    void LoadImage(string filename)
    {
        ifstream reader;
        reader.open(filename);

        // Throws error if can't open
        while (!reader.is_open())
        {
            try
            {
                reader.open(filename);
                if (!reader.is_open())
                {
                    throw("Error loading");
                }
                else {break;}
            }
            catch (const char* msg)
            {
                cout<<"Cannot load file"<<endl;
                cout<<"Enter another file: ";
                cin>>filename;
            }
        }
        reader.close();
    }

    void SaveImage(string filename)
    {
        ofstream createimg;
        createimg.open(filename);

        // Throws error if special char
        while (!createimg.is_open())
        {
            try
            {
                createimg.open(filename);
                if (!createimg.is_open())
                {
                    throw("Error Saving");
                }
                else {break;}
            }
            catch (const char* msg)
            {
                cout<<"Cannot save file"<<endl;
                cout<<"Enter another file: ";
                cin>>filename;
            }
        }
        createimg << "P3" << endl;
        createimg << width << " " << height << endl;
        createimg<<"255"<<endl;

        // Outputs image from array
        for (int i=0;i<height;i++)
        {
            for (int j=0;j<width;j++)
            {
                createimg<<image[i][j][0];
                createimg<<" ";
                createimg<<image[i][j][1];
                createimg<<" ";
                createimg<<image[i][j][2];
                createimg<<" ";
            }
            createimg<<endl;
        }
        createimg.close();
    }

    // Rechecks Width Height
    void WidthHeightChecker(int x,int y)
    {
        while (x<0 || x>640)
        {
            try { throw("Width Error"); }
            catch(const char* msg)
            {
                cout<<"Error"<<endl;
                cout<<"Enter a new width: ";
                cin>>x;
            }
            SetWidth(x);
        }
        while (y<0 || y>480)
        {
            try { throw("Height Error"); }
            catch (const char* msg)
            {
                cout<<"Error"<<endl;
                cout<<"Enter a new height: ";
                cin>>y;
            }
            SetHeight(y);
        }
    }

    // Gets Width Height and sets it
    int GetWidth()
    {
        int Width;
        cout << "Enter the width: ";
        cin >> Width;
        WidthHeightChecker(Width,0);
        return Width;
    }

    int GetHeight()
    {
        int Height;
        cout << "Enter the height: ";
        cin >> Height;
        WidthHeightChecker(0,Height);
        return Height;
    }

    void SetWidth(int Width)
    {
        width = Width;
    }

    void SetHeight(int Height)
    {
        height = Height;
    }

    // Checks RGB values
    void ColorChecker(int pen_red,int pen_green,int pen_blue)
    {
        while (pen_red>255 || pen_red<0)
        {
            try{throw("Error Color");}
            catch(const char* msg)
            {
                cout<<"invalid color"<<endl;
                cout<<"Enter new color: ";
                cin>>pen_red;
                SetPenRed(pen_red);
            }
        }

        while (pen_green>255 || pen_green<0)
        {
            try{throw("Error Color");}
            catch(const char* msg)
            {
                cout<<"invalid color"<<endl;
                cout<<"Enter new color: ";
                cin>>pen_green;
                SetPenGreen(pen_green);
            }
        }

        while (pen_blue>255 || pen_blue<0)
        {
            try{throw("Error Color");}
            catch(const char* msg)
            {
                cout<<"invalid color"<<endl;
                cout<<"Enter new color: ";
                cin>>pen_blue;
                SetPenBlue(pen_blue);
            }
        }
    }

    // Gets and Sets initial RGB
    int GetPenRed()
    {
        int RedValue;
        cout << "Enter a value: ";
        cin >> RedValue;
        ColorChecker(RedValue,0,0);
        return RedValue;
    }

    int GetPenGreen()
    {
        int GreenValue;
        cout << "Enter a value: ";
        cin >> GreenValue;
        ColorChecker(0,GreenValue,0);
        return GreenValue;
    }

    int GetPenBlue()
    {
        int BlueValue;
        cout << "Enter a value: ";
        cin >> BlueValue;
        ColorChecker(0,0,BlueValue);
        return BlueValue;
    }

    void SetPenRed(int NewR)
    {
        pen_red = NewR;
    }

    void SetPenGreen(int newG)
    {
        pen_green = newG;
    }
    void SetPenBlue(int newB)
    {
        pen_blue = newB;
    }

    // Pixel
    void DrawPixel(int x, int y)
    {
        WidthHeightChecker(width,height);
        ColorChecker(pen_red,pen_green,pen_blue);
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                if (i == x && j == y)
                {
                    int r = pen_red;
                    int g = pen_green;
                    int b = pen_blue;
                    image[i][j][0]+=(r);
                    image[i][j][1]+=(g);
                    image[i][j][2]+=(b);
                }
            }
        }
    }

    // Line
    void DrawLine(int x1,int y1,int x2,int y2)
    {
        WidthHeightChecker(width,height);
        ColorChecker(pen_red,pen_green,pen_blue);
        long double m,b;
        m=(double(y2-y1))/(double (x2-x1));
        b=(double(y1))-(double(m*x1));
        long double y=0;
        for (int i=0;i<width;i++)
        {
            for (int j=0;j<height;j++)
            {
                if (y==0)
                {
                    y=m*i+b;
                    y=round(y);
                    DrawPixel(i,y);
                    // Breaks out of for loop
                    y=1;
                }
            }
            // Resets Loop
            y=0;
        }
    }

    // Rectangle
    void DrawRectangle(int x1,int y1,int x2,int y2)
    {
        WidthHeightChecker(width,height);
        ColorChecker(pen_red,pen_blue,pen_green);
        DrawLine(x1,y1,x1,y2);
        DrawLine(x1,y2,x2,y2);
        DrawLine(x2,y2,x2,y1);
        DrawLine(x1,y1,x2,y1);
    }

    // Recheck and compare to set width and height
    int CheckCordinates(int x,int y)
    {
        int NewX,NewY=0;
        while (x<0 || x>width)
        {
            try { throw("X Error"); }
            catch(const char* msg)
            {
                cout<<"Error"<<endl;
                cout<<"Enter a new X: ";
                cin>>x;
                NewX=x;
            }
        }
        while (y<0 || y>height)
        {
            try { throw("Height Error"); }
            catch (const char* msg)
            {
                cout<<"Error"<<endl;
                cout<<"Enter a new Y: ";
                cin>>y;
                NewY=y;
            }
        }
        if (NewX!=0 && NewY!=0)
        {
            return NewX,NewY;
        }
        else if (NewX=0 && NewY!=0)
        {
            return x,NewY;
        }
        else if (NewX!=0 && NewY==0)
        {
            return NewX,y;
        }
        else {return x,y;}
    }
};

int main()
{
    ImageMaker obj;
    int Width=obj.GetWidth();
    obj.SetWidth(Width);
    int Height=obj.GetHeight();
    obj.SetHeight(Height);
    //cout<<"Size Width: "<<Width<<endl;
    //cout<<"Size Height: "<<Height;
    int R=obj.GetPenRed();
    int G=obj.GetPenGreen();
    int B=obj.GetPenBlue();
    obj.SetPenRed(R);
    obj.SetPenGreen(G);
    obj.SetPenBlue(B);
    //obj.DEFAULT();
    //string load;
    //cout<<"Enter a file to load: ";
    //cin>>load;
    //obj.LoadImage(load);
    //int x1,y1=values();
    //x1,y1=obj.CheckCordinates(x1,y1);
    //obj.DrawPixel(x1,y1);
    //int x2,y2=values();
    //x2,y2=obj.CheckCordinates(x2,y2);
    //obj.DrawLine(0,0,6,6);
    //obj.DrawRectangle(0,0,1,1);
    //string file;
    //cout<<"Enter a file: ";
    //cin>>file;
    //obj.SaveImage(file);
    //Loaded.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
