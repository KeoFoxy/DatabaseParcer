#ifndef CSVREADER_H
#define CSVREADER_H

#include <vector>

#include <QString>

#include <abstractreader.h>

class CSVReader : public AbstractReader {
public:
    CSVReader(const QString &fileName);
    ~CSVReader() { fin.close(); }

    bool is_open() override { return fin.is_open(); }

    std::vector<Films> readAll() override;
    std::vector<std::string> split_line(const std::string &str, char devider);

private:
    std::ifstream fin;
};

#endif // CSVREADER_H
