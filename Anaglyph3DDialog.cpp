#include <QFileDialog>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include "Anaglyph3DDialog.h"
#include "ui_Anaglyph3DDialog.h"

Anaglyph3DDialog::Anaglyph3DDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Anaglyph3DDialog)
{
    ui->setupUi(this);
    connect(ui->pushButtonLeftImage, SIGNAL(clicked(bool)), this, SLOT(onPushButtonLeftBrowse()));
    connect(ui->pushButtonRightImage, SIGNAL(clicked(bool)), this, SLOT(onPushButtonRightBrowse()));
    connect(ui->pushButtonGenerate, SIGNAL(clicked(bool)), this, SLOT(onPushButtonGenerate()));
}

Anaglyph3DDialog::~Anaglyph3DDialog()
{
    delete ui;
}

void Anaglyph3DDialog::browseLineEdit(QLineEdit *lineEdit)
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpeg *.jpg *.bmp)"));
    if(fileName.isEmpty())
    {
        return;
    }
    lineEdit->setText(fileName);
}

void Anaglyph3DDialog::onPushButtonLeftBrowse()
{
    browseLineEdit(ui->lineEditLeftImage);
}

void Anaglyph3DDialog::onPushButtonRightBrowse()
{
    browseLineEdit(ui->lineEditRightImage);
}

void Anaglyph3DDialog::onPushButtonGenerate()
{
    QImage imageLeft, imageRight;
    if(!imageLeft.load(ui->lineEditLeftImage->text()))
    {
        qDebug() << ui->lineEditLeftImage->text();
        QMessageBox::warning(this, "Failed to load left image!", "Failed to load left image!");
        return;
    }
    if(!imageRight.load(ui->lineEditRightImage->text()))
    {
        QMessageBox::warning(this, "Failed to load right image!", "Failed to load right image!");
        return;
    }
    if(imageLeft.size() != imageRight.size())
    {
        QMessageBox::warning(this, "Image size not equal!", "Image size not equal!");
        return;
    }
    int offset = ui->lineEditOffset->text().toInt();
    image = new QImage(imageLeft.width() + offset, imageLeft.height(), QImage::Format_ARGB32);
    image->fill(Qt::black);
    for(int i = 0; i < imageLeft.width(); i++)
    {
        for(int j = 0; j < imageLeft.height(); j++)
        {
            QColor color = imageLeft.pixelColor(i, j);
            int v  = (color.red() + color.green() + color.blue()) / 3;
            image->setPixelColor(i, j, QColor(v, 0, 0));
        }
    }
    for(int i = 0; i < imageRight.width(); i++)
    {
        for(int j = 0; j < imageRight.height(); j++)
        {
            QColor color = imageRight.pixelColor(i, j);
            int v  = (color.red() + color.green() + color.blue()) / 3;
            QColor orig = image->pixelColor(i + offset, j);
            orig.setBlue(v);
            image->setPixelColor(i + offset, j, orig);
        }
    }
    image->save("result.bmp");
    QMessageBox::information(this, "Saved to result.bmp", "Saved to result.bmp!");
}

