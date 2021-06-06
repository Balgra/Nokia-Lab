#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<ostream>
#include<set>
#include<list>
#include<forward_list>
#include<map>
#include<chrono> // this is used for high_resolution_clock

using namespace std;

//Write a variadic template function that calculate the maximum of its parameter
/*
template <typename T> 
T Maxfct(T elem1,T elem2)   // calculating maximum between 2 numbers each time.
{
   if (elem1>elem2)
      return elem1;
   else
      return elem2;
}

template <typename T, typename ... Args>
T Maxfct(T arg1, T arg2, Args ... args)
{
   return Maxfct(Maxfct(arg1,arg2),args...); // taking the numbers one by one it can calculate the maximum.
}

int main()
{
	cout<<Maxfct(5,6,7,2)<<endl;
	cout<<Maxfct(5,3,10,2)<<endl;
}*/

//Write a variadic template function that calculate the square parameter’s sum from i=0 to n with i*i;

/*
template <typename T> 
T squareParam(T argument)   // calculating the squared value using pow.
{
   return pow(argument,2); // pow function taken from math.h library.
}

template <typename T, typename ... Args>
T squareParam(T arg, Args ... args)
{
   return pow(arg,2) + squareParam(args...); // taking the numbers one by one it can calculate square and add it to the final sum
}

int main()
{
	cout<<squareParam(5,6,7,2)<<endl;
	cout<<squareParam(5,3,10,2)<<endl;

	for(int i=0;i<10;i++)
	{
		cout<<"The sum for "<<i<<" "<<i+1<<" "<<i+2<<" "<<i+3<<" "<< "is "<<squareParam(i,i+1,i+2,i+3);
		cout<<endl;
	}

	return 0;
}
*/

//Write a variadic template function that return true if the value of every even parameter is lower than the value of the parameter on the next position.

/*
template <typename T> 
T Minim(T elem1, T elem2)   // calculating minimum between 2 numbers each time.
{
   if (elem1 < elem2)
   {
   		return true;
   }
   else
   {
   		return false;
   }
}

template <typename T> 
T Minim(T elem)
{
	return 0;
}


template <typename T, typename ... Args>
T Minim(T arg1, T arg2, Args ... args)
{
	if(!(Minim(arg1,arg2)))
	{
		return false;
	}
	
	
   return Minim(args...);
}

int main()
{
	cout<<"The value is: "<<Minim(1,2,1,3,1,3,4.4,4.5)<<endl; // is ok
	cout<<"The value is: "<<Minim(1,2,3,4,2,5,'a','e')<<endl; // is ok
	cout<<"The value is: "<<Minim(1.1,2.2,4,0,10,20)<<endl; // is 0 since 4 is bigger than 0
	cout<<"The value is: "<<Minim(6,9,8,9,5.5,5.6,4)<<endl; // Even though giving an uneven number of elements is not good, the program will still evaluate 
	// correctly the values, but since the last element doesn't have a "colleague" it  yields 0/
	cout<<"The value is: "<<Minim(2)<<endl;
}
*/



//Write a Fibo function as constexpr and measure the time of Fibo(40) as constexpr/ non constexpr value.

/*
constexpr long FibonacciExpr(long long  n)
{

    if(n<0)
    {
    	return -1;
    }
    else
    {
    	if(n==0)
    	{
    		return 0;
    	}
    	if(n==1 || n==2)
    	{
    		return 1;
    	}
    	else
    	{
    		return FibonacciExpr(n-1) + FibonacciExpr(n-2);
    	}
    }
}


long fibonacciExpr(long long  n)
{

    if(n<0)
    {
    	return -1;
    }
    else
    {
    	if(n==0)
    	{
    		return 0;
    	}
    	if(n==1 || n==2)
    	{
    		return 1;
    	}
    	else
    	{
    		return FibonacciExpr(n-1) + FibonacciExpr(n-2);
    	}
    }
}



int main()
{
	cout<<"All the results are in MicroSeconds "<<endl;

	// function call of the constexpr function which will calculate Fibonacci of 30 when 
	auto start = chrono::high_resolution_clock::now(); 

	FibonacciExpr(40); 
	
	auto stop = chrono::high_resolution_clock::now();

	auto duration = (stop - start);

	cout << duration.count() << endl;
	// for me the value of this call is around 200-400 microseconds When we have Fibo(7);
	// When Fibo(30) is called the value is 5968600 microseconds




	// function call of the "normal" function which will calculate fibonacci of 30 

	auto start1 = chrono::high_resolution_clock::now(); 

	cout <<fibonacciExpr(40)<<" <-Result of Fibo(30)  and it's time ";

	auto stop1 = chrono::high_resolution_clock::now();

	auto duration1 = (stop1 - start1);
	
	cout << duration1.count() << endl; 
	// for me the value of the call is around 1000 microseconds When having fibo(7);
	// When fibo(30) is called the value is 5460700 microseconds.


	// function call of the "normal" function which will calculate Fibonacci of 30 
	// the function is one declared as constexpr (even tho we call it and print the result)

	auto start2 = chrono::high_resolution_clock::now(); 

	cout << FibonacciExpr(40)<< " <-Result of Fibo(30)  and it's time ";

	auto stop2 = chrono::high_resolution_clock::now();

	auto duration2 = (stop2 - start2);
	
	cout << duration1.count() << endl; 

	// for me the value of this call is around 1000 microseconds
	//When fibo(30) is called the value is 5460700 microseconds.
	// it is expected that the value of Fibo(30)[The function declared as constexpr] and fibo(30) the normal function to be equal/
	// Having the "cout" before the call of the constexpr Fibo makes it just as a normal function.


	// One final conclusion is that when having to deal with such big numbers once every 5 runs (approximately), the 
	// time of the call of constexpr Fibo is actually lower than the other two. For Fibo(30).

	// Even for Fibo of 40 it's still the same conclusion somtime it is slower. But we can see the fact that it takes
	// a few seconds when compilling.



   return 0;

}
*/

//This algorithm should work with all STL containers
//Write an algorithm that calculate the harmonic media.
//  with some containers cannot be used like map or pop stack and so on. but for the ones in the example they work.
/*
template <typename ContainerT>
double avgHarmonic(ContainerT& container)
{
    double sum = 0;
    int counter = 0;
    for (auto i = container.begin(); i != container.end(); i++)
    {
        sum += (float)1 / *i;
        counter++;
    }   

    return (double)counter / sum;
}


int main() 
{
    vector<int> Vector = { 14,16,8,25,26 };
    cout<< avgHarmonic(Vector) << endl;

    set<int> Set = { 7,10,5,2,100 };
    cout<< avgHarmonic(Set)<<endl;

	list <int> List= {6,3,5,10,15};

	cout<<avgHarmonic(List)<<endl;

	forward_list<int> ForwardList;

	ForwardList.assign({16,16,20,1,3,5});

	cout<<avgHarmonic(ForwardList)<<endl;


    return 0;
}
*/