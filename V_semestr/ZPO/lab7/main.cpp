#include "mainwindow.h"

#include <QApplication>
#include <QSet>
#include <QString>

#include <iostream>
#include <cctype>  // std::tolower



bool isPangram(const QString& text)
{
    QSet<char> uniqueLetters;
    for(const QChar &ch : text)
    {
        if(std::tolower(ch.toLatin1()) >= 97 &&  std::tolower(ch.toLatin1()) <= 122)
        {
            uniqueLetters.insert(std::tolower(ch.toLatin1()));
        }
    }
    return uniqueLetters.size() == 26;
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString test1 = "The quick brown fox jumps over the lazy dog";
    QString test2 = "Hello World!";

    if (isPangram(test1))
    {
        std::cout << "\"" << test1.toStdString() << "\" jest pangramem." << std::endl;
    }
    else
    {
        std::cout << "\"" << test1.toStdString() << "\" nie jest pangramem." << std::endl;
    }

    if (isPangram(test2))
    {
        std::cout << "\"" << test2.toStdString() << "\" jest pangramem." << std::endl;
    }
    else
    {
        std::cout << "\"" << test2.toStdString() << "\" nie jest pangramem." << std::endl;
    }

    return a.exec();
}
