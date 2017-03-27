#ifndef ANAGLYPH3DDIALOG_H
#define ANAGLYPH3DDIALOG_H

#include <QDialog>

namespace Ui {
class Anaglyph3DDialog;
}

class Anaglyph3DDialog : public QDialog
{
    Q_OBJECT

public:
    explicit Anaglyph3DDialog(QWidget *parent = 0);
    ~Anaglyph3DDialog();

private:
    Ui::Anaglyph3DDialog *ui;
};

#endif // ANAGLYPH3DDIALOG_H
