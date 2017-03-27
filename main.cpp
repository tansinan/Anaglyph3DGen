#include "Anaglyph3DDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Anaglyph3DDialog w;
    w.show();

    return a.exec();
}
