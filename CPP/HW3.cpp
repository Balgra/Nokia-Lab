/*
//lab 2 slide 4;
#include <iostream>

class Human
{
	public :
		Human()=default; // constructor
		~Human()=default; // destructor
		std::string name;
		int age;

};

int main()
{
	// with a variable
	int var=10;

	auto pol=var;

	std::cout<<pol<<std::endl;

	// with pointers
	int *b,c;

	c=7;
	b=&c;

	auto p=b;

	std::cout<<*p<<" "<<*b<<std::endl;


	// with classes
	Human x;
	x.age=10;
	x.name="alex";

	auto a=x;

	std::cout<<"The age of (a) : "<<a.age<<" The name(a) :  "<<a.name<<std::endl;
	std::cout<<"Adress of age (a): "<<&a.age<<" Adress of name (a): "<<&a.name<<" Adress of a in general: "<<&a<<std::endl;
 
	return 0;
}*/

// lab 2 slide 6;
/*#include<iostream>

struct cars
{
	int weigth;
	int age; 
	int heigth;

};

int main()
{
    int i;
 	//const int c=10;
 	auto c=10;
 	std::cout<<"value of c "<<c<<std::endl;

 	//const int &cri=i;
 	auto &cri=i;
 	std::cout<<"value of cri "<<cri<<std::endl;

    //const struct cars*p =new cars();
 	auto *p=new cars();

 	p=(struct cars*)malloc(sizeof(struct cars));

 	std::cout<<"the weigth "<<p->weigth<<" The age "<<p->age<<" heigth "<<p->heigth<<std::endl;

 	//it is 0 everywhere because of the const, we can;t modify it and also because of the memory allocation

 	// It works just fine with the auto because the function knows the declaration type of the value assigned.

	return 0;
}*/

//lab 2 slide 9
/*
#include<iostream>

class biscuits
{
	public :
	
		int width;
		int heigth;
		constexpr int weigth(int x, int y)
		{
			return (x*y);
		}

	
};

int main()
{

	class biscuits *oreo=new biscuits();

	oreo=(class biscuits *)malloc(sizeof(class biscuits));

	oreo->width=20;
	oreo->heigth=30;

	//weigth(oreo->width,oreo->heigth);

	std::cout<<"the area of the biscuit: "<<oreo->weigth(oreo->width,oreo->heigth)<<std::endl;

	
	//	After we calculate a certain length of an object or the area of it
	//	We then use it, as it is, for instance to put some buildings in that area
	//	since the area has only a value, the function calculating that can be a constant one
	

	return 0;

}*/


// lab 2 slide 12

#include<iostream>
#include<string>
#include<vector>

struct coordinates
{
	int x;
	int y;
	int z;
};

std:: ostream& operator<<(std::ostream& stream, const coordinates& vertex)
{
	stream<< vertex.x << ", " <<vertex.y << ", " << vertex.z;
	return stream;
}

int main()
{
	std::vector<coordinates>vector;
	int x,y,z;
  std::cout<<"how many elements does the vector should have?"<<std::endl;
  int n;
  std::cin>>n;

  for(int i=0;i<n;i++)
  {
     std::cout<<"enter the coordinates (3) "<<std::endl;
     std::cin>> x >> y >> z;
 	 vector.push_back({x, y, z});
  }

  for(unsigned i=0; i<vector.size();i++)
  {
  	 std::cout<<"v["<<i<<"] is equal with: ";
  	 std::cout<<vector[i]<< std::endl;
  }

  unsigned counter=0,verif;
  verif=vector.size();// i use verif, for the erasing of odd elements 
  //because i needed an index to show me how many elements were at first
  // and how many i have now, after i erased some(unsing counter i know how many elemente are left)
  //for example verif-counter=nr elements left in vector;

   for(unsigned i=0; i<vector.size();i++)
  {
  	 if(vector[i].x % 2!=0 && vector[i].y % 2!=0 && vector[i].z % 2!=0)
  	 		{
  	 			vector.erase(vector.begin()+i);
  	 			i--;
  	 			counter++;
  	 		}
  }

  std::cout<<"After we erase the odd elements:"<<std::endl;

  //std::cout<<counter<< " ";

  if(counter!=verif)
  	{	
  		for(unsigned i=0; i<vector.size(); i++)
  		{
  			 std::cout<<"v["<<i<<"] is equal with: ";
  			 std::cout<<vector[i]<< std::endl;
  	 	}
    }
   else
   {
   	 std::cout<<"there are no elements left :( ";
   }

   std::cout<<"After replacing the first and second element "<<std::endl;

   	std::cout<<"enter the coordinates (3) for the last element to be replaced "<<std::endl;
    std::cin>> x >> y >> z;
 	vector.back()={x, y, z};

 	std::cout<<"enter the coordinates (3) for the first element to be replaced "<<std::endl;
    std::cin>> x >> y >> z;
 	vector.at(0)={x, y, z};

  //erasing the fifth element, if all the coordinates are even;

  	 if(vector[4].x % 2==0 && vector[4].y % 2==0 && vector[4].z % 2==0)
  	 		{
  	 			vector.erase(vector.begin()+4);
  	 		}

  	for(unsigned i=0; i<vector.size(); i++)
  	{
  		 std::cout<<"v["<<i<<"] is equal with: ";
  		 std::cout<<vector[i]<< std::endl;
  	 }


   return 0;
}