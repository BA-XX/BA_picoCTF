// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void displayMenu(){
    std::cout << "--------    menu   --------" << std::endl;
    std::cout << "1. Encrypte " << std::endl;
    std::cout << "2. Decrypte " << std::endl;
    std::cout << "0. exit " << std::endl << std::endl;
    
    std::cout << "  your choice ? : " ;

}

std::string encrypt(const std::string &input , const unsigned char &shiftValue){
    
    std::string ciphertext = "";
    
    for(char c : input){
        
        if(c >= 'a' && c <= 'z') // lowercase chars
            ciphertext += charset[(c - 'a' + shiftValue) % 26]; // c - 'a' : position of the char in the charset
        else if (c >= 'A' && c <= 'Z') // uppercase chars
            ciphertext += charset[((c - 'A' + shiftValue) % 26) + 26];
        else 
            ciphertext += c;
    }
    
    return ciphertext;
}

std::string decrypt(const std::string &input , const unsigned char &shiftValue){
    
    std::string plaintext = "";
    
    for(char c : input){
        
        if(c >= 'a' && c <= 'z') // lowercase chars
            plaintext += charset[(c - 'a' - shiftValue + 26) % 26]; // c - 'a' : position of the char in the charset
        else if (c >= 'A' && c <= 'Z') // uppercase chars
            plaintext += charset[((c - 'A' - shiftValue + 26) % 26) + 26];
        else 
            plaintext += c;
    }
    
    return plaintext;
}

int main() {
    
    
    std::string input;
    unsigned int shiftValue;
    unsigned char choice;

    displayMenu();
    
    choice = std::cin.get();
    
    if(choice != '1' && choice != '2'){
        return 0;
    }
    
    std::cout << "Input : " ;
    std::cin >> input;
    std::cout << "Shift value : ";
    std::cin >> shiftValue;
    shiftValue = shiftValue % 26; // Ensure shiftValue is within range

    switch(choice){
        case '1':
            std::cout << encrypt(input,shiftValue) << std::endl;
        break;
        case '2':
            std::cout << decrypt(input,shiftValue) << std::endl;
        break;
    }

    return 0;
}
