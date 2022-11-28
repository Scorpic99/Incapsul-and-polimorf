#include <iostream>
#include <fstream>
#include <sstream>

class Address {
public:


    std::string get_output_address(std::string city, std::string address, int home, int flat) {
        std::stringstream sstm;
        sstm << city << ", " << address << ", " << home << ", " << flat;
        return sstm.str();
        //return city + ", " + address + ", " + static_cast<std::string>(home) + ", " + flat;
    }
    Address(std::string city, std::string address, int home, int flat) {
        this->m_city = city;
        this->m_address = address;
        this->m_home = home;
        this->m_flat = flat;
    }
private:
    std::string m_city = "неизвестно";
    std::string m_address = "неизвестно";
    int m_home = 0;
    int m_flat = 0;
};

int main()
{
    setlocale(LC_ALL, "Rus");
    //создание файла in.txt
    std::ofstream inFileStack("in.txt");
    inFileStack << 5 << std::endl << "Москва" << std::endl << "Строителей" << std::endl << "32" << std::endl << "12" << std::endl;
    inFileStack << "Новокузнецк" << std::endl << "Науки" << std::endl << "5" << std::endl << "16" << std::endl;
    inFileStack << "Омск" << std::endl << "Пушкина" << std::endl << "2" << std::endl << "13" << std::endl;
    inFileStack << "Москва" << std::endl << "Арбат" << std::endl << "4" << std::endl << "1" << std::endl;
    inFileStack << "Новосибирск" << std::endl << "Мира" << std::endl << "85" << std::endl << "64" << std::endl;
    inFileStack.close();

    
    std::ifstream inFile("in.txt");
    std::ofstream outFile("uot.txt");
    std::string city, street, address;
    int size = 0, home = 0, flat = 0;
    inFile >> size;
    outFile << size << std::endl;
    Address classAddress(city, street, home, flat);
    for (int i = 0; i < size; i++) {
        inFile >> city;
        inFile >> street;
        inFile >> home;
        inFile >> flat;
        address = classAddress.get_output_address(city, street, home, flat);
        std::cout << address << std::endl;
        outFile << address << std::endl;
    }
    outFile.close();
    inFile.close();
    return 0;
}

