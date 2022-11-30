#include <iostream>
#include <fstream>
#include <sstream>

void sorted(std::string* address, int size) {//функция сортировки
    std::string temp;
    for (int j = 0; j < size - 1; j++) {
        for (int i = 0; i < size - 1; i++) {
            if (address[i].compare(address[i + 1]) > 0) {//если allAddress[i] > allAddress[i + 1]
                temp = address[i];
                address[i] = address[i + 1];
                address[i + 1] = temp;
            }
        }
    }
}

class Address {
public:


    std::string get_output_address() {
        std::stringstream sstm;
        sstm << this->m_city << ", " << this->m_address << ", " << this->m_home << ", " << this->m_flat;
        return sstm.str();
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
    std::string city, street, address;
    int size = 0, home = 0, flat = 0;
    inFile >> size;
    Address classAddress(city, street, home, flat);
    std::string* allAddress = new std::string[size];
    std::ofstream outFile("uot.txt");
    outFile << size << std::endl;
    for (int i = 0; i < size; i++) {
        inFile >> city;
        inFile >> street;
        inFile >> home;
        inFile >> flat;
        classAddress = Address(city, street, home, flat);
        allAddress[i] = classAddress.get_output_address();
    }
    inFile.close();

    //сортировка
    sorted(allAddress, size);

    //return massive
    for (int i = 0; i < size; i++) {
        std::cout << allAddress[i] << std::endl;
    }
    for (int i = 0; i < size; i++) {
        outFile << allAddress[i] << std::endl;
    }

    delete[] allAddress;
    outFile.close();
    return 0;
}
