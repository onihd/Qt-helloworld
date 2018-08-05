#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <QChar>
#include <QHash>

char findFirstRecurringChar(const char *input, long length)
{
    QHash<QChar, int> hash;

    char ret = '\0';
    char temp = '\0';

    for(int i = 0; i < length-1; i++)
    {
        if(hash.find(input[i]) == hash.end())
        {
            hash[input[i]] = 1;
        }
        else
        {
            return input[i];
        }
//        temp = input[i];

//        for(int j = i+1; j < length; j++)
//        {
//            if(temp == input[j])
//            {
//                ret = temp;
//                return ret;
//            }
//        }
    }
    return '\0';
}

void findTheLongestString(const QString &input, QPair<QChar, int> &pair)
{
    QTextStream out(stdout);
    out << input<<endl;

    pair.first = 'A';
    pair.second = 10;

    QChar lastMaxChar = input[0];
    QChar curChar = input[0];
    int maxLen = 1;
    int lastMaxLen = 1;

    for(int i = 1; i < input.length(); i++)
    {
        if(curChar == input[i])
        {
            maxLen++;
        }
        else
        {
            if(maxLen > lastMaxLen)
            {
                lastMaxLen = maxLen;
                lastMaxChar = curChar;
            }
            maxLen = 1;
            curChar = input[i];
        }
    }

    pair.first = lastMaxChar;
    pair.second = lastMaxLen;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"hello world!"<<endl;
    QTextStream out(stdout);
    out << "hello world!"<<endl;

    out<<findFirstRecurringChar("ABCBAB", 6)<<endl;

    QString input = "AABBBCCCCDEEEEEFFF";
    QPair<QChar, int> pair;
    findTheLongestString(input, pair);

    out <<pair.first<<"-"<<pair.second<<endl;

    return a.exec();
}
