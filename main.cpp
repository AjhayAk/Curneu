#include <bits/stdc++.h>
#include<thread>
#include <fstream>
#include<stdio.h>
using namespace std;

int KEYGENERATOR=100000;
// tripledata class with encrypt() and
// decrypt() member functions
class tripledata  {
	int key;

	// File name to be encrypt
	string file = "3Dmodel.obj";
	char c;

public:
	void encrypt();
	void decrypt();
};
void tripledata::encrypt()
{
   //3DES Encryption  - ( file + Key 1 = Cipher Text 1 ) + ( Cipher Text 1 - Key 2 = Cipher Text 2 ) + ( Cipher Text 2 + Key 3 = Cipher Text 3 )
                                // encrypt (key 1)                   decrypt (key 2)                            encrypt (key 3)
	cout << "\n Type in the key for 3DES Encryption: "; // Encryption Key
	cin >> key;
	fstream fin, fout;
	int temp;
	fin.open(file, fstream::in);
	fout.open("encrypt.txt", fstream::out);
	while (fin >> noskipws >> c)
		temp = (c + key); //Cipher Text1
    int key2 = KEYGENERATOR - (key);
    while (fin >> noskipws >> c)
        temp = (c - key2); //Cipher Text2
    int key3 = KEYGENERATOR - (key2);
    while (fin >> noskipws >> c) {
        temp = (c + key3);//Cipher Text3
		//Generating Output File
		fout << (char)temp;
	}
	fin.close();
	fout.close();
}


// Definition of decryption function
void tripledata::decrypt()
{
    //3DES Decryption  - ( file - Key 1 = Cipher Text 1 ) + ( Cipher Text 1 + Key 2 = Cipher Text 2 ) + ( Cipher Text 2 - Key 3 = Cipher Text 3 )
                                    // decrypt (key 1)                   encrypt (key 2)                      decrypt (key 3)
	cout << "\n Type in the key for 3DES Decryption: "; //Decryption Key
	cin >> key;
	fstream fin;
	fstream fout;
	int temp;
	fin.open("encrypt.txt", fstream::in);
	fout.open("decrypt.txt", fstream::out);
	while (fin >> noskipws >> c)
		 temp = (c - key); //Cipher Text1
    int key2 = KEYGENERATOR - (key);
    while (fin >> noskipws >> c)
		 temp = (c + key2); //Cipher Text2
    int key3 = KEYGENERATOR - (key2);
    while (fin >> noskipws >> c) {
		 temp = (c - key3);//Cipher Text3
		//Generating Output File
		fout << (char)temp;
	}
	fin.close();
	fout.close();
}
//Main Code
int main()
{
	tripledata enc;
	char opt;
	cout << "\n\n\nEnc/dec the 3d obj file? : \n";
	cout << " e -> encrypt \n";
	cout << " d ->  decrypt \n";
    cin>>opt;
	cin.ignore();

	switch (opt) {
	case 'e': {
		enc.encrypt();
		break;
	}
	case 'd': {
		enc.decrypt();
		break;
	}
	}
}
