#ifndef ANAGLYPH3DDIALOG_H
#define ANAGLYPH3DDIALOG_H

#include <QDialog>

class QLineEdit;
class QImage;

namespace Ui {
class Anaglyph3DDialog;
}

class Anaglyph3DDialog : public QDialog
{
    Q_OBJECT

public:
    explicit Anaglyph3DDialog(QWidget *parent = 0);
    ~Anaglyph3DDialog();

protected:
    QImage *image = nullptr;
    void browseLineEdit(QLineEdit *lineEdit);

private:
    Ui::Anaglyph3DDialog *ui;

public slots:
    void onPushButtonLeftBrowse();
    void onPushButtonRightBrowse();
    void onPushButtonGenerate();
};

#endif // ANAGLYPH3DDIALOG_H
