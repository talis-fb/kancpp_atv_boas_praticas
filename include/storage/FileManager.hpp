// crie uma classe generica para ler e escrever em arquivos .bin

#include <fstream>
#include <string>

using namespace std;

class FileManager
{
private:
    fstream fileManager;

public:
    FileManager(const string &filename)
    {
        fileManager.open("data/" + filename, ios::in | ios::out | ios::binary | ios::app);
    }

    ~FileManager()
    {
        fileManager.close();
    }

    template <typename T>
    void write(const T &data)
    {
        fileManager.write(reinterpret_cast<const char *>(&data), sizeof(T));
    }

    template <typename T>
    T *read()
    {
        T *data = new T;
        fileManager.read(reinterpret_cast<char *>(data), sizeof(T));
        return data;
    }

    bool isEOF()
    {
        return fileManager.eof();
    }

    bool isOpen()
    {
        return fileManager.is_open();
    }
};
