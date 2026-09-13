#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

std::string getFilePath()
{
    std::string filePath;
    printf(" \n Note: If you want to exit, please enter 'X'.\n");
    std::cin >> filePath;
    return filePath;
}
void copyFile(long long originalSize, const std::string &filePath, const std::string &newFilePath)
{
    std::filesystem::path sourcePath(filePath);
    auto target = newFilePath / sourcePath.filename();
    try
    {
        std::filesystem::create_directories(newFilePath);
        std::filesystem::copy_file(filePath, target, std::filesystem::copy_options::overwrite_existing);
        std::cout << "File copied successfully.\n";
        std::ifstream newfile(target, std::ios::binary);
        printf("Original File size: %lld bytes\n\n", originalSize);
        newfile.seekg(0, std::ios::end);
        long long copiedFileSize = newfile.tellg();
        printf("Copied File size: %lld bytes\n\n", copiedFileSize);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error copying file: " << e.what() << std::endl;
    }
}
void run()
{
    while (true)
    {

        std::string filePath;
        std::string newFilePath;
        printf("Please enter the file path: ");
        filePath = getFilePath();
        if (filePath == "X")
        {
            printf("Exiting the program.\n");
            break;
        }
        std::filesystem::path sourcePath(filePath);
        std::ifstream file(filePath, std::ios::binary);
        if (!file.is_open())
        {
            printf("Failed to open the file.\n");
        }
        else
        {
            printf("File opened successfully.\n");
            file.seekg(0, std::ios::end);
            long long originalSize = file.tellg();
            printf("File size: %lld bytes\n\n", originalSize);
            printf("file name : %s \n", sourcePath.filename().string().c_str());
            printf("Enter the new file path to save the file:");
            newFilePath = getFilePath();
            copyFile(originalSize, filePath, newFilePath);
        }

        std::cout << "========================================================\n";
    }
}
int main()
{
    run();
    return 0;
}