#ifndef BASE_H
#define BASE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Base; }
QT_END_NAMESPACE

class Base : public QMainWindow
{
    Q_OBJECT

public:
    Base(QWidget *parent = nullptr);
    ~Base();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:

    QString Brainfuck2Text(QString);
    QString Text2Brainfuck(QString);
    void CheckSign(QChar);
    void PrintBF(int);
    void BFSign(int);

    char array[30000] = {0};
    char *p = array;

    void Plus();
    void Minus();
    void OAngleBracket();
    void CAngleBracket();
    void Dot();
    void Comma();
    void OSquareBracket(QString &);

    QString BF;
    QString Text;


    Ui::Base *ui;
};
#endif // BASE_H
