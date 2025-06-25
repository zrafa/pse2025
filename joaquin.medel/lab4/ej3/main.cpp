#include "transmitter.hpp"
#include <iostream>
#include <fstream>

void recv()
{
    transmitter tr;
    std::cout << "Receiving...\n";

    std::size_t size = tr.recv();
    std::string file_name(size, '\0');
    for(char &c : file_name)
        c = tr.recv();
        
    std::ofstream file(file_name);

    char c;
    while((c = tr.recv()) != 0x17) {
        file.write(&c, 1);
    } /* Mientras no EoT */
        

    file.close();
    std::cout << "File " << file_name << " received!\n";
}

void send(const std::string& file_name)
{
    std::ifstream file(file_name);

    if(not file.is_open())
    {
        std::cerr << "File " << file_name << " not found.\n";
        std::terminate();
    }

    transmitter tr;
    std::cout << "Sending...\n";

    /*Enviar nombre del archivo*/
    tr.send(static_cast<uint8_t>(file_name.size()));
    for(char c : file_name)
        tr.send(c);

    /*Enviar data*/
    char c;
    while(file.get(c))
    {
        tr.send(c);
    }

    tr.send(0x17); /*EoT*/
    file.close();
    std::cout << "Send complete!\n";
}

int main(int argc, char** argv)
{
    if(argc < 2)
        recv();
    else
        send(argv[1]);

    return 0;
}