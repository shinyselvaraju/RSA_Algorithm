#include<iostream>
#include<math.h>
#include <fstream>
#include <conio.h>
using namespace std;
// find gcd
int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}

bool isPrime = true;

bool prime(long int num)
{
    for(int i = 2; i <= (num/2); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int calculate_e(int a)
{
    int i = 2;
    int e;
    while(gcd(i, a)!=1)
        i++;
    e = i;
    if ( e >= a){
        throw(runtime_error("greater than phi n"));
    }
    return e;
}
int main() {
    fstream my_file;
	my_file.open("my_file", ios::binary);
	if (!my_file) {
		cout << "File not created!\n";
	}
	else {
		cout << "File created successfully!";
		my_file.close();
	}
   //2 random prime numbers
   double p;
   double q ;
   cout << "Enter the value of p" << endl;
   cin >> p ;
    isPrime = prime(p);
    if (!isPrime)
    {
        cout << " P is Not Prime\n";
        exit(1);
    }
   cout << "Enter the value of q" <<endl;
   cin >> q ;
    isPrime = prime(q);
    if (!isPrime)
    {
        cout << " Q is Not Prime\n";
        exit(1);
    }
   double n=p*q;//calculate n
   double track;
   double phi= (p-1)*(q-1);//calculate phi

   //public key
   //e stands for encrypt
   double e= calculate_e(phi);
   //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
   while(e<phi) {
      track = gcd(e,phi);
      if(track==1)
         break;
      else
         e++;
   }
   //private key
   //d stands for decrypt
   //choosing d such that it satisfies d*e = 1 mod phi
   double d1=1/e;
   double d=fmod(d1,phi);
   double message;
   cout << "Enter message" << endl ;
   cin >> message ;
   double c = pow(message,e); //encrypt the message
   double m = pow(c,d);
   c=fmod(c,n);
   m=fmod(m,n);
   cout<<"Original Message = "<<message;
   cout<<"\n"<<"p = "<<p;
   cout<<"\n"<<"q = "<<q;
   cout<<"\n"<<"n = pq = "<<n;
   cout<<"\n"<<"phi = "<<phi;
   cout<<"\n"<<"e = "<<e;
   cout<<"\n"<<"d = "<<d;
   cout<<"\n"<<"Encrypted message = "<<c;
   cout<<"\n"<<"Decrypted message = "<<m;
   return 0;
}
