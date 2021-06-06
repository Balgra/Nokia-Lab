#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<ostream>

using namespace std;


/*Exercise 1 Write a class MyString which has only one private member: a char*.
Write in this class a copy constructor and copy assignment operator, a move constructor and move assignment operator and a concatenate function.
*/

class Mystring{
public:

	// basic constructor
	Mystring(char *ch)
	{
		string = new char[strlen(ch)+1]; // making enough space for the string. 

		strcpy(string,ch);
	}

	// printing function to be easily to see the result
	virtual void printString()
	{
		cout<<string<<endl;
	}

	//copy constructor
	Mystring(const Mystring& str)
	{
		//cout<<str.string;
		string = new char[strlen(str.string)+1];

		strcpy(string,str.string);
	}

	//copy assigment operator
	Mystring& operator=(const Mystring& str)
	{
		if(&str!=this)
		{
			if(string)
			{
				delete[] string;
			}

			string = new char[strlen(str.string)+1];

			strcpy(string,str.string);
			
		}

		return*this;
	}

	//move constructor
	Mystring(Mystring&& str)
	{
		string=move(str.string);

		str.string=nullptr;// setting the pointer to null.
	}

	//move assigment operator
	Mystring& operator=(Mystring&& str)
	{
		if(&str != this)
		{
			if(string)
			{
				delete[] string;
			}

			string=move(str.string);

			str.string=nullptr; // setting the pointer to null.
		}

		return *this;
	}

	//function for concaternating 

	void concaternate(const Mystring& str)
	{
			char *string2=new char[strlen(str.string) + strlen(string)+1];

			strcpy(string2,string);
			strcat(string2,str.string);
			string = new char[strlen(string2)+1];
			strcpy(string,string2);

			//free(string2);
			delete[] string2;
	}

	~Mystring()
	{delete[] string;}

private:
	char *string;

};

int main()
{

	// i have used a char pointer (a) so it is more easily to use the pointers to chars.
	// I have used this insted of Mystring str1("ana") so it would have no errors.
	// because C++ forbids converting a string constant to ‘char*’
	char *a=(char *)malloc(50 * sizeof(char));
	strcpy(a,"ana");
	Mystring str1(a);
	Mystring str2=str1; // copy constructor

	strcpy(a,"mere");
	Mystring str3(a);
	str3 = str1; // copy assignment constructor.

	vector<Mystring> strings;
	strcpy(a,"mere");
	strings.push_back(Mystring(a)); // moveconstructor

	strcpy(a,"multe mere");
	Mystring str4(a); // move assigment operator

	strcpy(a,"multe pere");
	str4 = Mystring(a);

	str1.printString();
	str2.printString();
	str3.printString();
	strings[0].printString();
	str4.printString();

	str1.concaternate(str4); // function
	str1.printString();
}

/*
Use inheritance to simulate the following construction of the triangle:
Equilateral :base class for Isosceles,
Isosceles: base class for Triangle
Write in each class the formula for perimeter and aria
Annotation: Equilateral has only one side, Isosceles has 2 sides (one inheritance from Equilateral) and Triangle has 3 sides (2 inheritance from Isosceles)
You should test these classes in this way:
*/
//SideE -> side of the Equilateral Triangle
//SideI ->Base of the Isosceles Triangle
//SideT ->Random vertix.

