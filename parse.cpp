#include "parse.h"

Parse::Parse()
{

}

void Parse::writingWeights()
{
    QFile file ("pisun.txt");
   if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
       return;


    QTextStream out(&file);
    out << "The magic number is: " << 49 << "\n";

    file.close();
}
