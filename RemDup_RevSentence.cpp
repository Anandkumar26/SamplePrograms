#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
using namespace std::tr1;

//global variables to store hash map
unordered_map<string, int> ht;
unordered_map<string, int>::iterator it;
/*
* Function to reverse a string from start position to the number of elements
*/
void reverse(string &str,int start,int wordlen)
{
	char temp;
	int end = start+wordlen;
	for(int i=0; i<wordlen/2; i++)
	{
		temp = str[start+i];
		str[start+i]=str[start+wordlen-1-i];
		str[start+wordlen-1-i]=temp;
	}
}
void createword(string &str,int start,int end)
{
	int wordlen;
	wordlen = end-start;
	string s;
	if(end == str.length()-1 && str[end] != ' ')//end case
		wordlen++;
	
	reverse(str,start,wordlen);
}
/*
* Function to reverse sentenece
* Does Inplace - replacement
*/
void reverse_sentence(string &str)
{
	int start=-1,end=0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == ' ' || i== str.length()-1)
		{
			createword(str, start,i);
			start = i+1;
		}
		else
		{
			if(start == -1)
			  start = i;
		}

	}
	reverse(str,0,str.length());
}
/*
* Function to remove duplicates from an input array using HashMap
* Does Inplace - replacement
*/
void removedup(int a[],int &len)
{
	map<int,int>ht;
	map<int,int>::iterator it = NULL;
	for(int i=0;i<len;i++)
	{
		it = ht.find(a[i]);//find by key or value
		if(it == ht.end())
			ht[a[i]]=i;//add an element to hashtable
		else
		{
			cout<<"Duplicate element : "<<it->first<<endl;
			for(int index = i;index<len-1;index++)
				a[index]=a[index+1];
			len--;
			i--;
		}
	}
}
/*
* Function to print elements of an array
*/
void printelements(int a[],int len)
{
	cout<<"The elements are : "<<endl;
	for(int i=0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
/*
* Main function
*/
int main()
{
	int a[]={10,11,12,23,14,8,11,10};
	int size = sizeof(a)/sizeof(int);
	printelements(a,size);
	removedup(a,size);
	printelements(a,size);
	
	// reverse sentence
	string str = "This is a sentence and this is a word ";
	cout<<str.c_str()<<endl;
	reverse_sentence(str);
	cout<<str.c_str()<<endl;
	return 1;
}
