#ifndef CAESAR_H
#define CAESAR_H

#include <iostream>
#include <fstream>
#include <string>

class Caesar
{
public:
    Caesar();
    ~Caesar();
    std::string getMessage() const;
    void encrypt(std::string& , ushort);
    void decrypt(std::string& , ushort);
private:
    std::fstream normalText;
    std::fstream decodedText;
    std::string _message{};
};


Caesar::Caesar()
{
    std::string path1 = "normalText.txt";
    std::string path2 = "decodedText.txt";
    normalText.open(path1);
    decodedText.open(path2);
    if(normalText.is_open() && decodedText.is_open())
    {
        ushort choice = 0;
        std::cout << "========================";
        std::cout << "\n\tMain Menu\t" << std::endl;
        std::cout << "========================\n";
        std::cout << "[1] Encrypt the text\n[2] Decrypt the text\n[3] Exit" << std::endl;
        do
        {
            std::cout << "Enter your choice [*]\b\b";
            std::cin >> choice;
        } 
        while (choice > 3);

        ushort key;
        std::cout << "Enter the key for encrypting/decrypting the text [*]\b\b";
        std::cin >> key;
        std::string message{};
        std::cout << "Please enter the message : ";
        std::cin.ignore();
        std::getline(std::cin , message);
        this -> _message = message;
        switch (choice)
        {
        case 1:
            encrypt(message , key);
            break;
        case 2:
            decrypt(message , key);
            break;
        case 3:
            std::cout << "You closed the app...!\n" << std::endl;
            exit(0);
            break;
        }
        
    }
    else
    {
        std::cout << "\tFile is not open !" << std::endl;
    }
}

Caesar::~Caesar()
{
    normalText.close();
    decodedText.close();
}

std::string Caesar::getMessage() const
{
    return _message;
}

void display()
{
    Caesar Julius;
}

void Caesar::decrypt(std::string& message , ushort key)
{
    const int letterCount = 26;
    decodedText << message + "\n";
    for(int i = 0; i < message.length(); ++i)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            if(message[i] - key >= 'a')
            {
                message[i] -= key;
            }
            else
            {
                message[i] -= key + letterCount;
            }
        }
        if(message[i] >= 'A' && message[i] <= 'Z')
        {
            if(message[i] - key >= 'A')
            {
                message[i] -= key;
            }
            else
            {
                message[i] -= key + letterCount;
            }
        }
    }
    std::string str{message};
    normalText << str + "\n";
}

void Caesar::encrypt(std::string& message , ushort key)
{
    const int letterCount = 26;
    normalText << message + "\n";
    for(int i = 0; i < message.size(); ++i)
    {
        if (message[i] >= 'a' and message[i] <= 'z')
        {
            if (message[i] + key <= 'z')
            {
                message[i] += key;
            }
            else
            {
                message[i] += key - letterCount;
            }    
        }
        else if (message[i] >= 'A' and message[i] <= 'Z')
        {
            if(message[i] + key <= 'Z')
            {
                message[i] += key;
            }
            else
            {
                message[i] += key - letterCount;
            }       
        }
    }
    std::string str{message};
    decodedText << str + "\n";
}   
#endif