#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum class Filename
{
    BOARD,  /**< Board file */
    COLUMN, /**< Column file */
    TASK,   /**< Task file */
    USER    /**< User file */
};

/**
 * @brief Class for file management operations.
 */
class FileManager
{
private:
    fstream fileManager; /**< File stream for reading and writing. */

public:
    /**
     * @brief Constructs a FileManager object with the specified filename.
     *
     * @param filename The filename to be opened.
     * @param mode The file open mode (default: read and write in binary mode with append).
     *
     * @throw std::invalid_argument If the filename is invalid.
     */
    FileManager(Filename filename, ios_base::openmode mode = ios::in | ios::out | ios::binary | ios::app);

    /**
     * @brief Destroys the FileManager object and closes the file stream.
     */
    ~FileManager();

    /**
     * @brief Writes data to the file.
     *
     * @tparam T The type of data to be written.
     * @param args The data to be written.
     * @return True if the write operation was successful, false otherwise.
     */
    template <typename... T>
    bool write(T &...args);

    /**
     * @brief Reads data from the file.
     *
     * @tparam T The type of data to be read.
     * @return A vector containing the read data.
     *
     * @throw std::runtime_error If the file is not found.
     */
    template <typename T>
    std::vector<T> read();

    /**
     * @brief Checks if the file stream is ready for operations.
     *
     * @return True if the file stream is open, false otherwise.
     */
    bool isReady();
};

/**
 * @brief Constructs a FileManager object with the specified filename.
 *
 * @param filename The filename to be opened.
 * @param mode The file open mode.
 *
 * @throw std::invalid_argument If the filename is invalid.
 */
FileManager::FileManager(Filename filename, ios_base::openmode mode)
{
    string selectedFilename;

    switch (filename)
    {
    case Filename::BOARD:
        selectedFilename = "data/board.bin";
        break;
    case Filename::COLUMN:
        selectedFilename = "data/column.bin";
        break;
    case Filename::TASK:
        selectedFilename = "data/task.bin";
        break;
    case Filename::USER:
        selectedFilename = "data/user.bin";
        break;
    default:
        throw std::invalid_argument("Invalid filename.");
    }

    fileManager.open(selectedFilename, mode);
}

/**
 * @brief Destroys the FileManager object and closes the file stream.
 */
FileManager::~FileManager()
{
    fileManager.close();
}

/**
 * @brief Writes data to the file.
 *
 * @tparam T The type of data to be written.
 * @param args The data to be written.
 * @return True if the write operation was successful, false otherwise.
 */
template <typename... T>
bool FileManager::write(T &...args)
{
    if (!isReady())
    {
        return false;
    }

    try
    {
        (fileManager.write(reinterpret_cast<const char *>(&args), sizeof(args)), ...);
    }
    catch (const std::exception &e)
    {
        throw e;
    }

    return true;
}

/**
 * @brief Reads data from the file.
 *
 * @tparam T The type of data to be read.
 * @return A vector containing the read data.
 *
 * @throw std::runtime_error If the file is not found.
 */
template <typename T>
std::vector<T> FileManager::read()
{
    if (!isReady())
    {
        throw std::runtime_error("File not found.");
    }

    try
    {

        std::vector<T> datas;
        T data;

        while (fileManager.read(reinterpret_cast<char *>(&data), sizeof(T)))
        {
            datas.push_back(data);
        }

        return datas;
    }
    catch (const std::exception &e)
    {
        throw e;
    }
}

/**
 * @brief Checks if the file stream is ready for operations.
 *
 * @return True if the file stream is open, false otherwise.
 */
bool FileManager::isReady()
{
    return fileManager.is_open();
}
