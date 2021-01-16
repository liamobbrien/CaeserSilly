#include <iostream>
#include <fstream>


using namespace std;
int getShift(int shift);
int main(){
	int numChars = 0;
	int cntr = 0;
	
	int max = 100000;
	int shift;
	int numArr[max];
	
	char arr[max];
	int plainText[max];
	char cipherText[max];
	
	const char ALPHA[26] = {'A', 'B', 'C', 'D', 'E', 'F','G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	const char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	
	shift = getShift(shift);
	
	
	cout << "Enter word or phrase to encipher; enter '@' to exit. " << endl;
	for(int i = 0; i < max; i++){
		cin >> arr[i];
		numChars = i;
			
		if(arr[i] == '@'){
			break;
			}
		}
	
	
	for(int i = 0; i < numChars; i++){
		for(int j = 0; j < 26; j++){
		
		if(arr[i] == ALPHA[j]){
			arr[i] = j;
			numArr[i] = j;
			
			//cout << ALPHA[(numArr[i] + shift) % 26];
			cipherText[cntr] = ALPHA[(numArr[i] + shift) % 26];
			cntr++;
			}
				
		else if(arr[i] == alpha[j]){
			arr[i] = j; 
			numArr[i] = j;
			
			//cout << ALPHA[(numArr[i] + shift) % 26];
			cipherText[cntr] = ALPHA[(numArr[i] + shift) % 26];	
			cntr++;	
			}
		}
		
	}
		
		cout << endl;
		
		ofstream myfile;
		myfile.open("cipher.txt");
		
		if(myfile.is_open()){
			cout << "File sucessfully opened! " << endl;
			}else{ 
				cout << "Could not open file. Exiting... ";
				exit(1);
				} 
		
		for(int i = 0; i < cntr; i++){
			myfile << cipherText[i];
				if((i % 5) == 0){
					myfile << " ";
					}
			}
			
		myfile.close();
		
		cout << endl <<"The total number of characters is: " << numChars << endl;
		cout << "The number of special characters removed is: " << numChars - cntr << endl;

}

int getShift(int shift){

	cout << "Enter shift value! " << endl;
	cin >> shift;

	if(shift == 26 || shift <= 0){
		cout << "Invalid shift value! Exiting... " << endl;
			exit(1);
	}else
		return (shift % 26);
}		
		