/*	 Made a function to test if the triangles are ok, in case somebody does not put the right input.*/
/*
class Equilateral{
public:

	Equilateral(int LineGiven) : SideE(LineGiven)
	{}

	virtual int CheckTriangle()
	{
		if(SideE==0)
		{
			cout<<"We can't compute inexistent triangle"<<endl;
			return 0;
		}

		return 1;
	}
	virtual int perimeter()
	{
		return SideE*3;
	}

	virtual int aria()
	{
		return (pow(SideE,2) * sqrt(3) * 1/4);
	}

protected:
	int SideE;
};

//LineGivenI is the base of the triangle.
class Isosceles : public Equilateral{
public:

	Isosceles(int LineGivenE, int LineGivenI) : Equilateral(LineGivenE), SideI(LineGivenI) // calling constructor of Equilateral to have the SideE
	{}

	int CheckTriangle()
	{
		if(SideE==0 || SideI==0)
		{
			cout<<"We can't compute inexistent triangle"<<endl;
			return 0;
		}
		if(SideE+SideE<SideI || SideI+SideE<SideE)
		{
			cout<<"This is not a triangle, try again"<<endl;
			return 0;
		}

		return 1;
	}

	int perimeter()
	{

		return (SideE*2 + SideI);
	}

	int aria()
	{
		//cout<<(SideE*2 + SideI)/2<<endl<<((SideE*2 + SideI)/2)-SideE<<endl<<(((SideE*2 + SideI)/2)-SideI)<<endl; // checking if the numbers given are correct.
		return (sqrt( ((SideE*2 + SideI)/2) * (((SideE*2 + SideI)/2)-SideE) * (((SideE*2  + SideI)/2)-SideE) * (((SideE*2 + SideI)/2)-SideI) ) );
	}
protected:
	int SideI;
};


class Triangle : public Isosceles{
public:
	// calling isosceles constructor which will call the Equilateral constructor at this time.
	Triangle(int LineGivenT, int LineGivenI1, int LineGivenI2) : SideT (LineGivenT), Isosceles(LineGivenI1, LineGivenI2)
	{}

	int CheckTriangle()
	{
		if(SideE==0 || SideI==0 || SideT==0)
		{
			cout<<"We can't compute inexistent triangle"<<endl;
			return 0;
		}
		if(SideT+SideE<SideI || SideI+SideE<SideT || SideI+SideT<SideE)
		{
			cout<<"This is not a triangle, try again"<<endl;
			return 0;
		}

		return 1;
	}

	int perimeter()
	{
		return (SideE + SideI + SideT);
	}

	int aria()
	{
		return (sqrt( ((SideT + SideI + SideE)/2) * (((SideT + SideE + SideI)/2)-SideT) * (((SideT + SideE + SideI)/2)-SideE) * (((SideT + SideE + SideI)/2)-SideI) ));         
	}

protected:
	int SideT;
};


void write(Equilateral *p)
{
	if(p->CheckTriangle())
	{
		cout<<"perimeter: "<<p->perimeter()<<endl;

		cout<<"aria: "<<p->aria()<<endl;
	}
}

int main()
{
	Equilateral eq(10);
	write(&eq);
	Isosceles is(4,5); // first value are actually the sides, and the second value is the base of the triangle.
	write(&is);
	Triangle tr(3,4,5);// the numbers are random they can be given in any order.
	write(&tr);
}

*/



/*Exe 3 Use a abstract class Shape who has a write function which writes the perimeter and area. 
This abstract class has one member side. Derived from this class 3 objects:
Triangle, Square and Hexagon who override the 2 abstract function from Shape: perimeter and aria.*/
// we can put return in a void function because it sends a signal to the shell to signal that this program shall terminate here.
// base class which has the function and the member side.
// by default is an abstract class
// all functions have destructors to have proper memory allocation.
// Testing if the triangle/ square/ hexagon have edges == 0 (if so send an error message)
/*
class baseClass {
public:
	int side;
    virtual void write()
    {
    }

    virtual ~baseClass()
    {}
};

// we take into account that the triangle is equilateral.
// so we can easily calculate the area.
class Triangle : public baseClass {
public: 

	Triangle(int line)
	{
		side=line;
	}

	~Triangle()
	{}

    void write()
    {
    	if(side==0)
    	{
    		cout<<"Can not compute perimeter and area of a triangle with edges == 0"<<endl;
    		return;
    	}
         cout<<"The area of Triangle is "<<pow(side,2) * sqrt(3) * 1/4<<endl;
   		 cout<<"The perimeter of the Triangle is "<<side * 3<<endl;
   		 return;
    }
 
};

// calculating the square having the baseClass extended
class Square : public baseClass {
public: 

	Square(int line)
	{
		side=line;
	}

	~Square()
	{}

    void write()
    {
    	if(side==0)
    	{
    		cout<<"Can not compute perimeter and area of a square with edges == 0"<<endl;
    		return;
    	}
         cout<<"The area of Square is "<<pow(side,2)<<endl;
   		 cout<<"The perimeter of the Square is "<<side*4<<endl;
   		 return;
    }
 
};

// calculating the square having the baseClass extended.
class Hexagon : public baseClass {
public: 

	Hexagon(int line)
	{
		side=line;
	}

	~Hexagon()
	{}

    void write()
    {
    	if(side==0)
    	{
    		cout<<"Can not compute perimeter and area of a hexagon with edges == 0"<<endl;
    		return;
    	}
         cout<<"The area of Hexagon is "<<6 * pow(side,2) * sqrt(3) * 1/4<<endl;
   		 cout<<"The perimeter of the Hexagon is "<<side*6<<endl;
   		 return;
    }
 
};

// main function from the presentation.

int main()
{
	Triangle tr(10);
	tr.write();

	Square sq(5);
	sq.write();

	Hexagon hx(5);
	hx.write();

}
*/