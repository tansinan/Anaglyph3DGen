#include "Anaglyph3DDialog.h"
#include "ui_Anaglyph3DDialog.h"

Anaglyph3DDialog::Anaglyph3DDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Anaglyph3DDialog)
{
    ui->setupUi(this);
}

Anaglyph3DDialog::~Anaglyph3DDialog()
{
    delete ui;
}
