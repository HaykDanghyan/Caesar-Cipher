#include "Caesar.h"

int main()
{
again:    display();
    std::string choose{};
    do
    {
        std::cout << "Do you want to continue encrypting/decrypting the text? (yes/no) : ";
        std::cin >> choose;
    } 
    while (choose != "yes" && choose != "no");
    if(choose == "yes")
    {
        goto again;
    }
    else
    {
        std::cout << "You closed the app ... !\n" << std::endl;
        exit(0);
    }
}