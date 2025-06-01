/*1. Enter new string
2. Display length
3. Reverse string
4. Compare with another
5. Copy into another
6. Exit
Remove spaces from a string
Convert string to uppercase/lowercase
Count vowels & consonants
Check palindrome
*/
#include<iostream>
using namespace std;

//entry
char* entry(int n)
{
	cout<<"Enter str: ";
	char* temp = new char[n];
	
	cin.getline(temp,n);
	
	return temp;
}
//len
int str_lenth(char* string1,int n)
{
	int length = 0;
	for (int i=0 ;string1[i]!='\0';i++)
	{
		length++;
	}
	return length;
}
//reverse
char* reverse_string(char* string1,int n)
{
	char* temp = new char[n];
	int len = str_lenth(string1,n);
	int index=0;
	
	for (int i=len-1;i>=0;i--)
	{
		temp[index] = string1[i];
		index++;
    }
    temp[index] = '\0';
    return temp;
	
}

//compare
bool compare_strings(char* string1,char* inew,int n)
{
	int l1 = str_lenth(string1,n);
	int l2 = str_lenth(inew,n);
	if (l1==l2)
	{
		for ( int i=0;i<l1;i++)
		{
			if(string1[i]!=inew[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}
//copy
char* copy(char* string1,int n,bool choice=false)
{ 

int index=0;
	char* temp = new char[n];
if(!choice){
	for(int i=0;string1[i]!='\0';i++)
	{
		temp[i] = string1[i];
		index++;
	}
	}
	else
	{
		for (int i=0;string1[i]!='\0';i++)
		{
			if(string1[i]!=' '){
		
			temp[index] = string1[i];
			index++;
				}
		}
	}
    temp[index] = '\0';
	return temp;
}
//uper lower
void to_upper(char* string1,int n)
{
	for (int i=0; string1[i]!='\0';i++)
	{
		if (string1[i]>=97 && string1[i]<123)
		{
			string1[i] = string1[i]-32;
		}
	}
}
//lower
void to_lower(char* string1,int n)
{
	for (int i=0; string1[i]!='\0';i++)
	{
		if (string1[i]>=65 && string1[i]<91)
		{
			string1[i] = string1[i]+32;
		}
	}
}
//plandorime
bool plan(char* string1,int n){
	char* temp= copy(string1,n);
    to_lower(temp,n);
    char* store=copy(temp,n,2);
    char* store_reverse=reverse_string(store,n);
    bool c= compare_strings(store,store_reverse,n);
    delete[] temp;
    delete[] store;
    delete[] store_reverse;

    return c;
    

}
//vowel
int che(char c){
	if(c=='a'||c=='e'||c=='o'||c=='i'||c=='u'||c=='A'||c=='E'||c=='O'||c=='I'||c=='U'){
		return 1;
	}else if(c>='0'&&c<='9'){
		return 2;
	}else if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
		return 3;
	}else{
		if(c!=' '){
			return 4;
		}else{
			return 5;
		}
		
	}
}
//counting vowel
void count(char* str){
	int c=0,v=0,n=0,s=0,sp=0,d;
	for(int i=0;str[i]!='\0';i++){
		d=che(str[i]);
		if(d==1){
			v++;
		}else if(d==2){
			n++;
		}else if(d==3){
			c++;
		}else if(d==4){
			s++;
		}else{
			sp++;
		}
	}
	cout<<"Number of vowels is:\t"<<v<<"\n";
	cout<<"Number of conunetnts is:\t"<<c<<"\n";
	cout<<"Number of numbers is:\t"<<n<<"\n";
	cout<<"Number of special is:\t"<<s<<"\n";
	cout<<"Number of spaces is:\t"<<sp<<"\n";
}
int main(){
char button;
int n;
cout<<"Enter size of string: ";
cin>>n;
cin.ignore();
char* string1 = new char[n];
bool flag = true;
while(flag)
{
cout << "\n===== STRING OPERATIONS MENU =====\n";
cout << "1.  Enter new string\n";
cout << "2.  Display length\n";
cout << "3.  Reverse string\n";
cout << "4.  Compare with another string\n";
cout << "5.  Copy into another string\n";
cout << "6.  Remove spaces from string\n";
cout << "7.  Convert to UPPERCASE(1) / lowercase\n";
cout << "8.  Count vowels, consonants, digits, special chars\n";
cout << "9.  Check if string is a palindrome\n";
cout << "E.  Display current string\n";
cout << "C.  Credit to developers\n";
cout << "H.  Exit program\n";
cout << "===================================\n";
cout << "Enter your choice: ";


cin>>button;
cin.ignore();
switch(button)
{
	case '1':
			delete[] string1;
            string1 = entry(n);

		break;
	case '2':
		{
		
		int len = str_lenth(string1,n);
		cout<<"Lenght of string is: "<<len<<endl;
	}
		break;
		
	case '3':
		{
		
		char* reverse;
		reverse = reverse_string(string1,n);
		cout<<"Revese string: "<<reverse<<endl;
	}
		break;
	case '4':
		{
		
			char* inew;
			inew = entry(n);
		    bool same = compare_strings(string1,inew,n);
		    if (same)
		    {
		    	cout<<"String are same"<<endl;
			}
			else
			{
				cout<<"String are not same"<<endl;
			}
	}
		break;
	case '5':
		{
		
		char* cp_str;
		cp_str = copy(string1,n);
		cout<<"Copy string : "<<cp_str<<endl;
		
		
		
	}
		break;
	case '6':
		{
			char* spacefree;
			
			spacefree=copy(string1,n,true);
			cout<<"without spacess:  "<<spacefree<<endl;
			
			delete[] spacefree;
		}
		break;
	case '7':
		{
			cout<<"YOu eant upper or lower(1 upper):";
			cin>>button;
			
			if (button == '1')
			{
				to_upper(string1,n);
			}
			else
			{
				to_lower(string1,n);
			}
				
			cout<<"Modified string: "<<string1<<endl;
			
		}
		break;
	case '8':
		{
		count(string1);	
		}
		break;
	case '9':
		bool isPalindrome;
        isPalindrome = plan(string1, n);

		if(isPalindrome){
		cout<<"your str is plaimdrome!"<<endl;
		}else{
		cout<<"your str is not plaimdrome!"<<endl;	
		}
		break;
	case 'c':
	case 'C':
	cout<<"Code & desing by Miksi and Brand babu with love (github: miksi0078\tEjaz-Ahmed838) \n(phone:+923435411474)"<<endl;
	    break;	
	case 'y':
	case 'Y':	
		{
			
		}
		break;
		
	case 'h':
	case 'H':			
			flag = false;
			
		break;
	case 'e':
	case 'E':	
		{
			cout<<"your str is: "<<string1<<endl;
			
		}
		break;	
	default:
		cout<<"Enter valid option"<<endl;
		break;
	
	
}
	
	
	
}
	
	delete[] string1;
	return 0;
}
