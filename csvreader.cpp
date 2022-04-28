#include "csvreader.h"

CSVReader::CSVReader(const QString& filename)
{
   fin.open(filename.toLatin1().data());
}


std::vector<std::string> CSVReader::split_line(const std::string &str, char delim)
{
    std::vector<std::string> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            tokens.push_back(str.substr(start, (str.find(delim, start) - start)));
            end = str.find(delim, start);
            start = end + 1;
    } while (end != std::string::npos);
}

    return tokens;
}


std::vector<Vehicle> CSVReader::readAll()
{
    std::vector<Vehicle> result;
    try
    {
            while(!fin.eof())
            {
                std::string line;
                std::getline(fin, line);

                std::vector<std::string> v = split_line(line, ';');

                Vehicle temp;
                temp.ID = std::stoi(v[0]);
                temp.brand_and_model = QString::fromStdString(v[1]);
                temp.color = static_cast<Color>(stoi(v[2]));
                temp.year = stoi(v[3]);

                lineNum++;

                result.push_back(temp);
            }

    return result;
    }
    catch(std::logic_error &error)
    {
        throw CSVException("Error", lineNum);
    }
}


CSVReader::~CSVReader()
{
    fin.close();
}
