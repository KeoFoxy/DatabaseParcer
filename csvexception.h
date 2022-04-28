#ifndef CSVEXCEPTION_H
#define CSVEXCEPTION_H

#include <QString>

class CSVException: public std::exception
{
private:
    QString _error;
    int _lineNum;

public:
    CSVException(const QString &error, int lineNum):std::exception(), _error(error), _lineNum(lineNum){};

    virtual const char* what() const noexcept override
    {
        return (char*)_error.toLocal8Bit().data();
    }

    int getLineNum() const
    {
        return _lineNum;
    }

    void setLineNum(int lineNum)
    {
        _lineNum = lineNum;
    }
};

#endif // CSVEXCEPTION_H
