#include "base.h"
#include "ui_base.h"

Base::Base(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Base)
{
    ui->setupUi(this);
    ui->bf->setFocus();
}

Base::~Base()
{
    delete ui;
}


void Base::on_pushButton_clicked()
{
    ui->bf->setText(Text2Brainfuck(ui->text->toPlainText()));
}

void Base::on_pushButton_2_clicked()
{
    ui->text->setText(Brainfuck2Text(ui->bf->toPlainText()));
}
//#################     TEXT TO BRAINFUCK       #################
QString Base::Text2Brainfuck(QString text)
{
    Text = text;

    for (int i = 0; i < text.length(); i++) {
        qDebug()<<(int)text[i].unicode();
        PrintBF((int)text[i].unicode());
        BFSign((int)text[i].unicode());
    }

    return text;
}

void Base::PrintBF(int)
{


}

void Base::BFSign(int sign)
{




}


//#################      CHECK SIGN     #########################
void Base::CheckSign(QChar sign)
{
    if(sign == '+') Plus();
    else if(sign == '-') Minus();
    else if(sign == '<') OAngleBracket();
    else if(sign == '>') CAngleBracket();
    else if(sign == '.') Dot();
    else if(sign == ',') Comma();
}


//#################     BRAINFUCK TO TEXT    #####################
QString Base::Brainfuck2Text(QString brainfuck)
{
    int size = brainfuck.length();

    BF = brainfuck;

    for(int i = 0; i < size; i++) {
        if(brainfuck[i] != '[') CheckSign(brainfuck[i]);

        else {

            QString loop = "";
                i++;
            while(brainfuck[i] != ']') {
                loop += brainfuck[i];
                i++;
            }
            OSquareBracket(loop);
        }

    }



    return Text;
}



//###################   CHARACTER RECOGNITION    ###################
void Base::Plus()
{
    ++(*p);
}

void Base::Minus()
{
    --(*p);
}

void Base::OAngleBracket()
{
    --p;
}

void Base::CAngleBracket()
{
    ++p;
}

void Base::Dot()
{
     qDebug() << QString(QChar::fromLatin1(*p));
     Text += *p;
}

void Base::Comma()
{

}

void Base::OSquareBracket(QString &loop)
{

    while(*p != 0){
        for(int i = 0; i < loop.length(); i++){
            CheckSign(loop[i]);
        }
    }

}



