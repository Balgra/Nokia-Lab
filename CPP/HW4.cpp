/*#include<iostream>
#include<tuple>
#include<vector>

int main()
{

	std::tuple<int,char>foo(10,'x');
	auto bar= std::make_tuple("test",3.1, 14, 'y');

	std::get<2>(bar)=100;

	int myint; char mychar;

	std::tie(myint, mychar)=foo;

	printf("%d %c \n",myint, mychar);

	std::tie(std::ignore, std::ignore, myint, mychar)=bar;

	mychar= std::get<3>(bar);

	std::get<0>(foo)=std::get<2>(bar);
	std::get<1>(foo)=mychar;

	std::cout<<"foo cointains: ";
	std::cout<<std::get<0>(foo)<<' ';
	std::cout<<std::get<1>(foo)<<'\n';*/






/*Implement a database with 5 entries representing characteristics of your favourite objects.
NOTE: There must be at least 5 characteristics.

Search the database for your most favourite object by the characteristic you like the most
*/
/*#include<iostream>
#include<string>
#include<vector>

struct FavObj
{
	int age;
	int size;
	int weight;
	int height;
	int price;
};

std:: ostream& operator<<(std::ostream& stream, const FavObj& vertex)
{
	stream<< vertex.age << ", " <<vertex.size << ", " <<vertex.weight<< ", " <<vertex.height << ", " <<vertex.price<< ".";
	return stream;
}

int main()
{
	std::vector<FavObj>vector;
	int age,size,weight,height,price;
  std::cout<<"how many elements does the vector should have?"<<std::endl;
  int n;
  std::cin>>n;

  for(int i=0;i<n;i++)
  {
     std::cout<<"enter the characteristics: age, size, weight, height, and price "<<std::endl;
     std::cin>> age >> size >> weight>>height >>price;
 	 vector.push_back({age, size, weight, height, price});
  }

  for(unsigned i=0; i<vector.size();i++)
  {
  	 std::cout<<"v["<<i<<"] is equal with these specifications: ";
  	 std::cout<<"age: "<<vector[i].age<<" size: "<<vector[i].size<<" weight: "<<vector[i].weight<<" height: "<<vector[i].height<<" price: "<<vector[i].price<< std::endl;
  }


  for(unsigned i=0; i<vector.size(); i++)
  {
  	if(vector[i].price<10 && vector[i].age>5 && vector[i].size<20 && vector[i].weight<100 && vector[i].height==10)
  	{
  		std::cout<<"My favorite object has these specifications: ";
  	 	std::cout<<"age: "<<vector[i].age<<" size: "<<vector[i].size<<" weight: "<<vector[i].weight<<" height: "<<vector[i].height<<" price: "<<vector[i].price<< std::endl;
  	}
  }
}
*/



/*Make a vector of pairs (ints);
2Sort the vector by the first element in the pair;
3Replace the odd pairs with zero on the second element;*/

/*
#include<iostream> 
#include<vector>
  
int main() 
{ 
    //declaring vector of pairs 
    std::vector<std::pair <int,int> > vect; 

  	int elem1,elem2;
  	int n;
  	std::cout<<"how many elements do you want in your vector of pairs?"<<std::endl;
  	std::cin>>n;
    for (int i=0; i<n; i++) 
    {	
    	std::cout<<("Give the elements of the vector of pairs, 2 decimals")<<std::endl;
       	std::cin>>elem1>>elem2;
        vect.push_back( std::make_pair(elem1,elem2) ); 
    }
  
  	std::cout<<"The vector looks like this"<<std::endl;
    for (int i=0; i<n; i++) 
    { 
        std::cout << vect[i].first << " "<< vect[i].second <<std::endl; 
    } 
  
    std::cout<<"The vector after the sorting acendingly by the 1st element"<<std::endl;
    int aux;
    for (int i=0; i<n-1; i++) 
    { 
    	for(int j=i;j<n;j++)
    	{
    		if(vect[i].first>vect[j].first)
    		{
    			aux=vect[i].first;
    			vect[i].first=vect[j].first;
    			vect[j].first=aux;
    		}
    	}

    } 

     for (int i=0; i<n; i++) 
    { 
        std::cout << vect[i].first << " "<< vect[i].second <<std::endl; 
    } 

    std::cout<<"Replacing the odd pairs with 0 on the second element"<<std::endl;
    for (int i=0; i<n; i++) 
    { 
    	if(i%2==1)
    	{
    		vect[i].second=0;
    	}
    } 

    for (int i=0; i<n; i++) 
    { 
        std::cout << vect[i].first << " "<< vect[i].second <<std::endl; 
    } 


      return 0; 
}*/


/*#include<iostream>
#include<vector>
#include<string>

class Student
{
	public:
		Student();
		~Student();

	private:
		string Name;
		char Grade;

}

